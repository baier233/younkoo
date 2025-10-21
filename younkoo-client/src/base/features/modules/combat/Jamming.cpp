#include "Jamming.h"
#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <random>
#include <base/features/modules/player/Team.h>

#include <base/features/modules/ModuleManager.h>

#include <base/features/api/JammingApi.h>
#include <wrapper/net/minecraft/entity/player/EntityPlayer.h>
Jamming::Jamming() :AbstractModule(xorstr_("Jamming"), Category::COMBAT, xorstr_("Jamming."))
{
	this->setToggle(false);
	REGISTER_EVENT(EventAttack, Jamming::onAttack);
	JammingAPI::InitGameID();
}

Jamming& Jamming::getInstance()
{
	static Jamming instance = Jamming();
	return instance;
}
#include <thread>
#include <unordered_map>
#include <chrono>
#include <mutex>
static std::unordered_map<std::string, std::chrono::steady_clock::time_point> jammingTimes;
static std::mutex jammingTimesMutex;

void Jamming::asyncJammingPlayer(const std::string& player_uuid) {

	std::thread([player_uuid]() {

		auto now = std::chrono::steady_clock::now();
		std::lock_guard<std::mutex> lock(jammingTimesMutex);
		{

			auto it = jammingTimes.find(player_uuid);
			if (it != jammingTimes.end() && std::chrono::duration_cast<std::chrono::milliseconds>(now - it->second).count() < 1000)
			{
				return;
			}

			jammingTimes[player_uuid] = now;
		}

		auto playerInfo = JammingAPI::QueryUserInfoFromUUID(player_uuid);
		//LOG("playerinfo :" << playerInfo.has_value());
		if (!playerInfo.has_value()) return;
		if (JammingAPI::DoEat(playerInfo.value())) {
			LOG("Successfully Jamming Player: " << player_uuid << "!");
		}
		}).detach();
}

void Jamming::onAttack(const EventAttack& e)
{
	ToggleCheck;
	auto& entity = e.entity;
	if (e.entity.isNULL())return;
	static auto playerKlass = Wrapper::EntityPlayer::klass();
	if (!playerKlass) return;
	auto klass = entity.getClassBaseOnObject();
	if (!klass) return;
	if (!entity.instanceOf(playerKlass)) return;
	Wrapper::EntityPlayer player(*entity.instance.get());
	if (player.isNULL())return;
	if (Wrapper::Minecraft::getMinecraft().getPlayer().isSameTeam(player)) return;
	auto uuid = player.getUUID();
	if (uuid.empty()) return;
	JNI::get_env()->DeleteLocalRef(klass);
	asyncJammingPlayer(uuid);
}
static std::wstring o_title;
static std::wstring modify_title;
#include <base/render/Renderer.hpp>
#include <utils/Wstr.h>
void Jamming::onEnable()
{
	static auto& renderer = Renderer::get();
	if (modifyTitleValue->getValue())
	{
		static std::once_flag flag;
		std::call_once(flag, [] {
			static wchar_t windowTitle[256]{};
			auto len = GetWindowTextW(renderer.renderContext.HandleWindow, windowTitle, 256);
			o_title = std::wstring(windowTitle, len);
			LOG("Title :" << wstr::toString(o_title));
			modify_title = o_title + L"(绿玩罚站版)";
			});
	}

}

void Jamming::onDisable()
{
	static auto& renderer = Renderer::get();
	if (modifyTitleValue->getValue() && o_title.length() != 0)
	{
		SetWindowTextW(renderer.renderContext.HandleWindow, o_title.c_str());
	}
}
#include <hotspot/classes/instance_klass.h>

void Jamming::onUpdate()
{
	ToggleCheck;
	auto mc = Wrapper::Minecraft::getMinecraft();
	if (NanoGui::available || mc.isInGuiState()) return;

	if (modifyTitleValue->getValue() && o_title.length() != 0)
	{
		static auto& renderer = Renderer::get();
		SetWindowTextW(renderer.renderContext.HandleWindow, modify_title.c_str());
	}
}