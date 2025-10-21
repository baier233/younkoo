#include "MovementInput.h"
#include <wrapper/versions/1_18_1/net/minecraft/client/player/Input.h>
#include <wrapper/versions/1_20_1/net/minecraft/client/player/Input.h>
#include <wrapper/versions/1_8_9/net/minecraft/util/MovementInput.h>
#include <wrapper/versions/1_12_2/net/minecraft/util/MovementInput.h>

float Wrapper::MovementInput::getMoveForward()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Input input = this->getObject();
		return input.forwardImpulse.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Input input = this->getObject();
		return input.forwardImpulse.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::MovementInput input = this->getObject();
		return input.moveForward.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::MovementInput input = this->getObject();
		return input.moveForward.get();
	}
	return 0.0f;
}