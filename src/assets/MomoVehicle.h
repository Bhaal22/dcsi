#pragma once

#include "Vehicle.h"

class MomoVehicle : public Vehicle
{
public:
    MomoVehicle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, float);
    ~MomoVehicle();

    void shape();
};

