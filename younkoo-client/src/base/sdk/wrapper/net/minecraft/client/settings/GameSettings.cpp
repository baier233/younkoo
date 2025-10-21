#include "GameSettings.h"
#include <wrapper/versions/1_18_1/net/minecraft/client/Options.h>
#include <wrapper/versions/1_20_1/net/minecraft/client/Options.h>
#include <wrapper/versions/1_8_9/net/minecraft/client/settings/GameSettings.h>
#include <wrapper/versions/1_12_2/net/minecraft/client/settings/GameSettings.h>
float Wrapper::GameSettings::getFov()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Options settings = this->getObject();
		return settings.fov.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::GameSettings settings = this->getObject();
		return settings.fovSetting.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Options settings = this->getObject();
		V1_20_1::OptionInstance fov = settings.fov.get();
		//i cant fix it
		//return fov.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::GameSettings settings = this->getObject();
		return settings.fovSetting.get();
	}
	assert("unimplemented version");
	return 0.0f;
}

void Wrapper::GameSettings::setShiftKeyPressed(bool value)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Options settings = this->getObject();
		settings.keyShift.get().setDown(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Options settings = this->getObject();
		settings.keyShift.get().setDown(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::GameSettings settings = this->getObject();
		settings.keyBindSneak.get().pressed.set(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::GameSettings settings = this->getObject();
		settings.keyBindSneak.get().pressed.set(value);
	}
	assert("unimplemented version");
	return;
}

bool Wrapper::GameSettings::getShiftKeyPressed()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Options settings = this->getObject();
		settings.keyShift.get().isDown.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Options settings = this->getObject();
		settings.keyShift.get().isDown.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::GameSettings settings = this->getObject();
		return settings.keyBindSneak.get().pressed.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::GameSettings settings = this->getObject();
		return settings.keyBindSneak.get().pressed.get();
	}
	assert("unimplemented version");
	return false;
}

int Wrapper::GameSettings::getAttackKey()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Options settings = this->getObject();
		return settings.keyAttack.get().getKey().getValue();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Options settings = this->getObject();
		return settings.keyAttack.get().getKey().getValue();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::GameSettings settings = this->getObject();
		return settings.keyBindAttack.get().keyCode.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::GameSettings settings = this->getObject();
		return settings.keyBindAttack.get().keyCode.get();
	}
	return 0;
}

int Wrapper::GameSettings::getUseKey()
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Options settings = this->getObject();
		return settings.keyUse.get().getKey().getValue();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Options settings = this->getObject();
		return settings.keyUse.get().getKey().getValue();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::GameSettings settings = this->getObject();
		return settings.keyBindUseItem.get().keyCode.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::GameSettings settings = this->getObject();
		return settings.keyBindUseItem.get().keyCode.get();
	}
	return 0;
}

void Wrapper::GameSettings::setToggleSprint(bool value) {
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Options settings = this->getObject();
		settings.toggleSprint.set(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Options settings = this->getObject();
		V1_20_1::OptionInstance toggleSprint = settings.toggleSprint.get();
		//toggleSprint.set(value);
	}
	/*else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::GameSettings settings = this->getObject();
		return settings.keyBindSprint.get().pressed.set(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::GameSettings settings = this->getObject();
		return settings.keyBindSprint.get().pressed.set(value);
	}*/
}

bool Wrapper::GameSettings::getToggleSprint() {
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Options settings = this->getObject();
		return settings.toggleSprint.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Options settings = this->getObject();
		V1_20_1::OptionInstance toggleSprint = settings.toggleSprint.get();
		//return toggleSprint.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::GameSettings settings = this->getObject();
		return settings.keyBindSprint.get().pressed.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::GameSettings settings = this->getObject();
		return settings.keyBindSprint.get().pressed.get();
	}
	return false;
}
//TODO:1.20.1
void Wrapper::GameSettings::setGamma(double value) {
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Options settings = this->getObject();
		settings.gamma.set(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::GameSettings settings = this->getObject();
		return settings.gammaSetting.set(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::GameSettings settings = this->getObject();
		return settings.gammaSetting.set(value);
	}
}
//TODO:1.20.1
double Wrapper::GameSettings::getGamma() {
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Options settings = this->getObject();
		return settings.gamma.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::GameSettings settings = this->getObject();
		return settings.gammaSetting.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_12_2::GameSettings settings = this->getObject();
		return settings.gammaSetting.get();
	}
	return 0.0f;
}

void Wrapper::GameSettings::setSprintKeyPressed(bool value)
{
	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1)
	{
		V1_18_1::Options settings = this->getObject();
		settings.keySprint.get().setDown(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::GameSettings settings = this->getObject();
		settings.keyBindSprint.get().pressed.set(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Options settings = this->getObject();
		settings.keySprint.get().setDown(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::GameSettings settings = this->getObject();
		settings.keyBindSprint.get().pressed.set(value);
	}
	assert("unimplemented version");
	return;
}

int Wrapper::GameSettings::getThirdPersonView()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::GameSettings settings = this->getObject();
		return settings.thirdPersonView.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::GameSettings settings = this->getObject();
		return settings.thirdPersonView.get();
	}
	return 0;
}
