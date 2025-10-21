#pragma once
#include <wrapper/versions/1_8_9/net/minecraft/util/Vec3i.h>
#include <wrapper/versions/1_8_9/net/minecraft/util/Vec3.h>
#include <SDK.hpp>
BEGIN_1_8_9
BEGIN_KLASS_DEF_EX(BlockPos, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/BlockPos"), Vec3i)

JNI::ConstructorMethod<Vec3> constructor_3{ *this };
static inline BlockPos create(Vec3 vec3_obj) {
	return BlockPos::new_object(&BlockPos::constructor_3, vec3_obj);
}

static inline BlockPos create(Math::Vector3D vec3) {
	return BlockPos::new_object(&BlockPos::constructor_3, Vec3::fromVector3(vec3));
}
END_KLASS_DEF();
END_1_8_9
