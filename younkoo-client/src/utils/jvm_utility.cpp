#include "jvm_utility.h"

auto younkoo::jvm_utility::get_jni_tools(JNIEnv* env) -> std::tuple<jvmtiEnv*, JavaVM*>
{
	jvmtiEnv* jti = nullptr;
	JavaVM* jvm = nullptr;
	env->GetJavaVM(&jvm);
	jvm->GetEnv(reinterpret_cast<void**>(&jti), JVMTI_VERSION_1_2);
	return std::make_tuple(jti, jvm);
}

auto younkoo::jvm_utility::get_thread_classloader(const std::string_view& thread_name) -> jobject
{
	const auto jni_env = JNI::get_env();
	/* TODO: save to any class? */
	const auto [jti, jvm] = get_jni_tools(jni_env);
	jthread* thread = nullptr;
	jint thread_count;
	jti->GetAllThreads(&thread_count, &thread);
	jvmtiThreadInfo info;
	for (int i = 0; i < thread_count; i++)
	{
		jti->GetThreadInfo(thread[i], &info);
		if (thread_name == info.name)
		{
			return info.context_class_loader;
		}
	}
	return nullptr;
}
