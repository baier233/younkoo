#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include "TextColor.h"
#include <wrapper/versions/1_18_1/net/minecraft/network/chat/Style.h>
#include <wrapper/versions/1_20_1/net/minecraft/network/chat/Style.h>

BEGIN_WRAP
class Style:public Object {
public:
	using Object::Object;
	Wrapper::TextColor getColor();
};

END_WRAP