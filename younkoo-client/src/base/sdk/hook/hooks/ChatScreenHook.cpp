#include "ChatScreenHook.h"
#include <wrapper/versions/1_18_1/net/minecraft/client/gui/screens/ChatScreen.h>
#include "jdk/Classes.h"
#include <../features/command/CommandManager.h>
#include <ripterms/javahook/JavaHook.h>
static void detour_SendMessage(Ripterms::JavaHook::HotSpot::frame* frame, java_hotspot::java_thread* thread, bool* cancel) {
	JNI::set_thread_env(thread->get_jni_environment());
	auto str_obj = Ripterms::JavaHook::get_jobject_param_at(frame, 1);
	std::string message = String(str_obj).toString();
	//LOG("Message : " << message);
	if (message.rfind(".", 0) == 0) {
		CommandManager::get().executeCommand(message.erase(0, 1));
		*cancel = true;
	}
	//LOG("on channel read 0 ");
}

void ChatScreenHook::hook(const HookManagerData& container)
{

	if (SRGParser::get().GetVersion() != Versions::FORGE_1_18_1)
		return;
	LOG("Processing hook for ChatScreen ");

	auto& methods_being_hooked = container.methods_being_hooked;
	auto& methods_dont_compile = container.methods_dont_compile;
	auto& klasses_dont_compile = container.klasses_dont_compile;


	(void)JNI::get_env()->PushLocalFrame(66);

	jclass klass = JNI::find_class(V1_18_1::ChatScreen::get_name());

	JVM::get().jvmti->RetransformClasses(1, &klass);
	{

		auto mid = (jmethodID)V1_18_1::ChatScreen::static_obj().sendMessage.init();
		const auto method = *reinterpret_cast<java_hotspot::method**>(mid);
		Ripterms::JavaHook::hook(mid, detour_SendMessage);
		//methods_being_hooked.emplace_back(method);
		//HookUtils::GenericResolve(method);
		//ResolveChannleRead0(method);
	}

	(void)JNI::get_env()->PopLocalFrame(nullptr);
}
