#pragma once

#include "Vertex_t.h"

#include <glm/gtx/transform.hpp>

class Camera
{
public:
	Camera(const Vertex3& pos, float fov, float aspect, float zNear, float zFar);
	~Camera();

	glm::mat4 GetViewProjection() const;

	// not copyable


private:
	Vertex3 mPos;
	Vertex3 mForward;
	Vertex3 mUp;
	glm::mat4 mProjection;
};

