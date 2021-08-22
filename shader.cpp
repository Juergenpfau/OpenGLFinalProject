#include "shader.h"
#include <fstream>

std::string loadFile(const std::string& path) {
	std::ifstream is;
	std::string line;


	std::string shaderCode = "";
	is.open(path);

	while(std::getline(is, line)) {
		shaderCode += line + "\n";
	}

	is.close();
	return shaderCode;
}

Shader::Shader(const char* vs, const char* fs){
	vid = glCreateShader(GL_VERTEX_SHADER);
	fid = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vsCode = loadFile(vs);
	std::string fsCode = loadFile(fs);

	const char* vs_pointer = vsCode.c_str();
	const char* fs_pointer = fsCode.c_str();

	glShaderSource(vid, 1, &vs_pointer, 0);
	glShaderSource(fid, 1, &fs_pointer, 0);

	GLint vsCompileStatus;
	GLint fsCompileStatus;

	glCompileShader(vid);
	glGetShaderiv(vid, GL_COMPILE_STATUS, &vsCompileStatus);
	if(!vsCompileStatus){
		printf("Failed to compile vertex shader: %s\n", vs);
	}

	glCompileShader(fid);
	glGetShaderiv(fid, GL_COMPILE_STATUS, &fsCompileStatus);
	if(!fsCompileStatus){
		printf("Failed to compile fragment shader: %s\n", fs);
	}

	pid = glCreateProgram();
	glAttachShader(pid, vid);
	glAttachShader(pid, fid);
	glLinkProgram(pid);
	glValidateProgram(pid);
}

void Shader::use(){
	glUseProgram(pid);
}

void Shader::unuse(){
	glUseProgram(0);
}

void Shader::cleanUp(){
	glDetachShader(pid, vid);
	glDetachShader(pid, fid);
	glDeleteShader(vid);
	glDeleteShader(fid);
	glDeleteProgram(pid);
}

void Shader::loadUniform(const std::string& name, const glm::vec3& vec){
	glUniform3fv(glGetUniformLocation(pid, name.c_str()), 1, &vec.x);
}

void Shader::loadUniform(const std::string& name, const glm::mat4& matrix){
	glUniformMatrix4fv(glGetUniformLocation(pid, name.c_str()), 1, GL_FALSE, &matrix[0][0]);
}
