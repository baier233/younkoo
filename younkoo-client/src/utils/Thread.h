#pragma once
#include <Windows.h>
namespace utils {
	namespace thread {
		inline bool hideThread(void* hThread) {
			typedef NTSTATUS(NTAPI* pNtSetInformationThread)
				(HANDLE, UINT, PVOID, ULONG);

			NTSTATUS Status;

			// Get NtSetInformationThread
			static pNtSetInformationThread NtSIT = (pNtSetInformationThread)
				GetProcAddress(GetModuleHandle(TEXT("ntdll.dll")),
					"NtSetInformationThread");
			// Shouldn't fail
			if (NtSIT == NULL)
				return false;

			// Set the thread info
			if (hThread == NULL)
				Status = NtSIT(GetCurrentThread(),
					0x11, //ThreadHideFromDebugger
					0, 0);
			else
				Status = NtSIT(hThread, 0x11, 0, 0);

			if (Status != 0x00000000)
				return false;
			else
				return true;
			return false;
		}
	}
}