#include "RuntimeManager.h"
#include "InterfaceFactory.h"
#include <dsound.h>


RuntimeManager::RuntimeManager()
{
}

RuntimeManager& RuntimeManager::getInstance()
{
	static RuntimeManager instance;
	return instance;
}

void RuntimeManager::engineStartup()
{
	std::cout << "Engine is Loading" << std::endl;
   IDirectSound8* m_pDS = NULL;
    InterfaceFactory::getInstance().getAUInterface().startAudioEngine();
	//Interface Initialization
	getInterface<RD_Interface>().startRenderEngine();
	getInterface<RM_Interface>().loadAssetMT();
}

void RuntimeManager::engineShutdown()
{
	std::cout << "Shutdown" << std::endl;

	// Memory Deallocation

	// Export Log History
}
