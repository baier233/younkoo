#include "ItemAxe.h"

#include <wrapper/versions/1_18_1/net/minecraft/world/item/AxeItem.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/item/AxeItem.h>
#include <wrapper/versions/1_12_2/net/minecraft/item/ItemAxe.h>
#include <wrapper/versions/1_8_9/net/minecraft/item/ItemAxe.h>
jclass Wrapper::ItemAxe::klass()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		static auto klass = V1_18_1::AxeItem::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		static auto klass = V1_20_1::AxeItem::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		static auto klass = V1_12_2::ItemAxe::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		static auto klass = V1_8_9::ItemAxe::static_obj().init();
		return klass;
	}
	return jclass();
}
