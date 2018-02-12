#include "Camera.h"

#include <glm/glm.hpp>


Camera::Camera(const Vertex3& pos, float fov, float aspect, float zNear, float zFar) :
	mPos(pos),
	mForward(glm::vec3(0.0f, 0.0f, 1.0f)),
	mUp(glm::vec3(0.0f, 1.0f, 0.0f)),
	mProjection(glm::perspective(fov, aspect, zNear, zFar))
{
}


Camera::~Camera()
{
}


glm::mat4 Camera::GetViewProjection() const
{
	return mProjection * glm::lookAt(mPos.GetGLM(), mPos.GetGLM() + mForward.GetGLM(), mUp.GetGLM());
}