#pragma once
#include <SDK.hpp>
BEGIN_1_12_2
BEGIN_KLASS_DEF(Vec3d, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/Vec3d"))
JNI::ConstructorMethod<jdouble, jdouble, jdouble> constructor_0{ *this };

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/Vec3d"), "x")
)> x{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/Vec3d"), "y")
)> y{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/Vec3d"), "z")
)> z{ *this };/* D */

Math::Vector3D toVector3() {
	return Math::Vector3D(x.get(), y.get(), z.get());
}
static inline Vec3d fromVector3(Math::Vector3D vec) {
	static auto id = Vec3d::static_obj().constructor_0.init();
	return Vec3d::new_object(&Vec3d::constructor_0, id, (jdouble)vec.x, (jdouble)vec.y, (jdouble)vec.z);
}
END_KLASS_DEF()
END_1_12_2