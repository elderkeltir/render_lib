#include "Mesh.h"



Mesh::Mesh(const std::vector<Vertex3>& verteciesPosition, const std::vector<Vertex2>& textureCoords, Texture* texture) :
	mDrawCount(verteciesPosition.size()),
	mTexture(texture)
{
	// create VertexArrayBuffer
	mVerBuffer = std::make_unique<VertexArray>();
	mVerBuffer->BindVertexCoords(verteciesPosition);
	mVerBuffer->BindTextureCoords(textureCoords);
}


Mesh::~Mesh()
{
}

void Mesh::Draw()
{
	//bind texture
	mTexture->Bind(true);

	glBindVertexArray(mVerBuffer->GetVertexArrayObject());

	// draw triangles
	glDrawArrays(GL_TRIANGLES, 0, static_cast<int>(mDrawCount));

	glBindVertexArray(0);

	//unbind texture
	mTexture->Bind(false);
}
