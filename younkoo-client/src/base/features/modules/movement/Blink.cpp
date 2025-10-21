#include "Blink.h"
#include <WinSock2.h>
TitanHook<decltype(&WSASend)> WSASendHook;
#include <wrapper/net/minecraft/client/Minecraft.h>
int
WSAAPI
hk_WSASend(
	_In_ SOCKET s,
	_In_reads_(dwBufferCount) LPWSABUF lpBuffers,
	_In_ DWORD dwBufferCount,
	_Out_opt_ LPDWORD lpNumberOfBytesSent,
	_In_ DWORD dwFlags,
	_Inout_opt_ LPWSAOVERLAPPED lpOverlapped,
	_In_opt_ LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
) {
	while (Blink::getInstance().getToggle()) {
		Sleep(1);
	}
	return WSASendHook.GetOrignalFunc()(s, lpBuffers, dwBufferCount, lpNumberOfBytesSent, dwFlags, lpOverlapped, lpCompletionRoutine);
}

Blink& Blink::getInstance()
{
	static Blink instance = Blink();
	return instance;
}

void Blink::onEnable()
{
	WSASendHook.SetHook();
}

void Blink::onDisable()
{
	WSASendHook.RemoveHook();
}

void Blink::onUpdate()
{
	ToggleCheck;
}

Blink::Blink() : AbstractModule(xorstr_("Blink"), Category::MOVEMENT, xorstr_("Dangerous function"))
{
	WSASendHook.InitHook(WSASend, hk_WSASend);
}
