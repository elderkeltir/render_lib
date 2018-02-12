#include "Window.h"
#include "ShaderManager.h"
#include "Mesh.h"
#include "Texture.h"

int main()
{
	Window window(1024, 768, "Rendering!");
	ShaderManager shaderMgr("./shaders/basicShader");
	shaderMgr.Bind();

	std::vector<Vertex3> vertecies = { Vertex3(-1.0f, -1.0f, 0.f), Vertex3(0.f, 1.0f, 0.f), Vertex3(1.0f, -1.0f, 0.f) };
	std::vector<Vertex3> vertecies2 = { Vertex3(0.f, 1.0f, 0.f), Vertex3(1.0f, 1.0f, 0.f), Vertex3(1.0f, -1.0f, 0.f) };
	std::vector<Vertex3> vertecies3 = { Vertex3(-1.0f, -1.0f, 0.f), Vertex3(-1.0f, 1.0f, 0.f), Vertex3(0.f, 1.0f, 0.f) };
	std::vector<Vertex2> textureCoords = { Vertex2(0.0f, 1.0f - 0.0f), Vertex2(0.5f, 1.0f - 1.0f), Vertex2(1.0f, 1.0f - 0.0f) };
	Texture * texture = new Texture(".//resources//player.dds");


	Mesh mesh(vertecies, textureCoords, texture, shaderMgr.GetModelLocID());
	
	//Mesh mesh2(vertecies2, textureCoords, texture, shaderMgr.GetModelLocID());

	//Mesh mesh3(vertecies3, textureCoords, texture, shaderMgr.GetModelLocID());
	float counter = 0.0f;

	mesh.Scale(Vertex3(0.5f, 0.5f, 1));
	while (window.isActive())
	{
		window.Clear(0,0,0,0);
		mesh.Move(Vertex3(sin(counter), 0, 0));
		mesh.Rotate(Vertex3(0, 0, sin(counter)));
		//mesh.Scale(Vertex3(sin(counter), sin(counter), 1));
		mesh.Draw();
		//mesh2.Draw();
		//mesh3.Draw();
		window.PollEvents();

		counter += 0.01f;
	}

	return 0;
}