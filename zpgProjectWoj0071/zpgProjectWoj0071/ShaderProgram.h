// CISLO SHADER - shaderProgram -> cislo shaderu promenna
/*
	- shader_program_number 
	- metoda
*/

// vytvorim vertex a fragment shader a potom ho priradim


// NOVE
// ZDE POUZIJEME glUniformMatrix4fv = bude to jako promenna pouze v tride shaderProgram -> napr kdyz budeme posilat matici (id model transformace -> private )

// vtvorim si metodu -> posli promenout a tu ptomenu poslu shaderu -> nesmi byt jako public

#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "AppVertexShader.h"
#include "AppFragmentShader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"


class ShaderProgram : public Observer{
	public:
		ShaderProgram(AppVertexShader* vertexShader, AppFragmentShader* fragmentShader);
		void useProgram();
		void makeTransformation(glm::mat4 transform);
		void makeTransformationForMultipleObjects(glm::mat4 transform);
		void setViewProjectionMatrices(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix);
		void onCameraUpdate(const glm::mat4 updatedViewMatrix, const glm::mat4 updatedProjectionMatrix);


	private:
		GLuint shaderProgram;
		static int CreateShader(AppVertexShader* vertexShader, AppFragmentShader* fragmentShader);
		glm::mat4 M;
		GLint matrixID;
		Camera* camera;

		glm::mat4 viewMatrix;
		glm::mat4 projectionMatrix;
};

#endif  SHADERPROGRAM_H