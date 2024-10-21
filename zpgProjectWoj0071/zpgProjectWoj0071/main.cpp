//Include GLFW  
#include <GL/glew.h>
#include <GLFW/glfw3.h>  

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


#include "Application.h"
int main() {

	Application* app = new Application();
	app->initialization(); // OpenGL initialization
	app->createShaders();  // Loading shaders
	app->createModels();    // Loading models
	app->run();            // Rendering 
	//delete app;           // Cleanup
}














//#pragma once
//  //Include GLEW
//#include <GL/glew.h>
//
////Include GLFW
//#include <GLFW/glfw3.h>
//
////Include GLM  
//#include <glm/vec3.hpp> // glm::vec3
//#include <glm/vec4.hpp> // glm::vec4
//#include <glm/mat4x4.hpp> // glm::mat4
//#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
//#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
//
//
////Include the standard C++ headers  
//#include <iostream>
//#include <stdlib.h>
//#include <stdio.h>
//#include <random>
//
//#include "sphere.h"
//#include "tree.h"
//
//const char* vertex_shader =
//"#version 330\n"
//"uniform mat4 modelMatrix;"
//"uniform mat4 projectMatrix;"
//"uniform mat4 viewMatrix;"
//"out vec3 vertexColor;"
//"layout(location=0) in vec3 vp;"
//"layout(location=1) in vec3 vn;"
//"void main () {"
//"     vertexColor=vn;"
//"     gl_Position = projectMatrix * viewMatrix * modelMatrix * vec4(vp, 1.0);"
//"}";
//
//
//
//const char* fragment_shader =
//"#version 330\n"
//"out vec4 frag_colour;"
//"in vec3 vertexColor;"
//"void main () {"
//"     frag_colour = vec4(vertexColor, 0.0);"
//"}";
//
//
//
//void proccessInput(GLFWwindow * window, float deltaTime, glm::vec3* cameraPos, glm::vec3* cameraFront, glm::vec3* cameraUp) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//
//	float cameraSpeed = 5.5f * deltaTime;
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		*cameraPos += cameraSpeed * (*cameraFront);
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		*cameraPos -= cameraSpeed * (*cameraFront);
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		*cameraPos -= glm::normalize(glm::cross(*cameraFront, *cameraUp)) * cameraSpeed;
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		*cameraPos += glm::normalize(glm::cross(*cameraFront, *cameraUp)) * cameraSpeed;
//}
//
//int WIDTH = 800;
//int HEIGHT = 600;
//// mouse state
//bool firstMouse = false;
//float lastX = (float)WIDTH / 2.0;
//float lastY = (float)HEIGHT / 2.0;
//
//// camera
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 6.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
////mouse
//float yaw = -90.0f;
//float pitch = 0.0f;
//float fov = 45.0f;
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
//	if (firstMouse)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//
//	float xoffset = xpos - lastX;
//	float yoffset = lastY - ypos;
//	lastX = xpos;
//	lastY = ypos;
//
//	float sensitivity = 0.2f;
//	xoffset *= sensitivity;
//	yoffset *= sensitivity;
//
//	yaw += xoffset;
//	pitch += yoffset;
//
//	if (pitch > 89.0f)
//		pitch = 89.0f;
//	if (pitch < -89.0f)
//		pitch = -89.0f;
//
//	glm::vec3 front;
//	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
//	front.y = sin(glm::radians(pitch));
//	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
//
//	cameraFront = glm::normalize(front);
//
//}
////void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
////	//fov -= yoffset;
////
////	if (fov >= 1.0f && fov <= 45.f) {
////	
////	}
////}
//
//float generateRandomFloatNumber(float bottomBoundary, float upBoundary) {
//	std::random_device rd;
//	std::mt19937 gen(rd());
//	std::uniform_real_distribution<float> dis(bottomBoundary, upBoundary);
//
//	return dis(gen);
//}
//int main(void)
//{
//
//	if (!glfwInit()) {
//		fprintf(stderr, "ERROR: could not start GLFW3\n");
//		exit(EXIT_FAILURE);
//	}
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "ZPG", NULL, NULL);
//	if (!window) {
//		glfwTerminate();
//		exit(EXIT_FAILURE);
//	}
//
//	glfwMakeContextCurrent(window);
//	glfwSwapInterval(1);
//
//	glfwSetCursorPosCallback(window, mouse_callback);
//	//glfwSetScrollCallback(window, scroll_callback);
//	// 
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//	// start GLEW extension handler
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	//create and compile shaders
//	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertex_shader, NULL);
//	glCompileShader(vertexShader);
//	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
//	glCompileShader(fragmentShader);
//	GLuint shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, fragmentShader);
//	glAttachShader(shaderProgram, vertexShader);
//	glLinkProgram(shaderProgram);
//
//
//	GLuint VBO, VAO = 0;
//	glGenBuffers(1, &VBO); // generate the VBO
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(tree), tree, GL_STATIC_DRAW);
//
//	//Vertex Array Object (VAO)
//
//	glGenVertexArrays(1, &VAO); //generate the VAO
//	glBindVertexArray(VAO); //bind the VAO
//	glEnableVertexAttribArray(0); //enable vertex attributes
//	glEnableVertexAttribArray(1); //enable vertex attributes
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//
//	glm::mat4 M = glm::mat4(1.0f);
//
//	float alpha = 0;
//	GLint matrixID;
//
//	//delta-time timing
//	float deltaTime = 0.0f;
//	float lastFrame = 0.0f;
//	int frameCount = 0;
//	float lastTime = 0.0f;
//
//	glEnable(GL_DEPTH_TEST); //Z-buffer
//	glEnable(GL_CULL_FACE); // odstranuje zadne steny
//
//
//	//glm::vec3 spherePositions[] = {
//	// glm::vec3(-2.0f, 0.0f, -5.0f),  // Sphere 1
//	// glm::vec3(2.0f, 0.0f, -5.0f),   // Sphere 2
//	// glm::vec3(-2.0f, 2.0f, -5.0f),  // Sphere 3
//	// glm::vec3(2.0f, 2.0f, -5.0f)    // Sphere 4
//	//};
//
//	glm::vec3 spherePositions[500];
//
//	for (int i = 0;i < 500;i++) {
//		float rand = generateRandomFloatNumber(-100, 100);
//
//		spherePositions[i] = glm::vec3(rand, rand, rand);
//	}
//
//
//	while (!glfwWindowShouldClose(window))
//	{
//		// per-frame time logic
//
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		frameCount++;
//
//		// Calculate and display FPS every second
//		if (currentFrame - lastTime >= 1.0f) {
//			// FPS = number of frames / time (1 second here)
//			float fps = frameCount / (currentFrame - lastTime);
//
//			// Print FPS to the console (or display it on screen)
//			std::cout << "FPS: " << fps << std::endl;
//
//			// Reset the frame count and lastTime for the next second
//			frameCount = 0;
//			lastTime = currentFrame;
//		}
//	
//
//		// proccess input
//		proccessInput(window, deltaTime, &cameraPos, &cameraFront, &cameraUp);
//
//		// clear color and depth buffer
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO);
//
//
//		//alpha += 0.0;
//		//M = glm::rotate(glm::mat4(1.0f), alpha, glm::vec3(0.0f, 0.0f, 1.0f));
//		//matrixID = glGetUniformLocation(shaderProgram, "modelMatrix");
//		//glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(M));
//
//
//		//// Send the combined model matrix to the shader
//		//M = glm::rotate(glm::mat4(1.0f), alpha, glm::vec3(0.5f, 1.0f, 0.0f));  // Apply rotation
//		//matrixID = glGetUniformLocation(shaderProgram, "modelMatrix");
//		//glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(M));
//
//
//	
//		//glDrawArrays(GL_TRIANGLES, 0, 2880);  //mode, first, count
//
//		for (unsigned int i = 0; i < 500;i++) {
//
//			// Create model matrix: first translate, then rotate
//			//glm::mat4 model = glm::mat4(1.0f);
//			M = glm::translate(glm::mat4(1.0f), spherePositions[i]);  // Apply translation for each sphere
//			alpha = 0.0;  // Increment the rotation angle
//			M = glm::rotate(M, alpha, glm::vec3(0.0f, 0.0f, 1.0f));  // Apply rotation
//
//			// Send the combined model matrix to the shader
//			matrixID = glGetUniformLocation(shaderProgram, "modelMatrix");
//			glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(M));
//
//			// Draw each sphere
//			glDrawArrays(GL_TRIANGLES, 0, 100000);  //mode, first, count
//		}
//
//		M = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//		//M = glm::lookAt(glm::vec3(5.0f, 0.0f, 0.0f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f));
//		matrixID = glGetUniformLocation(shaderProgram, "viewMatrix");
//		glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(M));
//
//		M = glm::perspective(glm::radians(fov), (float)400 / (float)400, 0.1f, 100.0f);
//		//M = glm::perspective(45.0f, 800.f / 600.f, 0.1f, 100.0f);
//		matrixID = glGetUniformLocation(shaderProgram, "projectMatrix");
//		glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(M));
//
//
//		// update other events like input handling
//		glfwPollEvents();
//		// put the stuff we�ve been drawing onto the display
//		glfwSwapBuffers(window);
//	}
//	glfwDestroyWindow(window);
//	glfwTerminate();
//	exit(EXIT_SUCCESS);
//}