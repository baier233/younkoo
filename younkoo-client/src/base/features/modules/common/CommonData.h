#pragma once

#include <utils/Singleton.hpp>
#include <base/event/Events.h>
#include <utils/Math.h>

#include <wrapper/net/minecraft/client/Minecraft.h>
#include <wrapper/net/minecraft/client/renderer/ActiveRenderInfo.h>

class CommonData : public Singleton<CommonData>
{
public:
	void onRender3D(const EventRender3D& e);
	void onUpdate();

	Wrapper::Minecraft mc{};
	Wrapper::EntityPlayerSP player{};


	Math::Matrix projection;
	Math::Matrix modelView;
	Math::Vector3D renderPos;
	Math::Vector3D cameraPos;



	float renderPartialTicks;
	float eyeHeight;
	float fov;

	bool inChatScreen;

	int thirdPersonView;

	std::array<int, 4>viewport;
	Wrapper::ActiveRenderInfo activeRenderInfo;

	CommonData();
protected:
private:

};
