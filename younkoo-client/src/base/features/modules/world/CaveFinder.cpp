#include "CaveFinder.h"
#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <random>
#include <base/features/modules/player/Team.h>

#include <base/features/modules/ModuleManager.h>

#include <wrapper/net/minecraft/entity/player/EntityPlayer.h>

#include <utils/Wstr.h>
CaveFinder::CaveFinder() :AbstractModule(xorstr_("CaveFinder"), Category::WORLD, wstr::toString(L"注意 此模块不绕过obs!!"))
{
	this->setToggle(false);
}

CaveFinder& CaveFinder::getInstance()
{
	static CaveFinder instance = CaveFinder();
	return instance;
}

void CaveFinder::onEnable()
{
}

void CaveFinder::onDisable()
{

}
#include <hotspot/classes/instance_klass.h>

void CaveFinder::onUpdate()
{
}