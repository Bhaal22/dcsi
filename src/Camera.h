/* Camera.h */

#ifndef _CAMERA_H
#define _CAMERA_H


#define VIEW_MAGNITUDE 40.0f //the wanted magnitude of the view vect, ie the distance between the camera and the character
//#define VIEW_MAGNITUDE 30.0f 
#define HEIGHT 20 //the wanted height of the camera
#define MOVE_AWAY_RATIO 0.75 //we move 50 % slower if we're to close to the character
#define APPROACH_RATIO 1.25 //we move 50 % faster if we're to close to the character
#define MAX_ANGLE 1.1 //this is the maximum angle before the camera rotate to return behind the character
#define ROTATION_ANGLE 0.06545//PI/48

#include "Main.h"
#include "Element.h"
#include <vector>

class Camera : public Element 
{

 public:
  
  Camera (Vector3D& cPos, Vector3D& cView, Vector3D& cUp) : Element(cPos), view (cView), up (cUp), rotating (false) {}

  Camera (float positionX, float positionY, float positionZ,
	             float viewX,      float viewY,      float viewZ,
	             float upX,          float upY,         float upZ) : Element(Vector3D(positionX, positionY, positionZ)), view(Vector3D(viewX,viewY,viewZ)), 
	                                                                                    up(Vector3D(upX, upY, upZ))  {}
 
  Camera(Vector3D& cView) : Element(Vector3D(0,HEIGHT,0)), view(cView), up(Vector3D(0,1,0)) {}
  
  void affiche();
  
  Vector3D& getPosition()
  {
    return position;
  }
  
  Vector3D& getView() 
  {
    return view;
  }
  
  Vector3D& getUpVector() 
  {
    return up;
  }
    
   void setRotating (bool newR) {
   		rotating = newR;
   }

  // This changes the position, view, and up vector of the camera.
  void changePosition (float positionX, float positionY, float positionZ,
		                              float viewX,      float viewY,      float viewZ,
		                              float upX,          float upY,         float upZ) 
	{
    	position.x = positionX;       position.y = positionY;       position.z = positionZ;
    	view.x = viewX;                 view.y = viewY;                 view.z = viewZ;
    	up.x = upX;                        up.y = upY;                        up.z = upZ;
  	}

  // This rotates the camera around a point (it will be the car)
  void rotateAroundPoint (const Vector3D& center, float angle, float x, float y, float z);

	//rotates around the view, axis is 0,1,0 and angle is ROTATION_ANGLE * ratio
	void Camera::rotateAroundView (float ratio);
  

  /* This will move the camera forward or backward depending on the speed */
  void move (const Vector3D&, const Vector3D&);

	void updateRotation (const Vector3D& newView, const Vector3D& charDirection);

 private:

  Vector3D view;                       
  Vector3D up;

  bool rotating; //true if the camera is rotating to replace itself right back the character

  /* Determine if the camera collided, if so update moveVec */
//  bool hasCollided (const Vector3D& newView,  std::vector<Element&>& listOtherObjects, const Vector3D& moveVec);

};


#endif
