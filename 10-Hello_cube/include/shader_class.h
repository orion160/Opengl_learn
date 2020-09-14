#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	// the program ID
	GLuint ID;

	// constructor reads and builds the shader
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	// use/activate the shader
	void use();
	// utility uniform functions
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;

private:
	std::string retrieve_source(const std::string& path);
	GLuint create_vertex_shader(const char* source);
	GLuint create_fragment_shader(const char* source);
	GLuint create_shader_program(GLuint vertex, GLuint fragment);
};
