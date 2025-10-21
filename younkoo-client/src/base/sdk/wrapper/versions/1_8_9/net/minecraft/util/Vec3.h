#pragma once

#include <SDK.hpp>
#include <utils/types/Maths.hpp>
BEGIN_1_8_9
BEGIN_KLASS_DEF(Vec3, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/Vec3"))
JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/Vec3"), "xCoord")
)> xCoord{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/Vec3"), "yCoord")
)> yCoord{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/Vec3"), "zCoord")
)> zCoord{ *this };/* D */
JNI::ConstructorMethod<jdouble, jdouble, jdouble> constructor_0{ *this };

Math::Vector3D toVector3() {
	return Math::Vector3D(xCoord.get(), yCoord.get(), zCoord.get());
}
static inline Vec3 fromVector3(Math::Vector3D vec) {
	static auto id = Vec3::static_obj().constructor_0.init();
	return Vec3::new_object(&Vec3::constructor_0, id, (jdouble)vec.x, (jdouble)vec.y, (jdouble)vec.z);
}
END_KLASS_DEF();
END_1_8_9
