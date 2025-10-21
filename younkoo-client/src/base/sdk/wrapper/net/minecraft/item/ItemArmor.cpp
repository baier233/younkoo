#include "ItemArmor.h"
#include <wrapper/versions/1_12_2/net/minecraft/item/ItemArmor.h>
#include <wrapper/versions/1_8_9/net/minecraft/item/ItemArmor.h>
jclass Wrapper::ItemArmor::klass()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		static auto klass = V1_12_2::ItemArmor::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		static auto klass = V1_8_9::ItemArmor::static_obj().init();
		return klass;
	}
	return jclass();
}

int Wrapper::ItemArmor::getColor(Wrapper::ItemStack& stack)
{
	if (this->isNULL() || stack.isNULL()) return -1;
	if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::ItemArmor armor = this->getObject();
		V1_12_2::ItemStack s = stack.getObject();
		return armor.getColor(s);

	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::ItemArmor armor = this->getObject();
		V1_8_9::ItemStack s = stack.getObject();
		return armor.getColor(s);
	}
	return 0;
}
