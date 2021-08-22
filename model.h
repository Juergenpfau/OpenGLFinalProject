#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include "vertex_structure.h"


class Model {
public:

	Model(std::string path);
	void render();

private:

	GLuint m_numVertices = 0;
	GLuint m_vaoID = 0;
	GLuint m_vboID = 0;
	GLuint m_eboID = 0;

};