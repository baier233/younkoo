#include "VEHAntiCrcPatcher.h"
#include <Windows.h>
#include <stdio.h>
#include <cstdint>
#include <iostream>
namespace AntiCRC {
	static PVOID anti_crc_handle;
	static PVOID GuardAddress;
	static DWORD o_protect;




}

static LONG NTAPI anti_crc_exception(
	struct _EXCEPTION_POINTERS* ExceptionInfo
)
{

	if (ExceptionInfo->ExceptionRecord->ExceptionCode == STATUS_GUARD_PAGE_VIOLATION) // 捕获 PAGE_GUARD 违规
	{
		//printf("[+] 异常进入\n");
		//printf("[+] Rip::%zX\n", ExceptionInfo->ContextRecord->Rip);
		//printf("[+] TID::%d\n", GetCurrentThreadId());

		// 获取当前进程的模块信息
		HMODULE hModule = NULL;
		char moduleName[MAX_PATH] = {};
		if (GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPWSTR)ExceptionInfo->ContextRecord->Rip, &hModule)) {
			if (GetModuleFileNameA(hModule, moduleName, sizeof(moduleName))) {
				if (strstr(moduleName, "api-ms-win") != NULL) {
					ExceptionInfo->ContextRecord->Rcx = 999999999999;
					ExceptionInfo->ContextRecord->Rip = (uint64_t)Sleep;
					RemoveVectoredExceptionHandler(AntiCRC::anti_crc_handle);
					//MessageBoxA(0, moduleName, 0, 0);
					return EXCEPTION_CONTINUE_EXECUTION;
				}
			}
			else {

			}
		}
		else {


		}
		ExceptionInfo->ContextRecord->EFlags |= 0x100;
		return EXCEPTION_CONTINUE_EXECUTION;
	}

	if (ExceptionInfo->ExceptionRecord->ExceptionCode == STATUS_SINGLE_STEP) // 捕获 STATUS_SINGLE_STEP
	{
		DWORD dwOld;
		VirtualProtect((LPVOID)AntiCRC::GuardAddress, 0x1024, PAGE_EXECUTE_READ | PAGE_GUARD, &dwOld); // 重新应用 PAGE_GUARD 标志

		return EXCEPTION_CONTINUE_EXECUTION;
	}

	return EXCEPTION_CONTINUE_SEARCH;
}
static bool SetGuardRegion(const char* ModuleName)
{
	uint64_t hModule = (uint64_t)GetModuleHandleA(ModuleName);

	if (hModule == NULL) {
		return false;
	}

	IMAGE_DOS_HEADER* pDosHeader = (IMAGE_DOS_HEADER*)hModule;
	IMAGE_NT_HEADERS* pNtHeader = (IMAGE_NT_HEADERS*)(hModule + pDosHeader->e_lfanew);
	IMAGE_FILE_HEADER* pFileHeader = &pNtHeader->FileHeader;

	IMAGE_SECTION_HEADER* pSectionHeader = IMAGE_FIRST_SECTION(pNtHeader);
	for (uint32_t i = 0; i != pFileHeader->NumberOfSections; ++i, ++pSectionHeader)
	{
		if (strcmp((const char*)&pSectionHeader->Name, ".text") == 0)
		{
			AntiCRC::GuardAddress = (LPVOID)(hModule + pSectionHeader->VirtualAddress);

			VirtualProtect(AntiCRC::GuardAddress, 0x1024, PAGE_EXECUTE_READ | PAGE_GUARD, &AntiCRC::o_protect);
			return true;
		}
	}

	return false;
}

static bool RemoveGuardRegion(const char* ModuleName)
{
	uint64_t hModule = (uint64_t)GetModuleHandleA(ModuleName);

	if (hModule == NULL) {
		return false;
	}

	IMAGE_DOS_HEADER* pDosHeader = (IMAGE_DOS_HEADER*)hModule;
	IMAGE_NT_HEADERS* pNtHeader = (IMAGE_NT_HEADERS*)(hModule + pDosHeader->e_lfanew);
	IMAGE_FILE_HEADER* pFileHeader = &pNtHeader->FileHeader;

	IMAGE_SECTION_HEADER* pSectionHeader = IMAGE_FIRST_SECTION(pNtHeader);
	for (uint32_t i = 0; i != pFileHeader->NumberOfSections; ++i, ++pSectionHeader)
	{
		if (strcmp((const char*)&pSectionHeader->Name, ".text") == 0)
		{
			DWORD oProtect;
			LPVOID GuardAddress = (LPVOID)(hModule + pSectionHeader->VirtualAddress);

			VirtualProtect(GuardAddress, 0x1024, AntiCRC::o_protect, &oProtect);
			return true;
		}
	}

	return false;
}

void VEHAntiCrcPatcher::patch(const PatcherManagerData& data)
{
	AntiCRC::anti_crc_handle = AddVectoredExceptionHandler(0, anti_crc_exception);
	SetGuardRegion("jvm.dll");
}

void VEHAntiCrcPatcher::clean(const PatcherManagerData& data)
{
	RemoveGuardRegion("jvm.dll");
	RemoveVectoredExceptionHandler(AntiCRC::anti_crc_handle);
}
