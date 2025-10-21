#include <iostream>
#include <vector>
#include "ModuleManager.h"

//Combat
#include "combat/AutoClicker.h"
#include "combat/TriggerBot.h"
#include "combat/AimAssist.h"
#include "combat/KillAura.h"
#include "combat/Jamming.h"
#include "combat/Velocity.h"
#include "combat/JumpReset.h"
#include "combat/KeepSprint.h"

//Visual
#include "visual/HUD.h"
#include "visual/ESP.h"
#include "visual/NameTag.h"
#include "visual/ItemESP.h"
#include "visual/BlockESP.h"
#include "visual/ChestESP.h"
#include "visual/TargetHud.h"
#include "visual/FullBright.h"
#include "visual/Chams.h"

//Player
#include "player/Eagle.h"
#include "player/Team.h"
#include "player/AutoTool.h"
#include "player/HitDelayFix.h"
#include "player/FastPlace.h"
#include "player/NoJumpDelay.h"
#include "player/Stealer.h"
#include "player/AntiBot.h"

//World
#include "world/CaveFinder.h"

//Movement
#include "movement/AutoSprint.h"
#include "movement/Blink.h"
ModuleManager::ModuleManager() {

}

void ModuleManager::getModule(Category c, std::vector<HMOD>* out_module) {
	out_module->clear();

	for (auto iter = this->modules.cbegin(); iter < this->modules.cend(); iter++) {
		if (ToBaseModule(*iter)->getCategory() == c) {
			out_module->push_back(*iter);
		}
	}
}

AbstractModule* ModuleManager::getModule(std::string name) {
	for (auto iter = this->modules.cbegin(); iter < this->modules.cend(); iter++) {
		if (strcmp(ToBaseModule(*iter)->getName().c_str(), name.c_str()) == 0) {
			return ToBaseModule(*iter);
		}
	}
	LOG("Module not found!!!");
	return nullptr;
}

void ModuleManager::getModule(bool isenable, std::vector<HMOD>* out_module) {
	out_module->clear();
	for (auto iter = this->modules.cbegin(); iter < this->modules.cend(); iter++) {
		if (ToBaseModule(*iter)->getToggle() == isenable) {
			out_module->push_back(*iter);
		}
	}
}

void ModuleManager::ProcessKeyEvent(int key) {
	for (auto iter = this->modules.cbegin(); iter < this->modules.cend(); iter++) {
		ToBaseModule(*iter)->onKeyEvent(key);

	}
}

void ModuleManager::ProcessUpdate() {

	for (auto iter = this->modules.cbegin(); iter < this->modules.cend(); iter++) {

		if (ToBaseModule(*iter)->getToggle()) {
			(void)JNI::get_env()->PushLocalFrame(99);
			ToBaseModule(*iter)->onUpdate();
			(void)JNI::get_env()->PopLocalFrame(nullptr);
		}

	}
}

std::vector<HMOD> ModuleManager::getMods()
{
	return this->modules;
}

bool ModuleManager::LoadModules()
{
	{/*Visual*/
		this->addModule<HUD>(&HUD::getInstance());
		this->addModule<CaveFinder>(&CaveFinder::getInstance());
		this->addModule<FullBright>(&FullBright::getInstance());
		this->addModule<ESP>(&ESP::getInstance());
		if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1 || SRGParser::get().GetVersion() == Versions::FORGE_1_20_1)
		{
			this->addModule<TargetHud>(&TargetHud::getInstance());
			this->addModule<NameTag>(&NameTag::getInstance());
			this->addModule<ItemESP>(&ItemESP::getInstance());
		}
		else {
			this->addModule<ChestESP>(&ChestESP::getInstance());
			this->addModule<Chams>(&Chams::getInstance());
		}
		this->addModule <BlockESP >(&BlockESP::getInstance());
	}

	{/*Combat*/

		this->addModule<AutoClicker>(&AutoClicker::getInstance());
		this->addModule<KillAura>(&KillAura::getInstance());
		this->addModule<AimAssist>(&AimAssist::getInstance());
		this->addModule<Jamming>(&Jamming::getInstance());
		if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1 || SRGParser::get().GetVersion() == Versions::FORGE_1_20_1) {
			this->addModule<TriggerBot>(&TriggerBot::getInstance());
			this->addModule<KeepSprint>(&KeepSprint::getInstance());
		}
		this->addModule<Velocity>(&Velocity::getInstance());
		//this->addModule<JumpReset>(&JumpReset::getInstance());
	}

	{/*Player*/


		this->addModule<FastPlace>(&FastPlace::getInstance());
		this->addModule<HitDelayFix>(&HitDelayFix::getInstance());
		this->addModule<NoJumpDelay>(&NoJumpDelay::getInstance());
		this->addModule<Eagle>(&Eagle::getInstance());
		this->addModule<Team>(&Team::getInstance());
		this->addModule<Antibot>(&Antibot::getInstance());
		this->addModule<AutoTool>(&AutoTool::getInstance());
		if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1 || SRGParser::get().GetVersion() == Versions::FORGE_1_20_1) {
			this->addModule<Stealer>(&Stealer::getInstance());
		}
	}


	{/*Movement*/
		this->addModule<AutoSprint>(&AutoSprint::getInstance());
		//this->addModule<Blink>(&Blink::getInstance());

	}
	return true;
}


