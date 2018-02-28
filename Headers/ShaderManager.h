#pragma once

#include <string>
#include <array>

#include <GL\glew.h>

class ShaderManager
{
public:
	ShaderManager(const std::string& filePath);
	~ShaderManager();

	void Bind() const;
	GLuint GetModelLocID() const { return mModelLoc; }

	// not copyable
	ShaderManager(const ShaderManager&) = delete;
	ShaderManager& operator=(ShaderManager) = delete;
private:
	enum ShaderType 
	{
		VERTEX_SHADER, 
		FRAGMENT_SHADER,

		SHADER_NUM
	};
	std::string mFilePath;
	GLuint mProgram;
	std::array<GLuint,SHADER_NUM> mShaders;
	GLuint mModelLoc;

	std::string LoadShader(ShaderType type) const;
	void CreateShader(ShaderType type, const std::string& shaderSource);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
};

