#include "HideModulePatcher.h"
#include <windows.h>
#include <stdio.h>
//===========================================================================
typedef struct _UNICODE_STRING {
	USHORT Length;
	USHORT MaximumLength;
	PWCH   Buffer;
} UNICODE_STRING;
typedef UNICODE_STRING* PUNICODE_STRING;
//===========================================================================
typedef struct _PEB_LDR_DATA
{
	ULONG           Length;
	BOOLEAN         Initialized;
	PVOID           SsHandle;
	LIST_ENTRY      InLoadOrderModuleList;
	LIST_ENTRY      InMemoryOrderModuleList;
	LIST_ENTRY      InInitializationOrderModuleList;
} PEB_LDR_DATA, * PPEB_LDR_DATA;
//===========================================================================
typedef struct _PE_HEADER_INFO {
	BYTE* HeaderData;
	DWORD Size;
} PE_HEADER_INFO, * PPE_HEADER_INFO;


typedef struct _LDR_MODULE
{
	LIST_ENTRY      InLoadOrderModuleList;
	LIST_ENTRY      InMemoryOrderModuleList;
	LIST_ENTRY      InInitializationOrderModuleList;
	PVOID           BaseAddress;
	PVOID           EntryPoint;
	ULONG           SizeOfImage;
	UNICODE_STRING  FullDllName;
	UNICODE_STRING  BaseDllName;
	ULONG           Flags;
	SHORT           LoadCount;
	SHORT           TlsIndex;
	LIST_ENTRY      HashTableEntry;
	ULONG           TimeDateStamp;
} LDR_MODULE, * PLDR_MODULE;

typedef struct _MODULE_LIST_ENTRY {
	LIST_ENTRY InLoadOrderLinks;
	LIST_ENTRY InMemoryOrderLinks;
	LIST_ENTRY InInitializationOrderLinks;
	LIST_ENTRY HashTableEntryLinks;
} MODULE_LIST_ENTRY, * PMODULE_LIST_ENTRY;
#include <vector>
struct ListInfo
{
	PLIST_ENTRY blink;
	PLIST_ENTRY flink;
	PLIST_ENTRY preserved;
};
#include <array>
struct LdrInfo
{
	PLIST_ENTRY blink;
	PLIST_ENTRY flink;
	PLIST_ENTRY preserved;
};
struct RestoreData
{
	LdrInfo hash_table_info;
	std::array<ListInfo, 3> list_infos;
};
static RestoreData restore_data;
PE_HEADER_INFO g_PeHeaderInfo = { NULL, 0 };

static void UnlinkModule(void* Module)
{
	DWORD dwPEB = 0, dwOffset = 0;
	PLIST_ENTRY pUserModuleHead = NULL, pUserModule = NULL;
	PPEB_LDR_DATA pLdrData;
	PLDR_MODULE pLdrModule = NULL;
	void* ModuleBase = NULL;
	int i = 0, n = 0;
	BYTE* _teb = (BYTE*)__readgsqword(0x30);
	pLdrData = (PPEB_LDR_DATA)(PULONGLONG)(*(PULONGLONG)((*(PULONGLONG)(_teb + 0x60)) + 0x18));

	for (; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			pUserModuleHead = (PLIST_ENTRY)(&(pLdrData->InLoadOrderModuleList));
			pUserModule = (PLIST_ENTRY)(&(pLdrData->InLoadOrderModuleList));
			dwOffset = 0;
			break;

		case 1:
			pUserModuleHead = (PLIST_ENTRY)(&(pLdrData->InMemoryOrderModuleList));
			pUserModule = (PLIST_ENTRY)(&(pLdrData->InMemoryOrderModuleList));
			dwOffset = 16;
			break;
		case 2:
			pUserModuleHead = pUserModule = (PLIST_ENTRY)(&(pLdrData->InInitializationOrderModuleList));
			dwOffset = 32;
			break;
		}
		int index = 0;
		while (pUserModule->Flink != pUserModuleHead)
		{
			pUserModule = pUserModule->Flink;
			ModuleBase = *(void**)(((LONGLONG)(pUserModule)) + (48 - dwOffset));
			if (ModuleBase == Module)
			{
				restore_data.list_infos[i] = ListInfo{ };

				if (!pLdrModule)
					pLdrModule = (PLDR_MODULE)(((LONGLONG)(pUserModule)) - dwOffset);

				restore_data.list_infos[i].preserved = pUserModule;
				restore_data.list_infos[i].blink = pUserModule->Blink;
				restore_data.list_infos[i].flink = pUserModule->Flink;

				pUserModule->Blink->Flink = pUserModule->Flink;
				pUserModule->Flink->Blink = pUserModule->Blink;
			}
			index++;
		}
	}
	// Unlink from LdrpHashTable
	if (pLdrModule)
	{
		restore_data.hash_table_info.preserved = &pLdrModule->HashTableEntry;
		restore_data.hash_table_info.flink = pLdrModule->HashTableEntry.Flink;
		restore_data.hash_table_info.blink = pLdrModule->HashTableEntry.Blink;

		pLdrModule->HashTableEntry.Blink->Flink = pLdrModule->HashTableEntry.Flink;
		pLdrModule->HashTableEntry.Flink->Blink = pLdrModule->HashTableEntry.Blink;
	}
}

static void RelinkModule() {

	restore_data.hash_table_info.blink->Flink = restore_data.hash_table_info.preserved;
	restore_data.hash_table_info.flink->Blink = restore_data.hash_table_info.preserved;
	for (auto& info : restore_data.list_infos)
	{
		info.blink->Flink = info.preserved;
		info.flink->Blink = info.preserved;
	}
}

static void RemovePeHeader(HANDLE GetModuleBase) {
	PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)GetModuleBase;
	PIMAGE_NT_HEADERS pNTHeader = (PIMAGE_NT_HEADERS)((PBYTE)pDosHeader + (DWORD)pDosHeader->e_lfanew);

	if (pNTHeader->Signature != IMAGE_NT_SIGNATURE)
		return;

	if (pNTHeader->FileHeader.SizeOfOptionalHeader) {
		DWORD Protect;
		WORD Size = pNTHeader->FileHeader.SizeOfOptionalHeader;

		// 保存PE头部信息
		g_PeHeaderInfo.HeaderData = (BYTE*)malloc(Size);
		if (g_PeHeaderInfo.HeaderData == NULL) {
			return;
		}
		memcpy(g_PeHeaderInfo.HeaderData, (void*)GetModuleBase, Size);
		g_PeHeaderInfo.Size = Size;

		// 移除PE头部信息
		VirtualProtect((void*)GetModuleBase, Size, PAGE_EXECUTE_READWRITE, &Protect);
		RtlZeroMemory((void*)GetModuleBase, Size);
		VirtualProtect((void*)GetModuleBase, Size, Protect, &Protect);
	}
}

static void RestorePeHeader(HANDLE GetModuleBase) {
	if (g_PeHeaderInfo.HeaderData == NULL || g_PeHeaderInfo.Size == 0) {
		return;
	}

	DWORD Protect;
	VirtualProtect((void*)GetModuleBase, g_PeHeaderInfo.Size, PAGE_EXECUTE_READWRITE, &Protect);
	memcpy((void*)GetModuleBase, g_PeHeaderInfo.HeaderData, g_PeHeaderInfo.Size);
	VirtualProtect((void*)GetModuleBase, g_PeHeaderInfo.Size, Protect, &Protect);

	// 释放保存的头部数据
	free(g_PeHeaderInfo.HeaderData);
	g_PeHeaderInfo.HeaderData = NULL;
	g_PeHeaderInfo.Size = 0;
}

#include <Main.hpp>
void HideModulePatcher::patch(const PatcherManagerData& data)
{
#ifndef PUBLISH
	RemovePeHeader(Main::current_module);
	UnlinkModule(Main::current_module);
#endif // !PUBLISH
}

void HideModulePatcher::clean(const PatcherManagerData& data)
{
#ifndef PUBLISH
	RelinkModule();
	RestorePeHeader(Main::current_module);
#endif // !PUBLISH
}
