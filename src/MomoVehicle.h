#ifndef __MOMOH__
#define __MOMOH__

#include "Vehicle.h"

class MomoVehicle : public Vehicle{
public:

	MomoVehicle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, float);
	~MomoVehicle();
	
	void shape();
};


#endif
