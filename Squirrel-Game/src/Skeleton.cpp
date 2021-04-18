﻿#include "Skeleton.h"


Skeleton::Skeleton()
{
	auto transformComponent = new TransformComponent();
	transformComponent->setParent(this);
	this->transformComponent = transformComponent;
	insertComponent("transformComponent", transformComponent);

	auto renderComponent = new RenderComponent();
	renderComponent->setParent(this);
	this->renderComponent = renderComponent;
	insertComponent("renderComponent", renderComponent);

	auto aiComponent = new AIComponent();
	aiComponent->setParent(this);
	this->aiComponent = aiComponent;
	insertComponent("aiComponent", aiComponent);
}

void Skeleton::BeginPlay()
{
	//audioComponent->play();
}

void Skeleton::Update()
{
	transformComponent->rotationY += 0.05;
}
