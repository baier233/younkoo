#pragma once

#include <SDK.hpp>
BEGIN_1_12_2
BEGIN_KLASS_DEF(AxisAlignedBB, return SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/AxisAlignedBB"))
JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/AxisAlignedBB"), "minX")
)> minX{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/AxisAlignedBB"), "minY")
)> minY{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/AxisAlignedBB"), "minZ")
)> minZ{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/AxisAlignedBB"), "maxX")
)> maxX{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/AxisAlignedBB"), "maxY")
)> maxY{ *this };/* D */

JNI::Field<jdouble, JNI::NOT_STATIC, DECLARE_NAME(
	return SRGParser::get().getObfuscatedFieldName(SRGParser::get().getObfuscatedClassName("net/minecraft/util/math/AxisAlignedBB"), "maxZ")
)> maxZ{ *this };/* D */

inline Math::Box<double> toBox() {
	return Math::Box<double>{
		this->minX.get(), this->minY.get(), this->minZ.get(),
			this->maxX.get(), this->maxY.get(), this->maxZ.get()
	};
}

END_KLASS_DEF();
END_1_12_2