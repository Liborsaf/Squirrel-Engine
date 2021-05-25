#pragma once
#include "LightObject.h"

class PointLight : public LightObject
{
private:

public:
	PointLight(float lightIntensity, glm::vec3& lightColour, float attenuationRadius, glm::vec3& pos);
	PointLight(glm::vec3& pos);
	~PointLight();
	virtual void setupUniforms(Shader* shader, int currentLightIndex) override;
	
private:
	glm::vec3 m_Position;
	float m_AttenuationRadius;
};