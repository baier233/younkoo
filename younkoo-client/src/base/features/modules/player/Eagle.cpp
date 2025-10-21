#include "Eagle.h"

#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <base/features/modules/ModuleManager.h>

#include <base/features/modules/common/CommonData.h>




Eagle::Eagle() :AbstractModule(xorstr_("Eagle"), Category::PLAYER, xorstr_("Eagle."), 'G')
{
	this->addValue(BoolType, shiftPressedValue);
}


Eagle& Eagle::getInstance()
{
	static Eagle instance = Eagle();
	return instance;
}

void Eagle::onEnable()
{


}

void Eagle::onDisable()
{
	auto mc = Wrapper::Minecraft::getMinecraft();
	auto options = mc.getSettings();
	if (options.isNULL()) return;
	options.setShiftKeyPressed(false);
}


void Eagle::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;
	if (shiftPressedValue->getValue() && !(GetAsyncKeyState(VK_LSHIFT) & 0x8000)) return;
	auto mc = Wrapper::Minecraft::getMinecraft();
	auto player = mc.getPlayer();
	auto level = mc.getWorld();
	if (Younkoo::get().info.major == MajorVersion::MAJOR_189 or Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		auto pos = player.getPosition();
		auto options = mc.getSettings();
		if (options.isNULL()) return;
		options.setShiftKeyPressed(level.isAirBlock(pos - Math::Vector3D{ 0,0.1,0 }));
		return;
	}
	auto state = level.getBlockState(player.getPosition() - Math::Vector3D{ 0,0.1,0 });
	auto result = !state.isNULL() && state.isAir() && player.getMovementInput().getMoveForward() <= 0.0f;
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		auto options = mc.getSettings();
		if (options.isNULL()) return;
		options.setShiftKeyPressed(result);
	}
	else {
		player.setSneak(result);
	}
}

