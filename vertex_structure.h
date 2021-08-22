#ifndef vstruct
#define vstruct

#include <glm/glm.hpp>

struct Vertex {
	Vertex(glm::vec3 p, glm::vec3 n, glm::vec2 u){
		position = p;
		normal = n,
		uv = u;
	}
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 uv;
};


#endif