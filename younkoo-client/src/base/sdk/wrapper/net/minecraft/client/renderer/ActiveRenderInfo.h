#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"

BEGIN_WRAP
class ActiveRenderInfo : public Object {
public:
	using Object::Object;
	Math::Matrix getModelViewMatrix();
	Math::Matrix getProjectionMatrix();
};
END_WRAP