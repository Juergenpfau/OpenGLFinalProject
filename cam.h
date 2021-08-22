#pragma once

#include "input.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:

	Camera();
	void update(Input input, float deltaTime);
	void movement(Input input, float deltaTime);
	void direction(Input input);
	glm::mat4 getViewMatrix();

	float pitch = 0.0f;
	float yaw = 0.0f;
	glm::vec3 position;
	glm::vec3 forward;
	glm::mat4 projectionMatrix;


};


