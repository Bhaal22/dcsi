#include "Vehicle.h"

Vehicle::Vehicle(GLfloat x, GLfloat y, GLfloat z, GLfloat xFront, GLfloat yFront, GLfloat zFront, GLfloat w, GLfloat h, GLfloat l, float hOffset):
															GraphicalElement(x, y, z), front (Vector3D (xFront, yFront, zFront)), width(w), height(h), length(l)
{
	r = g = b = 1.0f;
	heightOffset = hOffset;
}
Vehicle::~Vehicle()
{}

Vector3D& Vehicle::getFront () 
{
	return front;
}

Vector3D Vehicle::getDirection () 
{
	Vector3D ret = (front - position).Normalized();
	return ret;
}


void Vehicle::setColor(GLfloat r, GLfloat g, GLfloat b)
{
	this->r = r; this->g = g; this->b = b;
}


void Vehicle::moveRelatif(float speed, Landscape* terrain) 
{
	Vector3D moveVec = getDirection();

	position.x += moveVec.x * speed;
	position.y += moveVec.y * speed;
	position.z += moveVec.z * speed;

	front.x += moveVec.x * speed;
	front.y += moveVec.y * speed;
	front.z += moveVec.z * speed;
		
	updateSlope(terrain);
}


void Vehicle::setDirection (const Vector3D& newDir) {

	Vector3D newDirN = newDir.Normalized();
	Vector3D tmp = getDirection();
	float nm = tmp.Magnitude();
	front = position + (nm * newDirN);
}

//rotates the Vehicle
void Vehicle::rotate (float angle, Landscape* terrain) {
	
	Vector3D dir = front - position;
	Vector3D axisX (0,1,0);
	Vector3D norm_tmp = CrossProduct(dir, axisX);
	Vector3D norm_tmp2 = CrossProduct (norm_tmp, dir);
	Vector3D norm = norm_tmp2.Normalized();
	rotatePriv (angle, norm.x, norm.y, norm.z);
	
	updateSlope(terrain);
}


void Vehicle::rotatePriv (float angle, float axisX, float axisY, float axisZ)
{	
	Vector3D newFront;            
  
  // To rotate our position around a point, what we need to do is find
  // a vector from our position to the center point we will be rotating around.
  // Once we get this vector, then we rotate it along the specified axis with
  // the specified degree.  Finally the new vector is added center point that we
  // rotated around (center) to become our new position.  That's all it takes.
  
  // Get the vVector from our position to the center we are rotating around
  Vector3D vDir= front - position;
  
  // Calculate the sine and cosine of the angle once
  float cosTheta = (float)cos(angle);
  float sinTheta = (float)sin(angle);

  // Find the new x position for the new rotated point
  newFront.x = (cosTheta + (1 - cosTheta) * axisX * axisX)        * vDir.x;
  newFront.x += ((1 - cosTheta) * axisX * axisY - axisZ * sinTheta)    * vDir.y;
  newFront.x += ((1 - cosTheta) * axisX * axisZ + axisY * sinTheta)    * vDir.z;
  
  // Find the new y position for the new rotated point
  newFront.y  = ((1 - cosTheta) * axisX * axisY + axisZ * sinTheta)    * vDir.x;
  newFront.y += (cosTheta + (1 - cosTheta) * axisY * axisY)        * vDir.y;
  newFront.y += ((1 - cosTheta) * axisY * axisZ - axisX * sinTheta)    * vDir.z;
  
  // Find the new z position for the new rotated point
  newFront.z  = ((1 - cosTheta) * axisX * axisZ - axisY * sinTheta)    * vDir.x;
  newFront.z += ((1 - cosTheta) * axisY * axisZ + axisX * sinTheta)    * vDir.y;
  newFront.z += (cosTheta + (1 - cosTheta) * axisZ * axisZ)        * vDir.z;

  // Now we just add the newly rotated vector to our position to set
  // our new rotated position of our camera.
  front = position + newFront;
	
}


/*updates slope of the Vehicle, depending on the slope of the terrain*/

void Vehicle::updateSlope (Landscape* terrain) 
{


  Vector3D carPosProj (position.x, terrain->getYFromXZ (position.x, position.z), position.z);
  Vector3D carFProj (front.x, terrain->getYFromXZ (front.x, front.z), front.z);

  Vector3D nD = carFProj - carPosProj;

	position.y = carPosProj.y + height/2;
  position.y -= heightOffset;
  
  setDirection (nD);

}

float Vehicle::getOffset()
{
	return heightOffset;
}

