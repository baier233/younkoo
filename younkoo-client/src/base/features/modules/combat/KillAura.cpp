﻿#include "KillAura.h"

#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <base/features/modules/ModuleManager.h>
#include <base/render/gui/input/InputApi.h>
#include <base/features/modules/common/CommonData.h>
#include <base/features/modules/player/Team.h>
#include <utils/Wstr.h>

#include <random>
#include <base/features/modules/visual/TargetHud.h>

static long lastClickTime = 0;
static int nextCps = 10;

static double distance(double x, double y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}

static double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
	return distance(y1 - y2, distance(x1 - x2, z1 - z2));
}
using namespace InputApi;

KillAura::KillAura() :AbstractModule(xorstr_("KillAura"), Category::COMBAT, xorstr_("Legit Aura."), 'R')
{

	this->addValue(FloatType, rangeValue);
	this->addValue(FloatType, leftMinCpsValue);
	this->addValue(FloatType, leftMaxCpsValue);
	this->addValue(FloatType, fovValue);
	this->addValue(FloatType, smoothValue);
	this->addValue(BoolType, keepSprintValue);
	this->addValue(BoolType, autoBlockValue);
	this->addValue(BoolType, canAttackCheckValue);
	this->addValue(BoolType, breakBlockCheckValue);

	this->addValue(ListType, killauraMode);
	this->addValue(ListType, targetPriorityListMode);
	REGISTER_EVENT(EventRender2D, KillAura::onRender2D);
}


KillAura& KillAura::getInstance()
{
	static KillAura instance = KillAura();
	return instance;
}

void KillAura::onEnable()
{
}
void KillAura::onDisable()
{
	TargetHud::getInstance().clear = true;
}

void KillAura::onRender2D(const EventRender2D& e)
{
	ToggleCheck;

	if (NanoGui::available) return;
}

#include <base/features/api/ClickApi.h>
#include <base/features/modules/player/AntiBot.h>
#include "Jamming.h"
#include <utils/TimerUtil.hpp>
using namespace ClickApi;


void KillAura::onUpdate()
{
	ToggleCheck;
	auto mc = Wrapper::Minecraft::getMinecraft();
	if (NanoGui::available || mc.isInGuiState()) return;
	if (breakBlockCheckValue->getValue() && Wrapper::Minecraft().getPlayerController().isHittingBlock()) return;

	auto fov = fovValue->getValue();
	auto smooth = smoothValue->getValue();
	auto thePlayer = mc.getPlayer();
	auto level = mc.getWorld();

	Math::Vector3D headPos = thePlayer.getPosition() + Math::Vector3D{ 0,thePlayer.getEyeHeight(),0 };
	Math::Rotation currentLookRot = thePlayer.getAngles();
	Math::Vector2 currentLookAngles = { .x = currentLookRot.yRot,.y = currentLookRot.xRot };

	float finalDist = FLT_MAX;
	float finalDiff = 370;
	float finalHealth = FLT_MAX;

	float realAimDistance = rangeValue->getValue();

	auto players = level.getPlayerList();
	Wrapper::EntityPlayer target{};

	for (auto& player : players)
	{
		if (player.isNULL()) continue;
		if (player.isEqualTo(thePlayer)) continue;


		if (player.getDisplayName().length() <= 0) return; 

		float playerHeight = player.getEyeHeight();

		Math::Vector2 difference = Math::vec_wrapAngleTo180(currentLookAngles.Invert() - Math::getAngles(headPos, player.getPosition() + Math::Vector3D(0, playerHeight, 0)).Invert());
		if (difference.x < 0) difference.x = -difference.x;
		if (difference.y < 0) difference.y = -difference.y;
		Math::Vector2 differenceFoot = Math::vec_wrapAngleTo180(currentLookAngles.Invert() - Math::getAngles(headPos, player.getPosition()).Invert());
		if (differenceFoot.x < 0) differenceFoot.x = -differenceFoot.x;
		if (differenceFoot.y < 0) differenceFoot.y = -differenceFoot.y;

		float angleYaw = currentLookAngles.x - difference.x;

		Math::Vector3D diff = thePlayer.getPosition() - player.getPosition();
		float dist = sqrt(pow(diff.x, 2) + pow(diff.y, 2) + pow(diff.z, 2));
		if ((abs(difference.x) <= fov) && dist <= realAimDistance)
		{
			if (player.isNULL() || Team::getInstance().isSameTeam(player))
			{
				continue;
			}
			if (Younkoo::get().info.major <= MajorVersion::MAJOR_112)
			{
				if (Antibot::getInstance().isBot(player))
				{
					continue;
				}
			}
			float health = player.getHealth();
			switch (this->targetPriorityListMode->getValue())
			{
			case Health:
				if (finalHealth > health)
				{
					target = player;
					finalHealth = health;
				}
				break;

			case Crosshair:
				if (finalDiff > difference.x)
				{
					target = player;
					finalDiff = difference.x;

				}
				break;
			default:
				if (finalDist > dist)
				{
					target = player;
					finalDist = (float)dist;

				}
			}


		}
	}

	if (target.isNULL()) {
		TargetHud::getInstance().clear = true;
		return;
	}
	else {
		TargetHud::getInstance().clear = false;
	}


	if (Team::getInstance().isSameTeam(target)) return;

	TargetHud::getInstance().renderTarget = target;
	if (canAttackCheckValue->getValue() && !thePlayer.canEntityBeSeen(target))
	{
		return;
	}
	float renderPartialTicks = CommonData::get().renderPartialTicks;
	static TimerUtil jammingTimer;
	if (Jamming::getInstance().getToggle() && Younkoo::get().info.major <= MajorVersion::MAJOR_112)
	{
		if (jammingTimer.hasTimeElapsed(500, true))
		{
			auto uuid = target.getUUID();
			if (uuid.empty()) return;
			Jamming::asyncJammingPlayer(uuid);
		}

	}



	if (this->killauraMode->getValue() == Legit) {

		Math::Vector3D ePos = target.getPosition();
		Math::Vector3D eRenderPos = target.getPosition(renderPartialTicks);

		float eHeight = target.getEyeHeight();
		Math::Vector3D eHeadPos = ePos + Math::Vector3D(0, eHeight, 0);
		Math::Vector3D eHeadRenderPos = eRenderPos + Math::Vector3D(0, eHeight, 0);


		Math::Vector2 anglesFoot = Math::getAngles(headPos, ePos);
		Math::Vector2 anglesHead = Math::getAngles(headPos, eHeadPos);

		Math::Vector2 difference = Math::vec_wrapAngleTo180(currentLookAngles.Invert() - anglesHead.Invert());
		Math::Vector2 differenceFoot = Math::vec_wrapAngleTo180(currentLookAngles.Invert() - anglesFoot.Invert());

		float offset = 0;

		float targetYaw = currentLookAngles.x + ((difference.x + offset) / smooth);

		Math::Vector3D renderPos = CommonData::get().renderPos;

		if (currentLookAngles.y > anglesFoot.y || currentLookAngles.y < anglesHead.y) {
			float targetPitchFoot = currentLookAngles.y + (differenceFoot.y / smooth);
			float targetPitchHead = currentLookAngles.y + (difference.y / smooth);

			float diffFoot = currentLookAngles.y - targetPitchFoot;
			float diffHead = currentLookAngles.y - targetPitchHead;
			diffFoot = diffFoot < 0 ? -diffFoot : diffFoot;
			diffHead = diffHead < 0 ? -diffHead : diffHead;

			float targetPitch;
			if (diffFoot > diffHead)
			{
				targetPitch = targetPitchHead;
			}
			else
			{
				targetPitch = targetPitchFoot;
			}
			thePlayer.setAngles(Math::Vector2(targetYaw, targetPitch));
		}
		else {
			thePlayer.setAngles(Math::Vector2(targetYaw, currentLookAngles.y + 0));
		}
	}

	/*if (keepSprintValue->getValue() && thePlayer.getMoveForward() != 0) {
		thePlayer.setSprint(true);
	}*/
	static auto& renderer = Renderer::get();
	long milli = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	if (lastClickTime == 0) lastClickTime = milli;
	if ((milli - lastClickTime) < (1000 / nextCps)) return;
	if (this->killauraMode->getValue() == Legit) {
		POINT pos_cursor;
		GetCursorPos(&pos_cursor);
		GenricMCClick(MouseType::LEFT, ClickType::DOWN);
		GenricMCClick(MouseType::LEFT, ClickType::UP);
	}
	//else if (this->killauraMode->getValue() == Normal) {
	//	//thePlayer.swingItem();
	//	//CommonData::getInstance()->isCombat = true;
	//	thePlayer.attackEntity(&thePlayer, target.getInstance());
	//}
	if (autoBlockValue->getValue() == true && this->killauraMode->getValue() == Legit) {
		POINT pos_cursor;
		GetCursorPos(&pos_cursor);
		LOG(target.getHealth());
		GenricMCClick(MouseType::RIGHT, ClickType::DOWN);
		GenricMCClick(MouseType::RIGHT, ClickType::UP);
		/*if (isMove())
			thePlayer.set_speed(0.155);*/
	}
	else if (autoBlockValue->getValue() == true && this->killauraMode->getValue() == Normal) {
		POINT pos_cursor;
		GetCursorPos(&pos_cursor);

		GenricMCClick(MouseType::RIGHT, ClickType::DOWN);

	}


	lastClickTime = milli;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(*this->leftMinCpsValue->getValuePtr(), *this->leftMaxCpsValue->getValuePtr());
	nextCps = distrib(gen);
}

	