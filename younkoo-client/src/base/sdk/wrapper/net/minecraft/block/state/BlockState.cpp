#include "BlockState.h"
#include <wrapper/versions/1_18_1/net/minecraft/world/level/block/state/BlockState.h>
#include <wrapper/versions/1_8_9/net/minecraft/block/state/BlockState.h>
#include <wrapper/versions/1_12_2/net/minecraft/block/state/IBlockState.h>
#include <wrapper/versions/1_20_1/net/minecraft/world/level/block/state/BlockState.h>

#include <hotspot/classes/c_method.h>
Wrapper::Block Wrapper::BlockState::getBlock()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::BlockState state = this->getObject();
		return state.getBlock();
	}

	 if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::BlockState state = this->getObject();
		return state.block.get();
	}

	if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::BlockState state = this->getObject();
		return state.getBlock();
	}
	
	return Block();
}
//TODO:1.8.9 1.12.2
bool Wrapper::BlockState::isAir()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::BlockState state = this->getObject();
		return state.isAir();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::BlockState state = this->getObject();
		return state.isAir();
	}
	return false;
}
