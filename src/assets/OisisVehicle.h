#pragma once

#include "Vehicle.h"
#include "Landscape.h"

class OisisVehicle : public Vehicle
{
public:
    OisisVehicle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, float);
    ~OisisVehicle();

    /* Tree Creation */
    void shape();
};
