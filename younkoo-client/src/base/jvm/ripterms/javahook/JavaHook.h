#pragma once
#include <JNI/jni.h>
#include <hotspot/java_hook.h>
#include <hotspot/classes/c_method.h>
inline constexpr int NO_COMPILE = JVM_ACC_NOT_C2_COMPILABLE | JVM_ACC_NOT_C1_COMPILABLE | JVM_ACC_NOT_C2_OSR_COMPILABLE | jvm_internal::JVM_ACC_QUEUED;
namespace Ripterms::JavaHook
{

	namespace HotSpot {
		struct frame
		{
			inline static int locals_offset = -56;
			void** get_locals();
			java_hotspot::method* get_method();
		};
	}
	void clean();

	template <typename T> inline void set_return_value(bool* cancel, T return_value)
	{
		*(T*)((void**)cancel + 8) = return_value; //see asm code to understand that
	}

	//param from left to right (arg0 beeing this for non static methods)
	template <typename T> inline T get_primitive_param_at(HotSpot::frame* frame, int index)
	{
		return *(T*)(frame->get_locals() - index);
	}

	inline jobject get_jobject_param_at(HotSpot::frame* frame, int index)
	{
		return (jobject)(frame->get_locals() - index);
	}

	typedef void(*i2i_detour_t)(HotSpot::frame* frame, java_hotspot::java_thread* thread, bool* cancel);
	class Midi2iHook
	{
	public:
		Midi2iHook(uint8_t* target, i2i_detour_t detour);
		~Midi2iHook();

		bool is_error = true;
	private:
		uint8_t* target = nullptr;
		uint8_t* allocated_assembly = nullptr;
	};

	bool hook(jmethodID methodID, i2i_detour_t detour);
}