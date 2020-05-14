#pragma once

#include "GraphicalElement.h"

class PalmTree : public GraphicalElement
{
public:
    PalmTree(const char *, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
    ~PalmTree();

    void shape();

    void setColor(GLfloat, GLfloat, GLfloat);

protected:
    GLfloat width, height, length;
    GLfloat r, g, b;
};
