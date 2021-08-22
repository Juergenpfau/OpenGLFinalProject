#pragma once

#include <GL/glew.h>
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

class Shader {
public:

	Shader(const char* vs, const char* fs);
	void use();
	void unuse();
	void cleanUp();

	void loadUniform(const std::string& name, const glm::vec3& vec);
	void loadUniform(const std::string& name, const glm::mat4& matrix);

private:

	GLuint pid = 0;
	GLuint vid = 0;
	GLuint fid = 0;

};


