#pragma once
#include <SDK.hpp>
#include <wrapper/versions/1_12_2/net/minecraft/util/math/Vec3i.h>
#include <wrapper/versions/1_12_2/net/minecraft/util/math/Vec3d.h>
BEGIN_1_12_2
BEGIN_KLASS_DEF_EX(BlockPos, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/BlockPos"), Vec3i)

JNI::ConstructorMethod<Vec3d> constructor_3{ *this };

static inline BlockPos create(Math::Vector3D vec3) {
	return BlockPos::new_object(&BlockPos::constructor_3, Vec3d::fromVector3(vec3));
}

END_KLASS_DEF()
END_1_12_2