#pragma once
#include <JVM.hpp>
#include <SDK.hpp>
#include <hotspot/java_hook.h>
#include <ripterms/javahook/JavaHook.h>
#include <hotspot/break/byte_code_info.h>
#include <map>
namespace HookUtils {
	inline std::map<java_hotspot::java_thread*, JavaThreadState> o_thread_map;
	inline std::vector<java_hotspot::instance_klass*> classes_been_transformed;
	inline java_hotspot::method* GenericResolve(jmethodID methodID) {
		java_hotspot::method* method = *(java_hotspot::method**)methodID;

		method->set_dont_inline(true);
		auto flags = (int*)method->get_access_flags();
		*flags |= (NO_COMPILE);

		jclass owner = nullptr;
		JVM::get().jvmti->GetMethodDeclaringClass(methodID, &owner);
		auto klass = java_hotspot::instance_klass::get_instance_class(owner);
		if (std::find(classes_been_transformed.begin(), classes_been_transformed.end(), klass) != classes_been_transformed.end())
		{
			goto end;
		}
		JVM::get().jvmti->RetransformClasses(1, &owner); //small trick to delete any already compiled / inlined code

		klass = java_hotspot::instance_klass::get_instance_class(owner);
		if (klass)
		{
			LOG("transformed klass :" << klass->get_name()->to_string());
			classes_been_transformed.push_back(klass);
		}
	end:
		JVM::get().Env->DeleteLocalRef(owner);
		method = *(java_hotspot::method**)methodID;


		method->set_dont_inline(true);
		flags = (int*)method->get_access_flags();
		*flags |= (NO_COMPILE);

		return method;
	}
}