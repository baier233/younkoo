#include "Block.h"
#include <wrapper/net/minecraft/block/state/BlockState.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/level/block/Block.h>
#include <wrapper/versions/1_18_1/net/minecraft/world/level/block/state/BlockState.h>
int Wrapper::Block::getID(Wrapper::BlockState& state)
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Block block = this->getObject();

		//return block.getId(state.getObject());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		//wtf?
	}
	return 0;
}
