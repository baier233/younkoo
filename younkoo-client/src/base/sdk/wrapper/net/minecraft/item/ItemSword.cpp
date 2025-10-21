#include "ItemSword.h"

#include <wrapper/versions/1_18_1/net/minecraft/world/item/SwordItem.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/item/SwordItem.h>
#include <wrapper/versions/1_8_9/net/minecraft/item/ItemSword.h>
#include <wrapper/versions/1_12_2/net/minecraft/item/ItemSword.h>

jclass Wrapper::ItemSword::klass()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		static auto klass = V1_18_1::SwordItem::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		static auto klass = V1_20_1::SwordItem::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		static auto klass = V1_12_2::ItemSword::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		static auto klass = V1_8_9::ItemSword::static_obj().init();
		return klass;
	}
	return jclass();
}
