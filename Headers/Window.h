#pragma once

#include <string>

#include <GL/glew.h>
#include <glfw3.h>


class Window
{
public:
	Window(size_t width, size_t height, const std::string& title);
	~Window();

	void Clear(float r, float g, float b, float a) const;
	bool isActive() const;

	void PollEvents() const;

	// not copyable
	Window(const Window&) = delete;
	Window& operator=(const Window) = delete;

private:
	size_t mWidth;
	size_t mHeight;
	std::string mTitle;
	GLFWwindow* mWindow;
};

