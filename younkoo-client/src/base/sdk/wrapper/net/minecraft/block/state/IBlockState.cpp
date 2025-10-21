#include "IBlockState.h"
#include <wrapper/versions/1_8_9/net/minecraft/block/state/IBlockState.h>
#include <wrapper/versions/1_12_2/net/minecraft/block/state/IBlockState.h>
Wrapper::Block Wrapper::IBlockState::getBlock()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::IBlockState state = this->getObject();
		return state.getBlock();
	}
	if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::IBlockState state = this->getObject();
		return state.getBlock();
	}
	return Block();
}
