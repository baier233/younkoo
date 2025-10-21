#pragma once
#include "../render/nano/NanovgHelper.hpp"
#include <utils/types/Maths.hpp>

class Event {};

class EventRender2D
{
public:
	NVGcontext*& vg;
	int winWidth, winHeight;
};

class EventUpdate {
public:
};

class EventRender3D
{
public:
	Math::Matrix PROJECTION_MATRIX;
	Math::Matrix MODELVIEW_MATRIX;
	Math::Vector3D CAMERA_POS;
	float TICK_DELTA;
	long START_TIME = 0;
	double GUI_SCALE = 0;
};

class EventLoadChunk {
public:
	int x;
	int z;
};
class EventUnloadChunk {
public:
	int x;
	int z;
};
class EventUpdateChunk {
public:
	int x;
	int z;
};
#include <wrapper/net/minecraft/util/\BlockPos.h>
#include <wrapper/net/minecraft/block/state/BlockState.h>

class EventChangeBlock {
public:
	Wrapper::BlockPos& pos;
	Wrapper::BlockState& state;
};
#include <wrapper/net/minecraft/entity/Entity.h>

class EventAttack {
public:
	Wrapper::Entity& entity;
};


enum PacketType {
	RECEIVE,
	SEND,
};

#include <wrapper/net/minecraft/network/Packet.h>
#include <hotspot/classes/java_thread.h>
class EventPacket {
public:
	Wrapper::Packet& packet;
	PacketType type;
	java_hotspot::java_thread* thread;
	bool cancel = false;
};

class EventStrafe {
public:
	float forward = 0;
	float strafe = 0;
	float friction = 0;
	float yaw = 0;
};

class EventJump {
public:
	float yaw = 0;
};