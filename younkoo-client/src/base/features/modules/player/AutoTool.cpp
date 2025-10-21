#include "AutoTool.h"

#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <base/features/modules/ModuleManager.h>
#include <base/features/modules/common/CommonData.h>


#include <wrapper/net/minecraft/client/Minecraft.h>
#include <wrapper/net/minecraft/util/BlockPos.h>
#include <wrapper/net/minecraft/item/ItemSword.h>

#include <wrapper/net/minecraft/block/state/IBlockState.h>



AutoTool::AutoTool() : AbstractModule(xorstr_("AutoTool"), Category::PLAYER, xorstr_("Auto Tool."))
{
}


AutoTool& AutoTool::getInstance()
{
	static AutoTool instance = AutoTool();
	return instance;
}

void AutoTool::onEnable()
{
}

void AutoTool::onDisable()
{

}
#include <base/features/api/ClickApi.h>

#include <hotspot/classes/instance_klass.h>
void AutoTool::onUpdate()
{
	ToggleCheck;
	auto mc = Wrapper::Minecraft::getMinecraft();
	if (NanoGui::available || mc.isInGuiState()) return;
	if (shiftPressedValue->getValue() && !(GetAsyncKeyState(VK_LSHIFT) & 0x8000)) return;
	auto player = mc.getPlayer();
	auto level = mc.getWorld();
	if (IsKeyBeingDown(ClickApi::keyAttack + 1)) {
		float bestSpeed = 1.f;
		int bestSlot = -1;
		Wrapper::MovingObjectPosition mouseover = mc.getMouseOver();
		if (mouseover.isNULL())
		{
			LOG("mouseover is null");
			return;
		}


		if (!mouseover.isTypeOfBlock()) return;

		Wrapper::BlockState blockstate{};
		Wrapper::IBlockState iblockstate{};
		Wrapper::Block block{};
		Wrapper::BlockPos blockpos = mouseover.getBlockPos();

		if (blockpos.isNULL())
		{
			return;
		}

		if (Younkoo::get().info.major < MajorVersion::MAJOR_112) {
			iblockstate = level.getIBlockState(blockpos);
			if (iblockstate.isNULL())
			{
				return;
			}
		}
		else
		{
			blockstate = level.getBlockState(blockpos);
			if (blockstate.isNULL())
			{
				return;
			}
		}


		if (Younkoo::get().info.major < MajorVersion::MAJOR_112) {

			block = iblockstate.getBlock();
			if (block.isNULL()) {
				return;
			}

		}





		auto inventory = player.getInventory();
		if (inventory.isNULL()) return;

		for (int i = 0; i <= 8; i++)
		{
			auto item = inventory.getStackInSlot(i);
			if (item.isNULL()) continue;

			float speed = 0.f;
			if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
				if (block.isNULL()) {
					LOG("block is null");
					continue;
				}
				speed = item.getStrVsBlock(block);
			}
			else {
				if (blockstate.isNULL())continue;
				speed = item.getStrVsBlock(blockstate);
			}

			if (speed > bestSpeed) {
				bestSpeed = speed;
				bestSlot = i;
			}
		}

		if (bestSlot == -1)
		{
			return;
		}

		if (bestSlot == inventory.getCurrentSlot())
		{
			return;
		}

		inventory.setCurrentItem(bestSlot);
	}

	return;

}

