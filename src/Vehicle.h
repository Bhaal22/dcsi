#ifndef __VEHICLEH__
#define __VEHICLEH__

#include "GraphicalElement.h"
#include "Landscape.h"

class Vehicle : public GraphicalElement
{
public:
    Vehicle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, float);
    ~Vehicle();

    virtual void moveRelatif(float, Landscape *);
    virtual Vector3D &getFront();
    virtual Vector3D getDirection();
    void setColor(GLfloat, GLfloat, GLfloat);
    void rotate(float angle, Landscape *);

    void setDirection(const Vector3D &);
    void updateSlope(Landscape *terrain);
    float getOffset();

protected:
    void rotatePriv(float angle, float axisX, float axisY, float axisZ);
    Vector3D front;
    GLfloat width, height, length;
    GLfloat r, g, b;
    float heightOffset;
};

#endif
