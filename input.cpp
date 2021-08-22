#include "input.h"
#include <iostream>


glm::vec2 mousePosition;
std::unordered_map<int, bool> keymap;

void keyPressed(int _keyID){
	keymap[_keyID] = true;
}

void keyReleased(int _keyID){
	keymap[_keyID] = false;
}

void keyPressed(GLFWwindow* window, int _key, int _scancode, int _action, int _mods){
	if(_action == GLFW_PRESS){
		keyPressed(_key);
	}else if(_action == GLFW_RELEASE){
		keyReleased(_key);
	}
}

void buttonPressed(GLFWwindow* window, int _button, int _action, int _mods){
	if(_action == GLFW_PRESS){
		keyPressed(_button);
	}else if(_action == GLFW_RELEASE){
		keyReleased(_button);
	}
}

void mouseMoved(GLFWwindow* window, double _xpos, double _ypos){
	mousePosition = glm::vec2((float)_xpos, 720 - (float)_ypos);
}

Input::Input(GLFWwindow* w) {
	window = w;
	glfwSetKeyCallback(window, keyPressed);
	glfwSetMouseButtonCallback(window, buttonPressed);
	glfwSetCursorPosCallback(window, mouseMoved);

	double x, y;
	glfwGetCursorPos(w, &x, &y);
	mousePosition.x = x;
	mousePosition.y = y;
	previousMousePosition = mousePosition;
}

void Input::processInput() {
	previousMousePosition = mousePosition;
	previousKeymap = keymap;

	glfwPollEvents();
}

glm::vec2 Input::getPreviousMousePosition(){
	return previousMousePosition;
}

glm::vec2 Input::getMousePosition(){
	return mousePosition;
}

bool Input::isKeyDown(int _keyID){
	auto it = keymap.find(_keyID);
	if(it != keymap.end()){
		return it->second;
	}
	return false;
}

bool Input::wasKeyDown(int _keyID){
	auto it = previousKeymap.find(_keyID);
	if(it != previousKeymap.end()){
		return it->second;
	}
	return false;
}

bool Input::isKeyPressed(int _keyID){
	return (isKeyDown(_keyID) && !wasKeyDown(_keyID));
}

bool Input::isKeyReleased(int _keyID){
	return (!isKeyDown(_keyID) && wasKeyDown(_keyID));
}