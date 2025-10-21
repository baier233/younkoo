#include "FastPlace.h"

FastPlace::FastPlace() :AbstractModule(xorstr_("FastPlace"), Category::PLAYER, xorstr_("FastPlace."))
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
		this->addValue(BoolType, onlyBlockValue);
}

FastPlace& FastPlace::getInstance()
{
	static FastPlace instance = FastPlace();
	return instance;
}

void FastPlace::onEnable()
{
}

void FastPlace::onDisable()
{

}

#include <wrapper/net/minecraft/item/ItemBlock.h>
void FastPlace::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;

	if (SRGParser::get().GetVersion() != Versions::FORGE_1_18_1)
	{
		auto mc = Wrapper::Minecraft::getMinecraft();

		mc.setRightClickDelayTimer(0);
		return;
	}
	auto mc = Wrapper::Minecraft::getMinecraft();
	auto itemStack = mc.getPlayer().getInventory().getCurrentItem();
	if (itemStack.isNULL()) return;
	auto mainItem = itemStack.getItem();
	if (mainItem.getObject() == NULL) return;

	auto offitemStack = mc.getPlayer().getOffhandItemStack();
	if (offitemStack.isNULL()) return;
	auto offItem = offitemStack.getItem();
	if (offItem.getObject() == NULL) return;
	if (onlyBlockValue->getValue() && !(JNI::get_env()->IsInstanceOf(mainItem.getObject(), Wrapper::ItemBlock::klass()) || JNI::get_env()->IsInstanceOf(offItem.getObject(), Wrapper::ItemBlock::klass()))) return;
	mc.setRightClickDelayTimer(0);
}