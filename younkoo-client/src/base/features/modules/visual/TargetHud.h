#include "../AbstractModule.h"
#include "../../../event/Events.h"
#include "../../../Younkoo.hpp"
#include "../ModuleManager.h"
#include <GL/glew.h>
#include <nanovg.h>
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <optional>
class TargetHud : public AbstractModule
{
public:
	static TargetHud& getInstance();
	void onEnable();
	void onDisable();
	void onUpdate();
	void onRender(const EventRender2D& e);
	bool clear = false;
	std::optional<Wrapper::EntityPlayer> renderTarget{};
private:

	TargetHud();
};
