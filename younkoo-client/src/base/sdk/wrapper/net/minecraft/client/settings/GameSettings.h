#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"

BEGIN_WRAP
class GameSettings : public Object {
public:
	using Object::Object;
	float getFov();
	void setShiftKeyPressed(bool value);
	bool getShiftKeyPressed();
	int getAttackKey();
	int getUseKey();
	void setToggleSprint(bool value);
	bool getToggleSprint();
	void setGamma(double value);
	double getGamma();
	void setSprintKeyPressed(bool value);
	int getThirdPersonView();
};
END_WRAP