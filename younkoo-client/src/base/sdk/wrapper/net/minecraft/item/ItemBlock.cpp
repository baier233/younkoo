#include "ItemBlock.h"

#include <wrapper/versions/1_18_1/net/minecraft/world/item/BlockItem.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/item/BlockItem.h>
#include <wrapper/versions/1_8_9/net/minecraft/item/ItemBlock.h>
#include <wrapper/versions/1_12_2/net/minecraft/item/ItemBlock.h>
jclass Wrapper::ItemBlock::klass()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		static auto klass = V1_18_1::BlockItem::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		static auto klass = V1_20_1::BlockItem::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		static auto klass = V1_12_2::ItemBlock::static_obj().init();
		return klass;
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		static auto klass = V1_8_9::ItemBlock::static_obj().init();
		return klass;
	}
	return jclass();
}
