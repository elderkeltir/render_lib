#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "Vertex_t.h"

class Transform
{
public:
	Transform(const Vertex3 &pos = Vertex3(), const Vertex3 &rot = Vertex3(), const Vertex3 &scale = Vertex3(1.0f, 1.0f, 1.0f));
	~Transform();

	const glm::mat4& GetModel();

	Vertex3* GetPos() { return &mPos; }
	Vertex3* GetRot() { return &mRot; }
	Vertex3* GetScale() { return &mScale; }

	void SetPos(const Vertex3& pos) { this->mPos = pos; }
	void SetRot(const Vertex3& rot) { this->mRot = rot; }
	void SetScale(const Vertex3& scale) { this->mScale = scale; }

	// not copyable
	Transform(const Transform&) = delete;
	Transform& operator=(Transform) = delete;
private:
	Vertex3 mPos;
	Vertex3 mRot;
	Vertex3 mScale;
	glm::mat4 mModel;
};