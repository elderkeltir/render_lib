#include "Mesh.h"



Mesh::Mesh(const std::vector<Vertex>& vertecies) : mDrawCount(vertecies.size())
{
	glGenVertexArrays(1, &mVertexArrayObject);
	glBindVertexArray(mVertexArrayObject);
	
	glGenBuffers(BUFFER_NUM, mVertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, mVertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, mDrawCount * sizeof(vertecies.front()), vertecies.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}


Mesh::~Mesh()
{
	glDeleteBuffers(BUFFER_NUM, mVertexArrayBuffers);
	glDeleteVertexArrays(1, &mVertexArrayObject);
}

void Mesh::Draw()
{
	glBindVertexArray(mVertexArrayObject);

	// first attr buffer is vertecies
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, mVertexArrayBuffers[POSITION_VB]);
	glVertexAttribPointer(
		0,                  // 0 attr for shaders?
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // is normalized
		0,                  // step
		(void*)0            // shifting array in buffer
	);

	// draw triangle
	glDrawArrays(GL_TRIANGLES, 0, static_cast<int>(mDrawCount));

	glDisableVertexAttribArray(0);

	glBindVertexArray(0);

	
}
