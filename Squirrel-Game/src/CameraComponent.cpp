#include "Components/CameraComponent.h"

CameraComponent::CameraComponent()
{
	updateProjection();
	updateView();
}

void CameraComponent::BeginPlay()
{

}

void CameraComponent::Update()
{
	cameraDesc->viewPos = getComponent<TransformComponent*>("transformComponent")->getTransform();
	cameraDesc->viewProjection = getViewProjection();
}

void CameraComponent::setup()
{
}

void CameraComponent::updateProjection()
{
	m_AspectRatio = m_ViewportWidth / m_ViewportHeight;
	m_Projection = glm::perspective(glm::radians(m_FOV), m_AspectRatio, m_NearClip, m_FarClip);
}

void CameraComponent::updateView()
{
	// m_Yaw = m_Pitch = 0.0f; // Lock the camera's rotation
	m_Position = calculatePosition();

	glm::quat orientation = getOrientation();
	m_ViewMatrix = glm::translate(glm::mat4(1.0f), m_Position) * glm::toMat4(orientation);
	m_ViewMatrix = glm::inverse(m_ViewMatrix);
}

glm::vec3 CameraComponent::getUpDirection() const
{
	return glm::rotate(getOrientation(), glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::vec3 CameraComponent::getRightDirection() const
{
	return glm::rotate(getOrientation(), glm::vec3(1.0f, 0.0f, 0.0f));
}

glm::vec3 CameraComponent::getForwardDirection() const
{
	return glm::rotate(getOrientation(), glm::vec3(0.0f, 0.0f, -1.0f));
}

glm::vec3 CameraComponent::calculatePosition() const
{
	return m_FocalPoint - getForwardDirection() * m_Distance;
}

glm::quat CameraComponent::getOrientation() const
{
	return glm::quat(glm::vec3(-m_Pitch, -m_Yaw, 0.0f));
}