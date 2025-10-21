#include "Vec3i.h"

#include <wrapper/versions/1_18_1/net/minecraft/core/Vec3i.h>
#include <wrapper/versions/1_20_1/net/minecraft/core/Vec3i.h>
#include <wrapper/versions/1_8_9/net/minecraft/util/Vec3i.h>
#include <wrapper/versions/1_12_2/net/minecraft/util/math/Vec3i.h>

int Wrapper::Vec3i::getX()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Vec3i vec3 = this->getObject();
		return vec3.x.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Vec3i vec3 = this->getObject();
		return vec3.x.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::Vec3i vec3 = this->getObject();
		return vec3.x.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Vec3i vec3 = this->getObject();
		return vec3.x.get();
	}
	return 0;
}

int Wrapper::Vec3i::getY()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Vec3i vec3 = this->getObject();
		return vec3.y.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Vec3i vec3 = this->getObject();
		return vec3.y.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::Vec3i vec3 = this->getObject();
		return vec3.y.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Vec3i vec3 = this->getObject();
		return vec3.y.get();
	}
	return 0;
}

int Wrapper::Vec3i::getZ()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Vec3i vec3 = this->getObject();
		return vec3.z.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Vec3i vec3 = this->getObject();
		return vec3.z.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::Vec3i vec3 = this->getObject();
		return vec3.z.get();
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Vec3i vec3 = this->getObject();
		return vec3.z.get();
	}
	return 0;
}

Math::Vector3i Wrapper::Vec3i::toVector()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_1181)
	{
		V1_18_1::Vec3i vec3 = this->getObject();
		return Math::Vector3i{ vec3.x.get(),vec3.y.get(),vec3.z.get() };
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_1201)
	{
		V1_20_1::Vec3i vec3 = this->getObject();
		return Math::Vector3i{ vec3.x.get(),vec3.y.get(),vec3.z.get() };
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::Vec3i vec3 = this->getObject();
		return Math::Vector3i{ vec3.x.get(),vec3.y.get(),vec3.z.get() };
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_112)
	{
		V1_12_2::Vec3i vec3 = this->getObject();
		return Math::Vector3i{ vec3.x.get(),vec3.y.get(),vec3.z.get() };
	}
	return Math::Vector3i{};
}
