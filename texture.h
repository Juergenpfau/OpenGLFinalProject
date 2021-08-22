#pragma once

#include <string>
#include <GL/glew.h>

class Texture {
public:

	Texture(std::string path);
	void bind();
	void unbind();

	GLuint textureID = 0;

};