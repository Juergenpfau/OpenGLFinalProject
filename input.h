#pragma once

#include <unordered_map>
#include "window.hpp"


class Input {
public:

	Input(GLFWwindow* w);

	void processInput();

	bool isKeyPressed(int keyID);
	bool isKeyReleased(int keyID);
	bool isKeyDown(int keyID);
	bool wasKeyDown(int keyID);

	glm::vec2 getMousePosition();
	glm::vec2 getPreviousMousePosition();

	std::unordered_map<int, bool> previousKeymap;
	glm::vec2 previousMousePosition;

	GLFWwindow* window = nullptr;

};