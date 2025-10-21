#include "PlayerController.h"
#include <wrapper/versions/1_18_1/net/minecraft/client/multiplayer/MultiPlayerGameMode.h>
#include <wrapper/versions/1_20_1/net/minecraft/client/multiplayer/MultiPlayerGameMode.h>

bool Wrapper::PlayerController::isHittingBlock(){
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::MultiPlayerGameMode sb = this->getObject();
		return sb.isDestroying.get();
	}
	assert("unimplemented version");
	return false;
}

void Wrapper::PlayerController::handleInventoryMouseClick(int k, int l, int m, ClickType arg, EntityPlayer arg2) {
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		V1_18_1::MultiPlayerGameMode sb = this->getObject();
		V1_18_1::ClickType aaaa(arg.getObject());
		V1_18_1::Player aaaa2(arg2.getObject());
		sb.handleInventoryMouseClick(k, l, m, aaaa, aaaa2);
	}

	if (SRGParser::get().GetVersion() == Versions::FORGE_1_20_1)
	{

		V1_20_1::MultiPlayerGameMode sb = this->getObject();
		V1_20_1::ClickType aaaa(arg.getObject());
		V1_20_1::Player aaaa2(arg2.getObject());
		sb.handleInventoryMouseClick(k, l, m, aaaa, aaaa2);
	}
}