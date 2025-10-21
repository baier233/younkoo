#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/versions/1_18_1/net/minecraft/network/chat/TextColor.h>
#include <wrapper/versions/1_20_1/net/minecraft/network/chat/TextColor.h>

BEGIN_WRAP
class TextColor :public Object {
public:
	using Object::Object;
	std::string getName();
	int getValue();
};

END_WRAP