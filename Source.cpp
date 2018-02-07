#include "Window.h"
#include "ShaderManager.h"
#include "Mesh.h"

int main()
{
	Window window(1024, 768, "Rendering!");
	ShaderManager shaderMgr("./shaders/basicShader");
	std::vector<Vertex> vertecies = { Vertex(-0.5f, -0.5f, 0.f), Vertex(0.f, 0.5f, 0.f), Vertex(0.5f, -0.5f, 0.f) };

	Mesh mesh(vertecies);

	while (window.isActive())
	{
		window.Clear(0,0,0,0);
		shaderMgr.Bind();
		mesh.Draw();
		window.PollEvents();
		

	}

	return 0;
}