#include "Style.h"

Wrapper::TextColor Wrapper::Style::getColor() {
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Style style = this->getObject();
		return style.color.get();
	}
	else if (SRGParser::get().GetVersion() == Versions::FORGE_1_20_1)
	{
		V1_20_1::Style style = this->getObject();
		return style.color.get();
	}
	return TextColor();
}