﻿#include "java_hook.h"



/* JVM exports some symbols that we need to use */
extern "C" JNIIMPORT VMStructEntry * gHotSpotVMStructs;
extern "C" JNIIMPORT VMTypeEntry * gHotSpotVMTypes;
extern "C" JNIIMPORT VMIntConstantEntry * gHotSpotVMIntConstants;
extern "C" JNIIMPORT VMLongConstantEntry * gHotSpotVMLongConstants;

#include <log/LOG.h>
static auto InitGlobalOffsets() -> void {
	/* .\hotspot\src\share\vm\classfile\javaClasses.hpp -> class java_lang_Class : AllStatic */
	const auto java_lang_Class = JVMWrappers::find_type_fields("java_lang_Class");
	if (!java_lang_Class.has_value()) {
		LOG("Failed to find java_lang_Class");
	}

	/* java_lang_Class -> _klass_offset */
	global_offsets::klass_offset = *static_cast<jint*>(java_lang_Class.value().get()["_klass_offset"]->address);
}



/* Scan bytecode offset */
static auto ScanByteCodeOffset(JNIEnv* env) -> void {
	/* Any class */
	const auto integer_klass = env->FindClass("java/lang/Integer");

	if (!integer_klass) {
		LOG("Failed to find java/lang/Integer");
	}
	/* Any method */
	const auto integer_hash_code = env->GetMethodID(integer_klass, "shortValue", "()S");
	if (!integer_hash_code) {
		LOG("Failed to find java/lang/Integer::shortValue");
	}
	/* Get method */
	const auto hash_method = *reinterpret_cast<java_hotspot::method**>(integer_hash_code);
	if (!hash_method) {
		LOG("Failed to find java/lang/Integer::shortValue");
	}
	java_hotspot::bytecode_start_offset = java_hotspot::const_method::get_const_method_length();
	LOG("Bytecode start offset: " << java_hotspot::bytecode_start_offset);

	/* Interception address */
	java_hotspot::interpreter_entry* interpreter_entry = hash_method->get_i2i_entry();
	if (const auto interception_address = interpreter_entry->get_interception_address(); !interception_address) {
		LOG("Failed to find interception address");
	}
	LOG("Interception address: " << reinterpret_cast<void*>(interpreter_entry->get_interception_address()));

	/* Get dispatch table */
	const uintptr_t dispatch_table = *reinterpret_cast<uintptr_t*>(interpreter_entry->get_interception_address() + 2);
	if (!dispatch_table) {
		LOG("Failed to find dispatch table");
	}
	LOG("Dispatch table: " << reinterpret_cast<void*>(dispatch_table));

	/* Get breakpoint method */
	const uintptr_t breakpoint_method = *reinterpret_cast<uintptr_t*>(dispatch_table + static_cast<uint8_t>(java_runtime::bytecodes::_breakpoint) * 8);
	const uintptr_t aload_method = *reinterpret_cast<uintptr_t*>(dispatch_table + static_cast<uint8_t>(java_runtime::bytecodes::_aload) * 8);
	if (!breakpoint_method) {
		LOG("Failed to find breakpoint method");
	}
	LOG("Breakpoint method: " << reinterpret_cast<void*>(breakpoint_method));
	LOG("Aload method: " << reinterpret_cast<void*>(aload_method));
	/* Get VM calls */

	const std::vector<void*> vm_calls = vm_helper::find_vm_calls(reinterpret_cast<PVOID>(breakpoint_method));
	if (vm_calls.size() < 2) {
		LOG("Failed to find VM calls");
	}
	LOG("VM calls: " << vm_calls.size());

	// Hook the runtime methods
	void* runtime_get_original_bytecode = vm_calls[0];
	void* runtime_breakpoint_method = vm_calls[1];
	LOG("Runtime get original bytecode: " << runtime_get_original_bytecode);
	LOG("Runtime breakpoint method: " << runtime_breakpoint_method);
	jvm_break_points::breakpoint_hook.InitHook(runtime_breakpoint_method, jvm_break_points::breakpoint_callback);
	jvm_break_points::original_bytecode_hook.InitHook(runtime_get_original_bytecode,
		jvm_break_points::original_bytecode_handler);
	jvm_break_points::breakpoint_hook.SetHook();
	jvm_break_points::original_bytecode_hook.SetHook();
}




bool JavaHook::JVM::Init(JNIEnv* env, bool breakpoint)
{
	//const auto interop = std::make_unique<java_interop>(env);
	JVMWrappers::init(gHotSpotVMStructs, gHotSpotVMTypes, gHotSpotVMIntConstants, gHotSpotVMLongConstants);
	InitGlobalOffsets();
	if (breakpoint)
	{
		ScanByteCodeOffset(env);
	}
	return false;
}

bool JavaHook::JVM::clean()
{
	jvm_break_points::breakpoint_hook.RemoveHook();
	jvm_break_points::original_bytecode_hook.RemoveHook();
	return true;
}
