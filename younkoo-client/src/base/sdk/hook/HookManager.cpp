#include "HookManager.h"
#include <hotspot/java_hook.h>
#include <jni/types/Env.hpp>
#include <hotspot/classes/compile_task.h>
#include <utils/Pattern.h>
#include <ripterms/javahook/JavaHook.h>
static std::vector<java_hotspot::method*> methods_being_hooked;
static std::vector<java_hotspot::method*> methodes_dont_compile;
static std::vector<java_hotspot::instance_klass*> klasses_dont_compile;
static void detour_invoke_compiler_on_method(java_hotspot::compile_task* task);
static void detour_do_analysis(void** ciMethodBlocks);
static void detour_cg_do_analysis(void* compile, void* phaseIterGVN);
static bool detour_ok_to_inline(void* inlinetree,
	void* callee_method,
	void* jvms,
	void* profile,
	bool* should_delay);
static void detour_safepoint_synchronize_block(java_hotspot::java_thread* thread);
static void* detour_get_bcea(void** ciMethod);
static void detour_trim_queue_to_threshold(void* state, unsigned int threshold);
static TitanHook<decltype(&detour_safepoint_synchronize_block)> _safepoint_synchronize_block_hook;
static TitanHook<decltype(&detour_invoke_compiler_on_method)> _invoke_compiler_on_method_hook;
static TitanHook<decltype(&detour_do_analysis)> _do_analysis_hook;
static TitanHook<decltype(&detour_do_analysis)> _do_cg_analysis_hook;
static TitanHook<decltype(&detour_ok_to_inline)> _ok_to_inline_hook;
static TitanHook<decltype(&detour_get_bcea)> _get_bcea_hook;
static TitanHook<decltype(&detour_trim_queue_to_threshold)> _trim_queue_to_threshold_hook;

void HookManager::clean() {
	for (auto ptr : methods_being_hooked)
	{
		auto method = reinterpret_cast<java_hotspot::method*>(ptr);
		method->remove_all_break_points();
	}
	JavaHook::JVM::clean();
	_invoke_compiler_on_method_hook.RemoveHook();
	_do_analysis_hook.RemoveHook();
	_ok_to_inline_hook.RemoveHook();
	_get_bcea_hook.RemoveHook();
	Ripterms::JavaHook::clean();
}

static void detour_invoke_compiler_on_method(java_hotspot::compile_task* task) {
	//TODO : hook ok_to_inline to improve performance
	auto method = task->get_method();
	auto holder = method->get_const_method()->get_constants()->get_pool_holder();
	//LOG("Compiling method :" << method->get_name());
	for (auto pMethod : methodes_dont_compile)
	{
		if (method == pMethod)
		{
			//LOG("Force break compile of " << static_cast<java_hotspot::instance_klass*>(current_pool_holder)->get_name()->to_string());
			return;
		}
	}

	for (auto pMethod : methods_being_hooked)
	{
		if (method == pMethod)
		{
			//LOG("Force break compile of " << static_cast<java_hotspot::instance_klass*>(current_pool_holder)->get_name()->to_string());
			return;
		}
	}

	for (auto klass : klasses_dont_compile)
	{
		if (klass == holder)
		{
			//LOG("Force break compile of " << static_cast<java_hotspot::instance_klass*>(current_pool_holder)->get_name()->to_string());
			return;
		}
	}

	_invoke_compiler_on_method_hook.GetOrignalFunc()(task);
}
void* detour_get_bcea(void** ciMethod) {
	if (!ciMethod) return _get_bcea_hook.GetOrignalFunc()(ciMethod);
	static VMStructEntry* _metadata_entry = JVMWrappers::find_type_fields("ciMetadata").value().get()[
		"_metadata"];
	auto method = *reinterpret_cast<java_hotspot::method**>(reinterpret_cast<uint8_t*>(ciMethod) + _metadata_entry->offset);
	LOG("getting bcea for method :" << method->get_name());
	for (auto& pMethod : methods_being_hooked)
	{
		if (method == pMethod)
		{
			LOG("force break getting bcea for method :" << pMethod->get_name());
			return nullptr;
		}
	}

	return nullptr;
	//return _get_bcea_hook.GetOrignalFunc()(ciMethod);
}
void detour_trim_queue_to_threshold(void* state, unsigned int threshold)
{
	std::cout << "On trim_queue_to_threshold" << std::endl;
	return;
}
void detour_do_analysis(void** ciMethodBlocks)
{
	static VMStructEntry* _metadata_entry = JVMWrappers::find_type_fields("ciMetadata").value().get()[
		"_metadata"];
	auto method = *reinterpret_cast<java_hotspot::method**>(*reinterpret_cast<uint8_t**>(ciMethodBlocks) + _metadata_entry->offset);
	//LOG(method->get_name());
	for (auto pMethod : methods_being_hooked)
	{
		if (method == pMethod)
		{
			LOG("Force break analysis of " << pMethod->get_name());

			return;
		}
	}

	//LOG("loading method's code :" << method->get_name() << " " + method->get_signature());
	_do_analysis_hook.GetOrignalFunc()(ciMethodBlocks);
}
void detour_cg_do_analysis(void* compile, void* phaseIterGVN)
{
	return;
}
constexpr bool DONT_INLINE = false;
bool detour_ok_to_inline(void* inlinetree, void* callee_method, void* jvms, void* profile, bool* should_delay)
{
	static VMStructEntry* _metadata_entry = JVMWrappers::find_type_fields("ciMetadata").value().get()[
		"_metadata"];
	auto method = *reinterpret_cast<java_hotspot::method**>(reinterpret_cast<uint8_t*>(callee_method) + _metadata_entry->offset);
	for (auto pMethod : methods_being_hooked)
	{
		if (method == pMethod)
		{
			LOG("Force break inling of " << pMethod->get_name());

			return DONT_INLINE;
		}
	}
	return _ok_to_inline_hook.GetOrignalFunc()(inlinetree, callee_method, jvms, profile, should_delay);
}
#include "HookUtils.h"
void detour_safepoint_synchronize_block(java_hotspot::java_thread* thread)
{
	auto it = HookUtils::o_thread_map.find(thread);
	if (it != HookUtils::o_thread_map.end())
	{
		auto orginal_state = it->second;
		thread->set_thread_state(orginal_state);
	}
	else {
		thread->set_thread_state(JavaThreadState::_thread_in_Java);
	}
	_safepoint_synchronize_block_hook.GetOrignalFunc()(thread);
}
/*
FakePDB/signatures_find:
   * address  : 0x1801d0480
   * name     : ?do_analysis@ciMethodBlocks@@AEAAXXZ
   * signature: 48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 55 41 54 41 55 41 56 41 57 48 8B EC 48 81 EC 80 00 00 00 48 8B 19

FakePDB/signatures_find:
   * address  : 0x1801ceec0
   * name     : ?load_code@ciMethod@@AEAAXXZ
   * signature: 40 53 41 56 48 83 EC 38 65 48 8B 04 25 58 00 00 00

   FakePDB/signatures_find:
   * address  : 0x180125c90
   * name     : ?ok_to_inline@InlineTree@@QEAA_NPEAVciMethod@@PEAVJVMState@@AEAVciCallProfile@@AEA_N@Z
   * signature: 48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 81 EC 90 00 00 00 45 8B 70 24
   *
   * FakePDB/signatures_find:
   * address  : 0x1806d4b30
   * name     : ?block@SafepointSynchronize@@CAXPEAVJavaThread@@@Z
   * signature: 40 53 48 83 EC 30 48 8B D9 E8 ? ? ? ? 48 8B C8
   * 40 53 48 83 EC 30 48 8B D9 E8 ? ? ? ? 48 8B C8

   FakePDB/signatures_find:
   * address  : 0x1801ccf20
   * name     : ?get_bcea@ciMethod@@QEAAPEAVBCEscapeAnalyzer@@XZ
   * signature: 40 53 48 83 EC 20 48 8B 81 98 00 00 00 48 8B D9 48 85 C0

   FakePDB/signatures_find:
   * address  : 0x1d92c0
   * name     : ?next_wide_or_table@ciBytecodeStream@@AEAA?AW4Code@Bytecodes@@W423@@Z
   * signature: 40 53 48 83 EC 20 44 8B C2 8B DA

   FakePDB/signatures_find:
   * address  : 0x2b5550
   * name     : ?do_analysis@ConnectionGraph@@SAXPEAVCompile@@PEAVPhaseIterGVN@@@Z
   * signature: 48 89 5C 24 10 55 56 57 41 54 41 55 41 56 41 57 48 81 EC 80 00 00 00 48 8B EA

   FakePDB/signatures_find:
   * address  : 0x306e30
   * name     : ?trim_queue_to_threshold@G1ParScanThreadState@@AEAAXI@Z
   * signature: 48 89 5C 24 10 55 56 57 41 56 41 57 48 83 EC 20 44 8B F2
*/

//we can only hook ok_to_inline,but for some reasons i am going to 
static void hook_invoke_compiler_on_method() {
	auto jvm = (uintptr_t)GetModuleHandleA("jvm.dll");
	//48 89 ?? ?? ?? 48 89 ?? ?? ?? 48 ?? ?? ?? ?? ?? ?? 41 ?? ?? 4C ?? ?? ?? ?? ?? ?? 48 ?? ?? ?? ?? ?? ??
	auto pcg_do_analysis = (void*)CUtil_Pattern::Find(jvm, "48 89 5C 24 10 55 56 57 41 54 41 55 41 56 41 57 48 81 EC 80 00 00 00 48 8B EA");
	if (!pcg_do_analysis)
	{
		MessageBox(0, L"Failed to get the address of cg_do_analysis", 0, 0);
	}

	auto psafeblock_synchronize_block = (void*)CUtil_Pattern::Find(jvm, "40 53 48 83 EC 30 48 8B D9 E8 ? ? ? ? 48 8B C8");
	if (!psafeblock_synchronize_block)
	{
		MessageBox(0, L"Failed to get the address of safeblock_synchronize_block", 0, 0);
	}
	//CompileBroker::invoke_compiler_on_method(CompileTask *task)
	auto pinvoke_compiler_on_method = (void*)CUtil_Pattern::Find(jvm, "48 89 5C 24 10 48 89 74 24 18 48 89 7C 24 20 55 41 54 41 55 41 56 41 57 48 8D AC 24 80 FA FF FF 48 81 EC 80 06 00 00 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 70 05 00 00 33 D2");// this function will call    __dyn_tls_on_demand_init and doing something like NtCurrentTeb()->ThreadLocalStoragePointer + (unsigned int)TlsIndex);
	if (!pinvoke_compiler_on_method)
	{
		MessageBox(0, L"Failed to get the address of invoke_compiler_on_method", 0, 0);
	}

	auto pdo_analysis = (void*)CUtil_Pattern::Find(jvm, "48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 55 41 54 41 55 41 56 41 57 48 8B EC 48 81 EC 80 00 00 00 48 8B 19");
	if (!pdo_analysis)
	{
		MessageBox(0, L"Failed to get the address of do_analysis", 0, 0);
	}

	auto pok_to_inline = (void*)CUtil_Pattern::Find(jvm, "48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 81 EC 90 00 00 00 45 8B 70 24");
	if (!pok_to_inline)
	{
		MessageBox(0, L"Failed to get the address of ok_to_inline", 0, 0);
	}






	if (psafeblock_synchronize_block)
	{
		_safepoint_synchronize_block_hook.InitHook(psafeblock_synchronize_block, detour_safepoint_synchronize_block);
		_safepoint_synchronize_block_hook.SetHook();
	}

	if (pinvoke_compiler_on_method)
	{
		_invoke_compiler_on_method_hook.InitHook(pinvoke_compiler_on_method, detour_invoke_compiler_on_method);
		_invoke_compiler_on_method_hook.SetHook();
	}

	if (pok_to_inline)
	{
		_ok_to_inline_hook.InitHook(pok_to_inline, detour_ok_to_inline);
		_ok_to_inline_hook.SetHook();

	}

	if (pdo_analysis)
	{

		_do_analysis_hook.InitHook(pdo_analysis, detour_do_analysis);
		_do_analysis_hook.SetHook();

	}

	if (pcg_do_analysis)
	{
		_do_cg_analysis_hook.InitHook(pcg_do_analysis, detour_cg_do_analysis);
		_do_cg_analysis_hook.SetHook();
	}




}
#include "hooks/RenderSystemHook.h"
#include "hooks/BedRendererHook.h"
#include "hooks/ClientPacketListenerHook.h"
#include "hooks/LevelHook.h"
#include "hooks/PlayerHook.h"
#include "hooks/ConnectionHook.h"
#include "hooks/ChatScreenHook.h"
#include "hooks/EntityHook.h"
#include "hooks/LivingEntityHook.h"
#include "hooks/MinecraftHook.h"
#include "hooks/LocalPlayerHook.h"
void HookManager::setup()
{
	JavaHook::JVM::Init(JNI::get_env());

	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
		hook_invoke_compiler_on_method();

	hooks.push_back(std::make_shared<GameRendererHook>());
	//hooks.push_back(std::make_shared<ClientPacketListenerHook>());
	//hooks.push_back(std::make_shared<LevelHook>());
	//hooks.push_back(std::make_shared<BedRendererHook>());
	hooks.push_back(std::make_shared<PlayerHook>());
	hooks.push_back(std::make_shared<ChatScreenHook>());
	//hooks.push_back(std::make_shared<LivingEntityHook>());
	//hooks.push_back(std::make_shared<EntityHook>());	
	hooks.push_back(std::make_shared<ConnectionHook>());
	hooks.push_back(std::make_shared<LocalPlayerHook>());
	//hooks.push_back(std::make_shared<MinecraftHook>());

}

void HookManager::handle()
{
	for (auto& hook : hooks)
	{
		hook->hook(HookManagerData{ methods_being_hooked,  methodes_dont_compile,klasses_dont_compile });
	}


}