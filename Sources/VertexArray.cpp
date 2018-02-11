#include "VertexArray.h"



VertexArray::VertexArray()
{
	// initialize vertexArrayObj
	glGenVertexArrays(1, &mVertexArrayObject);
	glBindVertexArray(mVertexArrayObject);

	// generate buffers
	glGenBuffers(BUFFER_NUM, mVertexArrayBuffers);
	
	glBindVertexArray(0);
}


VertexArray::~VertexArray()
{
	glDeleteBuffers(BUFFER_NUM, mVertexArrayBuffers);
	glDeleteVertexArrays(1, &mVertexArrayObject);
}


void VertexArray::BindVertexCoords(const std::vector<Vertex3> &vertexCoords)
{
	glBindVertexArray(mVertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, mVertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, vertexCoords.size() * sizeof(vertexCoords.front()), vertexCoords.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glBindVertexArray(0);
}

void VertexArray::BindTextureCoords(const std::vector<Vertex2> &TextureCoords)
{
	glBindVertexArray(mVertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, mVertexArrayBuffers[TEXCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(TextureCoords.front()) * TextureCoords.size(), &TextureCoords.front(), GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
	glBindVertexArray(0);
}
