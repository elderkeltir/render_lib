#include "ShaderManager.h"

#include <fstream>
#include <iostream>
#include <string>

ShaderManager::ShaderManager(const std::string & filePath) :
	mFilePath(filePath)
{
	CreateShader(ShaderType::VERTEX_SHADER, LoadShader(ShaderType::VERTEX_SHADER).c_str());
	CreateShader(ShaderType::FRAGMENT_SHADER, LoadShader(ShaderType::FRAGMENT_SHADER).c_str());


	// create shader program and bind shaders to it
	mProgram = glCreateProgram();
	for (auto shader : mShaders)
		glAttachShader(mProgram, shader);
	
	glLinkProgram(mProgram);
	CheckShaderError(mProgram, GL_LINK_STATUS, true, "Error linking shader program");

	glValidateProgram(mProgram);
	CheckShaderError(mProgram, GL_LINK_STATUS, true, "Invalid shader program");

	mModelLoc = glGetUniformLocation(mProgram, "MVP");
}

ShaderManager::~ShaderManager()
{
	for (auto shader : mShaders)
	{
		glDetachShader(mProgram, shader);
		glDeleteShader(shader);
	}

	glDeleteProgram(mProgram);
}

void ShaderManager::Bind() const
{
	glUseProgram(mProgram);
}

std::string ShaderManager::LoadShader(ShaderType type) const
{
	std::string ext =
		type == ShaderType::VERTEX_SHADER ? ".glvs" : ".glfs";

	std::string fullPath = mFilePath + ext;

	std::string shaderCode;
	std::ifstream shaderStream(fullPath, std::ios::in);
	if (shaderStream.is_open())
	{
		std::string line("");
		while (getline(shaderStream, line))
			shaderCode += "\n" + line;
		shaderStream.close();
	}

	return shaderCode;
}

void ShaderManager::CreateShader(ShaderType type, const std::string& shaderSource)
{
	GLenum shType =
		type == ShaderType::VERTEX_SHADER ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;

	GLuint shader = glCreateShader(shType);

	char const * sourcePointer = shaderSource.c_str();
	glShaderSource(shader, 1, &sourcePointer, NULL);
	glCompileShader(shader);

	mShaders.at(static_cast<size_t>(type)) = shader;

	CheckShaderError(mShaders.at(static_cast<size_t>(type)), GL_COMPILE_STATUS, false, "Error compiling shader!");
}

void ShaderManager::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	}
}