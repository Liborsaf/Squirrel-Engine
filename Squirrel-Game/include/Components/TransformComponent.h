#pragma once
#include "Actor.h"
#include "Components/RenderComponent.h"

SR_COMPONENT()

class TransformComponent : public ActorComponent
{
struct Transform {
	vec3 position;
	vec3 rotation;
	vec3 scale;
};
private:
	mat4 transformMat;
	quat orientation;
  Transform transform;
public:

	vec3 forward = vec3(0, 0, -1);
	vec3 up = vec3(0, 1, 0);
	vec3 right = vec3(1, 0, 0);
	SR_VAR_START()
	
	SR_VAR_END()
public:
	TransformComponent();
	void BeginPlay() override;
	void Update() override;
	void setup() override;

	void translate(const vec3& direction);
	void translate(float x, float y, float z);
	void rotate(const vec3& eulers);
	void rotate(float x, float y, float z);

	vec3& getPosition();
	vec3& getRotation();
	vec3& getScale();
	void setTransform(float x, float y, float z);
	void setRotation(float x, float y, float z);
	void setScale(float x, float y, float z);
private:
	quat getOrientation();
};

SR_COMPONENT()
