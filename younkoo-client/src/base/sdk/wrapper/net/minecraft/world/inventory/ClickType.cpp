#include "ClickType.h"

Wrapper::ClickType Wrapper::ClickType::QUICKMOVE() {
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{

		return V1_18_1::ClickType::static_obj().QUICK_MOVE.get();
	}
	else if (SRGParser::get().GetVersion() == Versions::FORGE_1_20_1)
	{

		return V1_20_1::ClickType::static_obj().QUICK_MOVE.get();
	}
	return ClickType();
}