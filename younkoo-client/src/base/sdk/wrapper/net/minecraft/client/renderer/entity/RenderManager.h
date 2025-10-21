#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"

BEGIN_WRAP
class RenderManager :public Object {
public:
	using Object::Object;
	Math::Vector3D getRenderPosition();
};

END_WRAP