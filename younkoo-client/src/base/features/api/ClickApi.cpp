#include "ClickApi.h"
#include <Windows.h>
#include <base/render/gui/input/InputApi.h>
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <base/render/Renderer.hpp>
static HWND handleWindow = 0;
using namespace InputApi;
void ClickApi::Init()
{
	auto mc = Wrapper::Minecraft::getMinecraft();
	if (mc.isNULL()) return;
	auto settings = mc.getSettings();
	if (settings.isNULL()) return;
	if (Younkoo::get().info.major == MajorVersion::MAJOR_189 || Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		keyAttack = 0;
		keyUse = 1;
	}
	else {
		keyAttack = settings.getAttackKey();
		keyUse = settings.getUseKey();
	}

	handleWindow = Renderer::get().renderContext.HandleWindow;

}
struct LOCK
{
	inline LOCK() {
		WndProcHook::LOCK = true;
	}
	inline ~LOCK() {

		WndProcHook::LOCK = false;
	}
};
void ClickApi::GenricClick(MouseType mouse, ClickType click)
{
	static POINT pos_cursor;
	GetCursorPos(&pos_cursor);
	if (click == ClickType::BOTH)
	{
		LOCK{};
		SendMessageNoEvent(handleWindow, 0x200 + (int)mouse * 3 + 1, static_cast<WPARAM>((int)mouse) + 1, MAKELPARAM(pos_cursor.x, pos_cursor.y));
		SendMessageNoEvent(handleWindow, 0x201 + (int)mouse * 3 + 1, static_cast<WPARAM>((int)mouse) + 1, MAKELPARAM(pos_cursor.x, pos_cursor.y));
		return;
	}
	else {
		LOCK{};
		SendMessageNoEvent(handleWindow, 0x200 + (int)mouse * 3 + 1 + (int)click, static_cast<WPARAM>((int)mouse) + 1, MAKELPARAM(pos_cursor.x, pos_cursor.y));
	}
}


void ClickApi::GenricMCClick(MouseType mouse, ClickType click)
{

	static POINT pos_cursor;
	GetCursorPos(&pos_cursor);
	if ( true || Younkoo::get().info.major <= MajorVersion::MAJOR_112)
	{
		LOG("Hanlde Window :" << handleWindow);
		if (mouse == MouseType::LEFT)
		{
			if (click == ClickType::BOTH)
			{
				PostMessageA(handleWindow, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
				PostMessageA(handleWindow, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
			}
			else if (click == ClickType::DOWN) {

				PostMessageA(handleWindow, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
			}
			else {

				PostMessageA(handleWindow, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
			}
		}
		else {
			if (click == ClickType::BOTH)
			{
				PostMessageA(handleWindow, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
				PostMessageA(handleWindow, WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
			}
			else if (click == ClickType::DOWN) {

				PostMessageA(handleWindow, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));

			}
			else {

				PostMessageA(handleWindow, WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(pos_cursor.x, pos_cursor.y));
			}
		}
		return;
	}
	if (mouse == MouseType::LEFT)
	{
		if (click == ClickType::BOTH)
		{
			LOCK{};
			SendMessageNoEvent(handleWindow, 0x200 + (int)keyAttack * 3 + 1, static_cast<WPARAM>((int)keyAttack) + 1, MAKELPARAM(pos_cursor.x, pos_cursor.y));
			SendMessageNoEvent(handleWindow, 0x201 + (int)keyAttack * 3 + 1, static_cast<WPARAM>((int)keyAttack) + 1, MAKELPARAM(pos_cursor.x, pos_cursor.y));
			return;
		}
		else {
			LOCK{};
			SendMessageNoEvent(handleWindow, 0x200 + (int)keyAttack * 3 + 1 + (int)click, static_cast<WPARAM>((int)keyAttack) + 1, MAKELPARAM(pos_cursor.x, pos_cursor.y));
		}
	}
	else {
		if (click == ClickType::BOTH)
		{
			LOCK{};
			SendMessageNoEvent(handleWindow, 0x200 + (int)keyUse * 3 + 1, static_cast<WPARAM>((int)keyUse) + 1, MAKELPARAM(pos_cursor.x, pos_cursor.y));
			SendMessageNoEvent(handleWindow, 0x201 + (int)keyUse * 3 + 1, static_cast<WPARAM>((int)keyUse) + 1, MAKELPARAM(pos_cursor.x, pos_cursor.y));
			return;
		}
		else {
			LOCK{};
			SendMessageNoEvent(handleWindow, 0x200 + (int)keyUse * 3 + 1 + (int)click, static_cast<WPARAM>((int)keyUse) + 1, MAKELPARAM(pos_cursor.x, pos_cursor.y));
		}
	}

}