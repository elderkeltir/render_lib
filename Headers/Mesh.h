#pragma once

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Vertex
{
public:
	Vertex(const glm::vec3& pos) : pos(pos)	{}
	Vertex(float x, float y, float z) : pos(glm::vec3(x, y, z)) {}
	glm::vec3* GetPos() { return &pos; }
private:
	glm::vec3 pos;
};

class Mesh
{
public:
	Mesh(const std::vector<Vertex>& vertecies);
	~Mesh();

	void Draw();

	// not copybale
	Mesh(const Mesh&) = delete;
	Mesh& operator=(Mesh) = delete;
private:
	enum
	{
		POSITION_VB,

		BUFFER_NUM
	};

	GLuint mVertexArrayObject;
	GLuint mVertexArrayBuffers[BUFFER_NUM];
	size_t mDrawCount;
};

