#pragma once

#include <vector>
#include <memory>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "VertexArray.h"
#include "Texture.h"
#include "Transform.h"

class Mesh
{
	friend class Texture;
public:
	Mesh(const std::vector<Vertex3>& verteciesPosition, const std::vector<Vertex2>& textureCoords, Texture* texture, GLuint programID);
	~Mesh();

	void Draw();
	void Move(const Vertex3 &pos);
	void Rotate(const Vertex3 &pos);
	void Scale(const Vertex3 &pos);
	Transform& GetTransform() { return *mTransform; }

	// not copybale
	Mesh(const Mesh&) = delete;
	Mesh& operator=(Mesh) = delete;
private:
	size_t mDrawCount;
	Texture* mTexture;
	std::unique_ptr<VertexArray> mVerBuffer;
	std::unique_ptr<Transform> mTransform;
	GLuint mProgram;
};

