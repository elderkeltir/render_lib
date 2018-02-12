#include "Transform.h"



Transform::Transform(const Vertex3 &pos, const Vertex3 &rot, const Vertex3 &scale) :
	mPos(pos),
	mRot(rot),
	mScale(scale)
{

}


Transform::~Transform()
{
}

const glm::mat4& Transform::GetModel()
{
	glm::mat4 posMat = glm::translate(mPos.GetGLM());
	glm::mat4 scaleMat = glm::scale(mScale.GetGLM());
	glm::mat4 rotX = glm::rotate(mRot.GetGLM().x, glm::vec3(1.0, 0.0, 0.0));
	glm::mat4 rotY = glm::rotate(mRot.GetGLM().y, glm::vec3(0.0, 1.0, 0.0));
	glm::mat4 rotZ = glm::rotate(mRot.GetGLM().z, glm::vec3(0.0, 0.0, 1.0));
	glm::mat4 rotMat = rotX * rotY * rotZ;

	mModel =  posMat * rotMat * scaleMat;

	return mModel;
}
