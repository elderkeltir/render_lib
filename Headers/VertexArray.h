#pragma once

#include <vector>
#include <GL/glew.h>
#include <glm\glm.hpp>

#include "Vertex_t.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void BindVertexCoords(const std::vector<Vertex3> &vertexCoords);
	void BindTextureCoords(const std::vector<Vertex2> &TextureCoords);
	GLuint GetVertexArrayObject() const { return mVertexArrayObject; }

	// not copyable
	VertexArray(const VertexArray&) = delete;
	VertexArray& operator=(VertexArray) = delete;
private:
	enum
	{
		POSITION_VB,
		TEXCOORD_VB,

		BUFFER_NUM
	};

	GLuint mVertexArrayObject;
	GLuint mVertexArrayBuffers[BUFFER_NUM];
};

