#include "InputApi.h"
#include <base/Younkoo.hpp>
#include <iostream>
LRESULT InputApi::SendMessageNoEvent(_In_opt_ HWND hWnd,
	_In_ UINT Msg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam)
{
	if (Younkoo::get().info.major <= MajorVersion::MAJOR_112)
	{
		return SendMessageA(hWnd, Msg, wParam, lParam);
	}
	return CallWindowProcW(WndProcHook::GL_HANDLE, hWnd, Msg, wParam, lParam);
}
