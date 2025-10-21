#pragma once
#include <SDK.hpp>
#include "wrapper/Object.h"
#include <wrapper/net/minecraft/entity/EntityLivingBase.h>
#include <wrapper/net/minecraft/inventory/Container.h>
#include "InventoryPlayer.h"

BEGIN_WRAP
class EntityPlayer :public EntityLivingBase {
public:
	using EntityLivingBase::EntityLivingBase;

	bool isSameTeam(EntityPlayer& other);
	static  jclass klass();
	static jmethodID attack_id();
	InventoryPlayer getInventory();
	void jump();
	Wrapper::Container getOpenContainer();

};

END_WRAP