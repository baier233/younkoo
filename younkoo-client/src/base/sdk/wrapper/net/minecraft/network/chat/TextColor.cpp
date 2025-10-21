#include "TextColor.h"

std::string Wrapper::TextColor::getName() {
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::TextColor textColor = this->getObject();
		return textColor.name.get().toString();
	}
	else if (SRGParser::get().GetVersion() == Versions::FORGE_1_20_1)
	{
		V1_20_1::TextColor textColor = this->getObject();
		return textColor.name.get().toString();
	}
	return std::string();
}

int Wrapper::TextColor::getValue() {
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::TextColor textColor = this->getObject();
		return textColor.value.get();
	}
	else if (SRGParser::get().GetVersion() == Versions::FORGE_1_20_1)
	{
		V1_20_1::TextColor textColor = this->getObject();
		return textColor.value.get();
	}
	return -1;
}