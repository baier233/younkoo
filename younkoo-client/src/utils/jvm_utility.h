#pragma once
#include <string_view>
#include "jni/jvmti.h"

#include "jni/types/Array.hpp"

namespace younkoo::jvm_utility
{
    auto get_jni_tools(JNIEnv* env) -> std::tuple<jvmtiEnv*, JavaVM*>;

    auto get_thread_classloader(const std::string_view& thread_name) -> jobject;
}
