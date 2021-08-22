#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>

class Window {
public:

	Window();
	void close();
	void swapBuffers();
	void clearWindow();

	GLFWwindow* windowPtr;


};