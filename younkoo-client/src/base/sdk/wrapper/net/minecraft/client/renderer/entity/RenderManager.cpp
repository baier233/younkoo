#include "RenderManager.h"
#include "wrapper/versions/1_12_2/net/minecraft/client/renderer/entity/RenderManager.h"
#include "wrapper/versions/1_8_9/net/minecraft/client/renderer/entity/RenderManager.h"
Math::Vector3D Wrapper::RenderManager::getRenderPosition()
{

	if (Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		V1_12_2::RenderManager renderManager = this->getObject();
		return Math::Vector3D(renderManager.renderPosX.get(), renderManager.renderPosY.get(), renderManager.renderPosZ.get());
	}
	else if (Younkoo::get().info.major == MajorVersion::MAJOR_189)
	{
		V1_8_9::RenderManager renderManager = this->getObject();
		return Math::Vector3D(renderManager.renderPosX.get(), renderManager.renderPosY.get(), renderManager.renderPosZ.get());
	}


	return Math::Vector3D();
}
