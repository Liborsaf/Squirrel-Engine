﻿#pragma once
#include "Macros.h"
#include "../../Squirrel-Engine/include/Actor.h"
#include "Components/RenderComponent.h"
#include "Components/TransformComponent.h"
SR_ACTOR()
class Skeleton : public Squirrel::Actor
{
public:
	Skeleton();
	void BeginPlay() override;
	void Update() override;
	int health;
	int attackPower;
	SR_VAR_START()

	SR_VAR_END()

	SR_COMP_START()
	RenderComponent* renderComponent;
	TransformComponent* transformComponent;

	SR_COMP_END()
};


SR_ACTOR()