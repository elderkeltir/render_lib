#pragma once

#include <vector>
#include <memory>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "VertexArray.h"
#include "Texture.h"

class Mesh
{
	friend class Texture;
public:
	Mesh(const std::vector<Vertex3>& verteciesPosition, const std::vector<Vertex2>& textureCoords, Texture* texture);
	~Mesh();

	void Draw();

	// not copybale
	Mesh(const Mesh&) = delete;
	Mesh& operator=(Mesh) = delete;
private:
	size_t mDrawCount;
	Texture* mTexture;
	std::unique_ptr<VertexArray> mVerBuffer;
};

