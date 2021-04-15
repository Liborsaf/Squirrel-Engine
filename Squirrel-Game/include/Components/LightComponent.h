#pragma once
#include "Macros.h"
#include <iostream>
#include "../../../Squirrel-Engine/include/ActorComponent.h"
#include "../../Squirrel-Engine/include/InterfaceFactory.h"
#include "../../Squirrel-Engine/include/LightDrawCall.h"
#include "include/Components/TransformComponent.h"

SR_COMPONENT()
class LightComponent : public Squirrel::ActorComponent
{
private:
	int shaderID;
private:
	inline int getShaderID() { return shaderID; }
public:
	SR_VAR_START()
	glm::vec3 color;
	SR_VAR_END()

public:
	LightComponent();
	void BeginPlay() override;
	void Update() override;
	void setup() override;

	void setColor(float r, float g, float b);
};
SR_COMPONENT()