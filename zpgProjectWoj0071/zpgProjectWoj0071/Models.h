#pragma once
#ifndef MODEL_H
#define MODEL_H

#include "ShaderProgram.h"
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "CompositeTransformation.h"

// nesmi pro kazdy model vytvorit na graficke karte neve VBO A VAO
// musim vytvorit jeden stromerek, jeden model -> a potom mu jenom pridam novy shader

// vytvorim 2 modely na graficke karte a potom je jenom z ruznyma transformacema vykreslit

// bdu chtit vykreslit model s jinymi barvami -> pouziju DrwableObject, ktery pouzije ShaderProgram
// Stromecky budou ulozeny ve scene

class Model {
public:
    //Model(float points[], size_t size);
    Model(const float points[], size_t size, GLenum shapeType, int first, int count );
    ~Model();
    void bind();
    static void unbind();
    GLuint getVAO();

	GLenum getShapeType() const;
	int getFirst() const;
    int getCount() const;


private:
    GLuint VBO, VAO;

	GLenum shapeType;
	int first;
	int count;
};



#endif // MODEL_H
