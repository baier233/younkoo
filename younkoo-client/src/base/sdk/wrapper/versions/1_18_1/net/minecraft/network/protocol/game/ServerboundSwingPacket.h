#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_18_1/net/minecraft/world/InteractionHand.h>
BEGIN_1_18_1


BEGIN_KLASS_DEF(ServerboundSwingPacket, return SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundSwingPacket"))
JNI::Field<InteractionHand, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/network/protocol/game/ServerboundSwingPacket"), "hand")
)> hand{ *this };/* Lnet/minecraft/world/InteractionHand; */
JNI::ConstructorMethod<InteractionHand> constructor_0{ *this };
inline static ServerboundSwingPacket create(InteractionHand hand) {
	return ServerboundSwingPacket::new_object(&ServerboundSwingPacket::constructor_0, hand);
}

END_KLASS_DEF();
END_1_18_1