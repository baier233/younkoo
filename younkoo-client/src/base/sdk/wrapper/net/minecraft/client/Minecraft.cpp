#include "Minecraft.h"

#include "wrapper/versions/1_18_1/net/minecraft/client/MInecraft.h"
#include "wrapper/versions/1_8_9/net/minecraft/client/MInecraft.h"
#include "wrapper/versions/1_12_2/net/minecraft/client/Minecraft.h"
#include "wrapper/versions/1_20_1/net/minecraft/client/Minecraft.h"

#include "wrapper/versions/1_18_1/net/minecraft/client/gui/screens/ChatScreen.h"
#include "wrapper/versions/1_8_9/net/minecraft/client/gui/GuiChat.h"
#include "wrapper/versions/1_12_2/net/minecraft/client/gui/GuiChat.h"
#include "wrapper/versions/1_20_1/net/minecraft/client/gui/screens/ChatScreen.h"

#include <memory>

Wrapper::Minecraft Wrapper::Minecraft::getMinecraft()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		return Minecraft(V1_18_1::Minecraft::static_obj().getInstance());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		return Minecraft(V1_8_9::Minecraft::static_obj().getMinecraft());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201) {
		return Minecraft(V1_20_1::Minecraft::static_obj().getInstance());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		return Minecraft(V1_12_2::Minecraft::static_obj().getMinecraft());
	}
	assert("unimplemented version");
	return Minecraft();
}

Wrapper::Minecraft Wrapper::Minecraft::static_obj()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		return Minecraft(V1_18_1::Minecraft::static_obj());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		return Minecraft(V1_8_9::Minecraft::static_obj());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201) {
		return Minecraft(V1_20_1::Minecraft::static_obj());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		return Minecraft(V1_12_2::Minecraft::static_obj());
	}
	assert("unimplemented version");
	return Minecraft();
}

bool Wrapper::Minecraft::isInGuiState()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Minecraft mc = this->getObject();
		return !JNI::get_env()->IsSameObject(mc.screen.get().object_instance, NULL);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Minecraft mc = this->getObject();
		return !JNI::get_env()->IsSameObject(mc.currentScreen.get().object_instance, NULL);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Minecraft mc = this->getObject();
		return !JNI::get_env()->IsSameObject(mc.screen.get().object_instance, NULL);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::Minecraft mc = this->getObject();
		return !JNI::get_env()->IsSameObject(mc.currentScreen.get().object_instance, NULL);
	}
	assert("unimplemented version");
	return false;
}

bool Wrapper::Minecraft::isInChatGui()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Minecraft mc = this->getObject();
		auto currentScreen = mc.screen.get().object_instance;
		static auto chatScreenKlass = V1_18_1::ChatScreen::static_obj().init();
		return !JNI::get_env()->IsSameObject(currentScreen, NULL) && JNI::get_env()->IsInstanceOf(currentScreen, chatScreenKlass);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Minecraft mc = this->getObject();
		auto currentScreen = mc.currentScreen.get().object_instance;
		static auto chatScreenKlass = V1_8_9::GuiChat::static_obj().init();
		return !JNI::get_env()->IsSameObject(currentScreen, NULL) && JNI::get_env()->IsInstanceOf(currentScreen, chatScreenKlass);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Minecraft mc = this->getObject();
		auto currentScreen = mc.screen.get().object_instance;
		static auto chatScreenKlass = V1_20_1::ChatScreen::static_obj().init();
		return !JNI::get_env()->IsSameObject(currentScreen, NULL) && JNI::get_env()->IsInstanceOf(currentScreen, chatScreenKlass);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::Minecraft mc = this->getObject();
		auto currentScreen = mc.currentScreen.get().object_instance;
		static auto chatScreenKlass = V1_12_2::GuiChat::static_obj().init();
		return !JNI::get_env()->IsSameObject(currentScreen, NULL) && JNI::get_env()->IsInstanceOf(currentScreen, chatScreenKlass);
	}
	assert("unimplemented version");
	return false;
}

Wrapper::World Wrapper::Minecraft::getWorld()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Minecraft mc = this->getObject();
		return World(mc.level.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Minecraft mc = this->getObject();
		return World(mc.theWorld.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Minecraft mc = this->getObject();
		return World(mc.level.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::Minecraft mc = this->getObject();
		return World(mc.world.get());
	}
	assert("unimplemented version");
	return World();
}

Wrapper::EntityPlayerSP Wrapper::Minecraft::getPlayer()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Minecraft mc = this->getObject();
		return EntityPlayerSP(mc.player.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Minecraft mc = this->getObject();
		return EntityPlayerSP(mc.thePlayer.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Minecraft mc = this->getObject();
		return EntityPlayerSP(mc.player.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::Minecraft mc = this->getObject();
		return EntityPlayerSP(mc.player.get());
	}
	assert("unimplemented version");
	return EntityPlayerSP();
}

Wrapper::MovingObjectPosition Wrapper::Minecraft::getMouseOver()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Minecraft mc = this->getObject();
		return mc.hitResult.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Minecraft mc = this->getObject();
		return mc.objectMouseOver.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Minecraft mc = this->getObject();
		return mc.hitResult.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::Minecraft mc = this->getObject();
		return mc.objectMouseOver.get();
	}
	assert("unimplemented version");
	return MovingObjectPosition();
}

Wrapper::NetworkManager Wrapper::Minecraft::getNetworkManager()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Minecraft mc = this->getObject();
		return mc.getConnection().getConnection();
	}
	assert("unimplemented version");
	return NetworkManager();
}

float Wrapper::Minecraft::getFrameTime()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Minecraft mc = this->getObject();
		return mc.getFrameTime();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Minecraft mc = this->getObject();
		return mc.getFrameTime();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::Minecraft mc = this->getObject();
		return mc.timer.get().renderPartialTicks.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Minecraft mc = this->getObject();
		return mc.timer.get().renderPartialTicks.get();
	}
	assert("unimplemented version");
	return 0.0f;
}

Wrapper::GameSettings Wrapper::Minecraft::getSettings()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Minecraft mc = this->getObject();
		return mc.options.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Minecraft mc = this->getObject();
		return mc.gameSettings.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Minecraft mc = this->getObject();
		return mc.options.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::Minecraft mc = this->getObject();
		return mc.gameSettings.get();
	}
	assert("unimplemented version");
	return GameSettings();
}

void Wrapper::Minecraft::setLeftClickCounter(int value) {
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Minecraft mc = this->getObject();
		mc.missTime.set(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Minecraft mc = this->getObject();
		return mc.leftClickCounter.set(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Minecraft mc = this->getObject();
		mc.missTime.set(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::Minecraft mc = this->getObject();
		mc.leftClickCounter.set(value);
	}
	assert("unimplemented version");
}

int Wrapper::Minecraft::getFps()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Minecraft mc = this->getObject();
		return mc.fps.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Minecraft mc = this->getObject();
		return mc.debugFPS.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Minecraft mc = this->getObject();
		return mc.fps.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::Minecraft mc = this->getObject();
		return mc.debugFPS.get();
	}
	assert("unimplemented version");
	return 0.0f;
}

void Wrapper::Minecraft::setRightClickDelayTimer(int value) {
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Minecraft mc = this->getObject();
		mc.rightClickDelay.set(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::Minecraft mc = this->getObject();
		return mc.rightClickDelayTimer.set(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Minecraft mc = this->getObject();
		mc.rightClickDelay.set(value);
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::Minecraft mc = this->getObject();
		mc.rightClickDelayTimer.set(value);
	}
	assert("unimplemented version");
}

Wrapper::PlayerController Wrapper::Minecraft::getPlayerController() {
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Minecraft mc = this->getObject();
		return mc.gameMode.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Minecraft mc = this->getObject();
		return mc.gameMode.get();
	}
	assert("unimplemented version");
}

Wrapper::RenderManager Wrapper::Minecraft::getRenderManager()
{
	//TODO:189

	if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Minecraft mc = this->getObject();
		return mc.renderManager.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::Minecraft mc = this->getObject();
		return mc.renderManager.get();
	}
	assert("unimplemented version");
	return Wrapper::RenderManager();
}
