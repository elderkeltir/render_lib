#include "Window.h"
#include "ShaderManager.h"
#include "Mesh.h"
#include "Texture.h"

int main()
{
	Window window(1024, 768, "Rendering!");
	ShaderManager shaderMgr("./shaders/basicShader");
	
	std::vector<Vertex3> vertecies = { Vertex3(-1.0f, -1.0f, 0.f), Vertex3(0.f, 1.0f, 0.f), Vertex3(1.0f, -1.0f, 0.f) };
	std::vector<Vertex3> vertecies2 = { Vertex3(0.f, 1.0f, 0.f), Vertex3(1.0f, 1.0f, 0.f), Vertex3(1.0f, -1.0f, 0.f) };
	std::vector<Vertex3> vertecies3 = { Vertex3(-1.0f, -1.0f, 0.f), Vertex3(-1.0f, 1.0f, 0.f), Vertex3(0.f, 1.0f, 0.f) };
	std::vector<Vertex2> textureCoords = { Vertex2(0.0f, 1.0f - 0.0f), Vertex2(0.5f, 1.0f - 1.0f), Vertex2(1.0f, 1.0f - 0.0f) };
	Texture * texture = new Texture(".//resources//player.dds");


	Mesh mesh(vertecies, textureCoords, texture);
	
	Mesh mesh2(vertecies2, textureCoords, texture);

	Mesh mesh3(vertecies3, textureCoords, texture);

	while (window.isActive())
	{
		window.Clear(0,0,0,0);
		shaderMgr.Bind();
		mesh.Draw();
		mesh2.Draw();
		mesh3.Draw();
		window.PollEvents();
	}

	return 0;
}