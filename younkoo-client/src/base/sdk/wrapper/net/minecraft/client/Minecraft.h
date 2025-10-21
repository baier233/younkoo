#pragma once

#include <SDK.hpp>
#include "wrapper/net/minecraft/util/MovingObjectPosition.h"
#include "wrapper/net/minecraft/world/World.h"
#include "wrapper/net/minecraft/client/entity/EntityPlayerSP.h"
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/client/settings/GameSettings.h>
#include <wrapper/net/minecraft/multiplayer/PlayerController.h>
#include <wrapper/net/minecraft/client/renderer/entity/RenderManager.h>
#include <wrapper/net/minecraft/network/NetworkManager.h>
BEGIN_WRAP

class Minecraft :public Object {
public:
	using Object::Object;
	static Minecraft getMinecraft();
	static Minecraft static_obj();
	bool isInGuiState();
	bool isInChatGui();
	World getWorld();
	EntityPlayerSP getPlayer();
	MovingObjectPosition getMouseOver();
	NetworkManager getNetworkManager();
	float getFrameTime();
	GameSettings getSettings();
	void setLeftClickCounter(int value);
	int getFps();
	void setRightClickDelayTimer(int value);
	Wrapper::PlayerController getPlayerController();
	Wrapper::RenderManager getRenderManager();
private:
};

END_WRAP