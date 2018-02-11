#pragma once

#include <string>

#include <GL/glew.h>

#include "Vertex_t.h"

class Texture
{
public:
	Texture(const std::string &filePath);
	~Texture();

	void Bind(bool flag);

	// not copyable
	Texture(Texture&) = delete;
	Texture& operator=(Texture) = delete;
private:
	GLuint m_texture;
};

