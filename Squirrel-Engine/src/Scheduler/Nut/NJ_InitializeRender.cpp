#include "NJ_InitializeRender.h"

NJ_InitializeRender::NJ_InitializeRender()
{
}

void NJ_InitializeRender::mount()
{
}

void NJ_InitializeRender::unmount()
{
}

void NJ_InitializeRender::run()
{

	DynamicLightManager::bindLightingUniforms(getInterface<RM_Interface>().getShader(0));
	getInterface<RD_Interface>().render();
}
