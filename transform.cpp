#include "transform.h"

Transform::Transform(){
	position = glm::vec3(0, 0, -200);
	rotation = glm::vec3(0);
	scale = glm::vec3(10);
}

glm::mat4 Transform::getMatrix() const {
	glm::mat4 matrix(1.0f);
	glm::mat4 posMatrix = glm::translate(position);
	glm::mat4 rotXMatrix = glm::rotate(glm::radians(rotation.x), glm::vec3(1, 0, 0));
	glm::mat4 rotYMatrix = glm::rotate(glm::radians(rotation.y), glm::vec3(0, 1, 0));
	glm::mat4 rotZMatrix = glm::rotate(glm::radians(rotation.z), glm::vec3(0, 0, 1));
	glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;
	glm::mat4 scaleMatrix = glm::scale(scale);

	return posMatrix * rotMatrix * scaleMatrix;
}
