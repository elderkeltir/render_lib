#include "Window.h"

#include <iostream>



Window::Window(size_t width, size_t height, const std::string & title, const std::array<float, 4> &clearColor) :
	mWidth(width),
	mHeight(height),
	mTitle(title)
{
	// Initialise GLFW
	if (!glfwInit())
	{
		std::cerr << "Failed to intialize GLFW" << std::endl;
		return;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	mWindow = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), title.c_str(), NULL, NULL);
	if (mWindow == NULL) {
		std::cerr << "Failed to create window" << std::endl;
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(mWindow);

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to intialize GLEW" << std::endl;
		glfwTerminate();
		return;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(mWindow, GLFW_STICKY_KEYS, GL_TRUE);

	// Set BG color
	glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
}

Window::~Window()
{
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}

void Window::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Window::isActive() const
{
	return glfwGetKey(mWindow, GLFW_KEY_ESCAPE) != GLFW_PRESS 
			&& glfwWindowShouldClose(mWindow) == 0;
}

void Window::PollEvents() const
{
	glfwPollEvents();
}

void Window::SwapBuffers() const
{
	glfwSwapBuffers(mWindow);
}

bool Window::CheckKeyStatus(KeyCode code, KeyStatus status)
{
	return glfwGetKey(mWindow, code) == status;
}
