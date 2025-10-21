#pragma once
#include <base\render\screen\impl\component\Component.h>
#include <base\render\nano\NanovgHelper.hpp>
#include <base\features\modules\AbstractModule.h>
#include <utils\animation\Animation.h>
class ValueComponent : public Component
{
public:
	float component_height_ = 35.0F;
};