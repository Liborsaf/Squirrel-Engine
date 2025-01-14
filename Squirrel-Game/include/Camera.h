#pragma once
#include "Actor.h"
#include "Components/TransformComponent.h"
#include "Components/CameraComponent.h"
#include <Components/LightComponent.h>

SR_ACTOR()

class Camera : public Actor
{
public:
	Camera();
	void BeginPlay() override;
	void Update() override;
	SR_VAR_START()

	SR_VAR_END()

	SR_COMP_START()
	TransformComponent transformComponent;
	CameraComponent cameraComponent;
	LightComponent lightComponent;
	SR_COMP_END()
};

SR_ACTOR()
