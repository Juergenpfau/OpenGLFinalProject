#include "window.hpp"
#include <iostream>

Window::Window(){
	glfwInit();

	glfwWindowHint(GLFW_SAMPLES, 4);

	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	windowPtr = glfwCreateWindow(1280, 720, "Desk", NULL, NULL);

	glfwMakeContextCurrent(windowPtr);
	
	glewInit();

	glfwSetInputMode(windowPtr, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glEnable(GL_MULTISAMPLE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glClearColor(0.0f, 0.5f, 0.8, 1.0f);

	glfwSwapInterval(1);
}

void Window::clearWindow(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::swapBuffers(){
	glfwSwapBuffers(windowPtr);
}

void Window::close(){
	glfwTerminate();
	glfwDestroyWindow(windowPtr);
}