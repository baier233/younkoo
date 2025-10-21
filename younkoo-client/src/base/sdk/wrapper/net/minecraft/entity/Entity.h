#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <utils/types/Maths.hpp>
#include <wrapper/net/minecraft/network/chat/Style.h>
#include <string>

BEGIN_WRAP
class Entity :public Object {
public:
	using Object::Object;
	// higer version only
	void setGlowing(bool value);
	Math::Vector3D getPosition();
	Math::Vector3D getPosition(float tickDetal);
	Math::Vector3D getLastTickPos();
	std::string getDisplayName();
	Wrapper::Style getDisplayName_Style();
	float getWidth();
	float getHeight();
	Math::Rotation getAngles();
	void setAngles(Math::Vector2 angles);
	float getEyeHeight();
	bool isOnGround();
	bool isSneaking();
	Math::Vector3D getMotion();
	void setMotion(Math::Vector3D motion);
	void setSneak(bool value);
	int getEntityID();
	std::string getUUID();
	Math::Box<double> getBoundingBox();
};

END_WRAP