#include "Team.h"

#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <base/features/modules/ModuleManager.h>

#include <base/features/modules/common/CommonData.h>

#include <wrapper/net/minecraft/item/ItemArmor.h>


Team::Team() :AbstractModule(xorstr_("Team"), Category::PLAYER, xorstr_("Team."))
{
}


Team& Team::getInstance()
{
	static Team instance = Team();
	return instance;
}

void Team::onEnable()
{
}

void Team::onDisable()
{

}


void Team::onUpdate()
{
}

bool Team::isSameTeam(Wrapper::EntityPlayer& other)
{
	if (!this->getToggle())return false;
	auto mc = Wrapper::Minecraft::getMinecraft();
	auto player = mc.getPlayer();
	if (SRGParser::get().GetVersion() >= Versions::FORGE_1_18_1)
	{
		return player.isSameTeam(other);
	}

	if (Younkoo::get().info.major == MajorVersion::MAJOR_189 or Younkoo::get().info.major == MajorVersion::MAJOR_112) {

		if (other.isNULL() || other.getInventory().isNULL()) {
			return false;
		}
		if (player.isNULL() || player.getInventory().isNULL()) {
			return false;
		}

		Wrapper::ItemStack myHead = player.getInventory().getArrmorItem(3);
		Wrapper::ItemStack entityHead = other.getInventory().getArrmorItem(3);
		if (myHead.isNULL())
		{
			return false;
		}

		if (entityHead.isNULL())
		{
			return false;
		}

		Wrapper::Item myHeadItem = myHead.getItem();
		Wrapper::Item entityHeadItem = entityHead.getItem();

		if (myHeadItem.isNULL())
		{
			return false;
		}

		if (entityHeadItem.isNULL())
		{
			return false;
		}
		if (!myHeadItem.instanceOf(Wrapper::ItemArmor::klass()))
		{
			return false;
		}

		if (!entityHeadItem.instanceOf(Wrapper::ItemArmor::klass()))
		{
			return false;
		}

		auto colorMe = Wrapper::ItemArmor(myHeadItem).getColor(myHead);
		auto colorU = Wrapper::ItemArmor(entityHeadItem).getColor(entityHead);
		LOG("Color Me :" << colorMe << " " << "Color U :" << colorU);
		return colorMe == colorU;
	}
	return false;
}


