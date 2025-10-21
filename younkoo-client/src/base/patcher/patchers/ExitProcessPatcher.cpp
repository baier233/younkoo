#include "ExitProcessPatcher.h"
#include <Windows.h>
#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")

#include <Psapi.h>

#include <StackWalk/StackWalker.h>

#include "utils/jvm_utility.h"

#include <iostream>

static bool __forceinline printStackTraceAndDetectNeteaseCrashes()
{
	auto result = false;
	HANDLE process = GetCurrentProcess();
	HANDLE thread = GetCurrentThread();
	CONTEXT context;
	STACKFRAME64 stackFrame;
	DWORD imageType;

	// Initialize context and stack frame
	RtlCaptureContext(&context);
	ZeroMemory(&stackFrame, sizeof(STACKFRAME64));

#ifdef _M_IX86
	imageType = IMAGE_FILE_MACHINE_I386;
	stackFrame.AddrPC.Offset = context.Eip;
	stackFrame.AddrPC.Mode = AddrModeFlat;
	stackFrame.AddrFrame.Offset = context.Ebp;
	stackFrame.AddrFrame.Mode = AddrModeFlat;
	stackFrame.AddrStack.Offset = context.Esp;
	stackFrame.AddrStack.Mode = AddrModeFlat;
#elif _M_X64
	imageType = IMAGE_FILE_MACHINE_AMD64;
	stackFrame.AddrPC.Offset = context.Rip;
	stackFrame.AddrPC.Mode = AddrModeFlat;
	stackFrame.AddrFrame.Offset = context.Rsp;
	stackFrame.AddrFrame.Mode = AddrModeFlat;
	stackFrame.AddrStack.Offset = context.Rsp;
	stackFrame.AddrStack.Mode = AddrModeFlat;
#elif _M_IA64
	imageType = IMAGE_FILE_MACHINE_IA64;
	stackFrame.AddrPC.Offset = context.StIIP;
	stackFrame.AddrPC.Mode = AddrModeFlat;
	stackFrame.AddrFrame.Offset = context.IntSp;
	stackFrame.AddrFrame.Mode = AddrModeFlat;
	stackFrame.AddrBStore.Offset = context.RsBSP;
	stackFrame.AddrBStore.Mode = AddrModeFlat;
	stackFrame.AddrStack.Offset = context.IntSp;
	stackFrame.AddrStack.Mode = AddrModeFlat;
#else
#error "Unsupported platform"
#endif

	// Initialize the symbol handler
	SymInitialize(process, NULL, TRUE);

	// Loop to walk the stack
	while (StackWalk64(imageType, process, thread, &stackFrame, &context, NULL,
		SymFunctionTableAccess64, SymGetModuleBase64, NULL))
	{
		DWORD64 address = stackFrame.AddrPC.Offset;
		if (address == 0)
		{
			break;
		}
		//GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,)
		// Print address
		HMODULE hModule = 0;
		if (GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCTSTR)address, &hModule)) {

			auto offset = (uintptr_t)address - (uintptr_t)hModule;
			char moduleName[MAX_PATH];
			K32GetModuleBaseNameA(GetCurrentProcess(), hModule, moduleName, sizeof(moduleName) / sizeof(char));
			auto module_name = std::string(moduleName);
			LOG("Address: " << module_name << " + 0x" << std::hex << offset << std::dec);


			if (!result)result = module_name.find("api-ms-w") != std::string::npos;

		}
		else {

			LOG("Address: " << (void*)address);
		}

		// Get symbol information
		DWORD64 displacementSym = 0;
		char buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];
		PSYMBOL_INFO symbol = (PSYMBOL_INFO)buffer;
		symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
		symbol->MaxNameLen = MAX_SYM_NAME;

		if (SymFromAddr(process, address, &displacementSym, symbol))
		{
			LOG("Function: " << symbol->Name);
		}

		// Get line information
		DWORD displacementLine = 0;
		IMAGEHLP_LINE64 line;
		line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);

		if (SymGetLineFromAddr64(process, address, &displacementLine, &line))
		{
			LOG("File: " << line.FileName << " Line: " << line.LineNumber);
		}
	}

	// Cleanup
	SymCleanup(process);
	return result;
}

class MyStackWalker : public StackWalker
{
public:
	MyStackWalker() : StackWalker() {}
protected:
	virtual void OnOutput(LPCSTR szText) {
		printf(szText); StackWalker::OnOutput(szText);
	}
	virtual void OnLoadModule(LPCSTR    img,
		LPCSTR    mod,
		DWORD64   baseAddr,
		DWORD     size,
		DWORD     result,
		LPCSTR    symType,
		LPCSTR    pdbName,
		ULONGLONG fileVersion) {
		return;
	}

};

static __forceinline void stack_walk() {
	MyStackWalker sw;

	sw.ShowCallstack(GetCurrentThread(), sw.GetCurrentExceptionContext());
}

#include <base/Younkoo.hpp>
#include "titan_hook.h"
static TitanHook<decltype(&ExitProcess)> ExitProcessHook;

static void My_ExitProcess(UINT code) {
	stack_walk();
	LOG("ExitProcess Code : " << code);	
	if (printStackTraceAndDetectNeteaseCrashes()) {
		MessageBox(0, L"On ExitProcess 1", 0, 0);
		while (!Younkoo::get().shouldShutDown.load())
		{
			Sleep(1);
		}
		return;
	}
	
	MessageBox(0, L"On ExitProcess 2", 0, 0);
	ExitProcessHook.GetOrignalFunc()(code);
}

void ExitProcessPatcher::patch(const PatcherManagerData& data)
{
	{
		auto pExitProcess = LI_FN(ExitProcess).get();
		ExitProcessHook.InitHook(pExitProcess, My_ExitProcess);
		ExitProcessHook.SetHook();
	}
}

void ExitProcessPatcher::clean(const PatcherManagerData& data)
{
	ExitProcessHook.RemoveHook();
}
