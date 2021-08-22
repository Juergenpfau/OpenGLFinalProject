#include "cam.h"
#include <cmath>

Camera::Camera() {
	position = glm::vec3(40, 30, 0);
	pitch = 0.0f;
	yaw = 180.0f;
	projectionMatrix = glm::perspective(glm::radians(90.0f), 800.0f / 600.0f, 0.1f, 1000.0f);
}

void Camera::update(Input input, float deltaTime) {
	movement(input, deltaTime);
	direction(input);
}


void Camera::movement(Input input, float deltaTime){
	if(input.isKeyDown(GLFW_KEY_W)){
		position += forward * 50.5f * deltaTime;
	}
	if(input.isKeyDown(GLFW_KEY_A)){
		position -= glm::normalize(glm::cross(forward, glm::vec3(0, 1, 0))) * 50.5f * deltaTime;
	}
	if(input.isKeyDown(GLFW_KEY_S)){
		position -= forward * 50.5f * deltaTime;
	}
	if(input.isKeyDown(GLFW_KEY_D)){
		position += glm::normalize(glm::cross(forward, glm::vec3(0, 1, 0))) * 50.5f * deltaTime;
	}
	if(input.isKeyDown(GLFW_KEY_LEFT_SHIFT)){
		position.y -= 50.5f * deltaTime;
	}
	if(input.isKeyDown(GLFW_KEY_SPACE)){
		position.y += 50.5f * deltaTime;
	}
}

void Camera::direction(Input input){
	glm::vec2 previousMousePos = input.getPreviousMousePosition();
	glm::vec2 currentMousePos = input.getMousePosition();

	glm::vec2 deltaMousePos = previousMousePos - currentMousePos;

	pitch -= deltaMousePos.y * 0.3f;
	yaw -= deltaMousePos.x * 0.3f;

	if (pitch >= 89.0f) {
		pitch = 89.0f;
	}
	if (pitch <= -89.0f) {
		pitch = -89.0f;
	}

	forward.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	forward.y = sin(glm::radians(pitch));
	forward.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	forward = glm::normalize(forward);
}


glm::mat4 Camera::getViewMatrix() {
	return glm::lookAt(position, position + forward, glm::vec3(0, 1, 0));
}