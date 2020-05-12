#ifndef __NOELH__
#define __NOELH__

#include "Vehicle.h"
#include "Landscape.h"

class NoelVehicle : public Vehicle
{
public:
    NoelVehicle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, float);
    ~NoelVehicle();

    void shape();
};

#endif
