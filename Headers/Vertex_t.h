#pragma once

#include <glm/glm.hpp>

template <class T>
class Vertex;

typedef Vertex<glm::vec3> Vertex3;
typedef Vertex<glm::vec2> Vertex2;

template <class T>
class Vertex
{
public:
	Vertex() : pos(T(0, 0, 0)) {}
	Vertex(const T& pos) : pos(pos) {}
	Vertex(float x, float y, float z ) : pos(T(x, y, z)) {}
	Vertex(float x, float y) : pos(T(x, y)) {}
	T& GetGLM() { return pos; }
private:
	T pos;
};

