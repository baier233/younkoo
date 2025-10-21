#pragma once

#include <SDK.hpp>
#include "jdk/Classes.h"

BEGIN_1_18_1

BEGIN_KLASS_DEF(ChatScreen, return SRGParser::get().getObfuscatedClassName("net/minecraft/client/gui/screens/ChatScreen"))
JNI::Method<void, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedMethodName("net/minecraft/client/gui/screens/Screen", "sendMessage", "(Ljava/lang/String;Z)V").first
), String, jboolean> sendMessage{ *this };//net/minecraft/client/gui/screens/Screen/sendMessage (Ljava/lang/String;Z)V
END_KLASS_DEF();

END_1_18_1