#include "Younkoo.hpp"
#include <iostream>	
#include "features/modules/ModuleManager.h"
#include "features/command/CommandManager.h"
#include "jvm/JVM.hpp"

Younkoo::Younkoo()
{
}

#include <SDK.hpp>

#include <wrapper/net/minecraft/client/Minecraft.h>
#include <wrapper/versions/1_18_1/net/minecraft/client/Minecraft.h>

#include "render/Renderer.hpp"
#include "render/nano/NanovgHelper.hpp"
#include "render/gui/input/Context.hpp"

#include "features/modules/common/CommonData.h"
#include "features/api/chunk/ChunkScanner.h"

#include "sdk/Mapper/SRGParser.h"

#include <base/sdk/hook/HookManager.h>
#include <base/patcher/PatcherManager.h>

#ifdef PUBLISH
#include "protocol/verify.h"
#endif // PULISH
#include "features/api/ClickApi.h"
#include <utils/jvm_utility.h>


bool Younkoo::setup()
{

	auto flag = JVM::get().setup();
	LOG("JVM Loaded");
#ifdef PUBLISH
	//flag &= Verfiy::init();
#endif // PUBLISH

	SDK::CheckVersion();
	ModuleManager::get().LoadModules();
	LOG("Module Loaded");
	CommandManager::get().LoadCommands();
	LOG("Commands Loaded");
	flag &= Renderer::get().Init();
	LOG("Renderer Loaded");
	auto classloader = younkoo::jvm_utility::get_thread_classloader("Render thread");
	if (classloader == nullptr)
		classloader = younkoo::jvm_utility::get_thread_classloader("Client thread");

	if (classloader != nullptr) {
		SDK::MinecraftClassLoader = classloader;
	}
	else {
		flag &= SDK::SetUpClassLoader(SRGParser::get().getObfuscatedClassName("net/minecraft/client/Minecraft"));
	}

	LOG("SRGParser Parsed");


	if (!flag) return flag;


	if (SDK::MinecraftClassLoader)
	{
		LOG("MinecraftClassLoader Found");
		JNI::set_class_loader(SDK::MinecraftClassLoader);
	}


	if (SRGParser::get().GetVersion() == Versions::FORGE_1_18_1) {
		HookManager::get().setup();
		HookManager::get().handle();
		LOG("HookManager loaded");
	}
	else {
		JavaHook::JVM::Init(JVM::get().Env, false);
	}


	PatcherManager::get().setup();
	PatcherManager::get().handle();


	LOG("Setting Up");

	auto& common = CommonData::get();
	ClickApi::Init();
	//ChunkScanner::setup();


	while (!shouldShutDown)
	{
		while (!YounkooIO::keyEvents.empty())
		{
			auto& event = YounkooIO::keyEvents.front();
			if (event.keycode == VK_END)
			{
				shouldShutDown = true;
				break;
			}

			if (!common.inChatScreen)	ModuleManager::get().ProcessKeyEvent(event.keycode);

			YounkooIO::keyEvents.pop();
		}

		CommonData::get().onUpdate();
		ModuleManager::get().ProcessUpdate();

		Sleep(1);
	}

	return Younkoo::shutdown();
}



#include "../Main.hpp"

#include "cleaner/UnloadedModuleCleaner.h"
#include <utils/Memory.h>
bool Younkoo::shutdown()
{


	for (auto& m : ModuleManager::get().getMods()) {
		if (m)
		{
			auto mod = ToBaseModule(m);
			if (mod->getToggle())
			{
				mod->setToggle(false);
			}
		}
	}
	shouldShutDown = true;
	UnloadedModuleCleaner::Clean();
	HookManager::get().clean();
	utils::memory::clean_all_allocated_memory();
	auto flag = Renderer::get().Shutdown() && JVM::get().shutdown();
	PatcherManager::get().clean();
	if (!flag) return false;
#ifndef PULISH
	Console::CloseConsole_();
	FreeLibraryAndExitThread(Main::current_module, 0);
#endif // PULISH
	return true;
}