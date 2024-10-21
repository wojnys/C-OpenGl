#include "AppVertexShader.h"
#include <cstddef>

AppVertexShader::AppVertexShader(const char* source) {
	//Shader(source, GL_FRAGMENT_SHADER);

	this->vertexShaderID = compileShader(source, GL_VERTEX_SHADER);
}

GLuint AppVertexShader::getVertexShaderID() const
{
	return this->vertexShaderID;
}



