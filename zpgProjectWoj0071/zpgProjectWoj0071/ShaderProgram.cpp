#include "ShaderProgram.h"
#include <iostream>


//Model matrix : defines position, rotation and scale of the vertices of the model in the world.
//View matrix : defines position and orientation of the "camera".
//Projection matrix : Maps what the "camera" sees to NDC, taking care of aspect ratio and perspective.

ShaderProgram::ShaderProgram(AppVertexShader* vertexShader, AppFragmentShader* fragmentShader) {
	this->shaderProgram = CreateShader(vertexShader, fragmentShader);
	this->M = glm::mat4(1.0f);
	glLinkProgram(this->shaderProgram);
}

int ShaderProgram::CreateShader(AppVertexShader* vertexShader, AppFragmentShader* fragmentShader) {
	GLuint programID = glCreateProgram();

	// we need to attach both of sahders into our program
	GLuint vertexShaderID = vertexShader->getVertexShaderID();
	GLuint fragmentShaderID = fragmentShader->getFragmentShaderID();

	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);

	glLinkProgram(programID);
	glValidateProgram(programID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	GLint status;
	glGetProgramiv(programID, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(programID, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "\n CHECK YOUR FRAGMENT AND VERTEX SHADER - THEY ARE SETUP WRONG %s\n", strInfoLog);
		delete[] strInfoLog;
		exit(EXIT_FAILURE);
	}

	// We will returj shader program ID
	return programID;
}

void ShaderProgram::useProgram() {
	glUseProgram(this->shaderProgram);
}

void ShaderProgram::onCameraUpdate(const glm::mat4 updatedViewMatrix, const glm::mat4 updatedProjectionMatrix) {
	//this->camera = camera;
	this->setViewProjectionMatrices(updatedViewMatrix, updatedProjectionMatrix);
	this->viewMatrix = updatedViewMatrix;

	this->projectionMatrix = updatedProjectionMatrix;
}

void ShaderProgram::makeTransformationForMultipleObjects(glm::mat4 modelMatrix) {
	float alpha = 0.0;
	glm::mat4 transform = glm::mat4(1.0f);
	GLuint transformLoc;

	// Send the combined model matrix to the shader
	transformLoc = glGetUniformLocation(this->shaderProgram, "modelMatrix");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));
}


void ShaderProgram::setViewProjectionMatrices(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) {
	GLuint viewLoc = glGetUniformLocation(this->shaderProgram, "viewMatrix");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	GLuint projectionLoc = glGetUniformLocation(this->shaderProgram, "projectMatrix");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}
