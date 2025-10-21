#pragma once
#include "../AbstractModule.h"
#include <wrapper/net/minecraft/client/entity/EntityPlayerSP.h>
#include <jdk/Classes.h>
class Antibot :public AbstractModule {
public:
	static Antibot& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
	bool isBot(Wrapper::EntityPlayer& p);
protected:
	Antibot();
private:
	std::vector<Wrapper::EntityPlayer> heightBots;
	std::vector<Wrapper::EntityPlayer> healthEntities;
};