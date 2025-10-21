#include "ActiveRenderInfo.h"
#include <wrapper/versions/1_12_2/net/minecraft/client/renderer/ActiveRenderInfo.h>
#include <wrapper/versions/1_8_9/net/minecraft/client/renderer/ActiveRenderInfo.h>
Math::Matrix Wrapper::ActiveRenderInfo::getModelViewMatrix()
{
	//TODO£º189
	if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::ActiveRenderInfo activeRenderInfo = this->getObject();
		return Math::Matrix(activeRenderInfo.MODELVIEW.get().GetMatrix());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::ActiveRenderInfo activeRenderInfo = this->getObject();
		return Math::Matrix(activeRenderInfo.MODELVIEW.get().GetMatrix());
	}
	return Math::Matrix();
}

Math::Matrix Wrapper::ActiveRenderInfo::getProjectionMatrix()
{
	if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::ActiveRenderInfo activeRenderInfo = this->getObject();
		return Math::Matrix(activeRenderInfo.PROJECTION.get().GetMatrix());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189) {
		V1_8_9::ActiveRenderInfo activeRenderInfo = this->getObject();
		return Math::Matrix(activeRenderInfo.PROJECTION.get().GetMatrix());
	}
	return Math::Matrix();
}
