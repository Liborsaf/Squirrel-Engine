#include "NJ_InitializeRender.h"



Squirrel::NJ_InitializeRender::NJ_InitializeRender()
{
}

void Squirrel::NJ_InitializeRender::mount()
{
}

void Squirrel::NJ_InitializeRender::unmount()
{
}

void Squirrel::NJ_InitializeRender::run()
{
	InterfaceFactory::getInstance().getRDInterface().render();
}