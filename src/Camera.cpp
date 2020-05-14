/* Camera.cpp */

#include "Camera.h"
#include <vector>

/*
 * We need to know the new view (character) position,
 * the direction the character is facing,
 * and a list of the other objects which could colide with the camera
 *  the transformation of the other objects must have been set !
 */
void Camera::render()
{
    gluLookAt(position.x, position.y, position.z,
              view.x, view.y, view.z,
              up.x, up.y, up.z);
}

void Camera::move(const Vector3D &newView, const Vector3D &charDirection)
{
    //we first get the speed the character moved :
    float speed;
    Vector3D tmp = newView - view;
    speed = tmp.Magnitude();

    //if we were too close to the character last frame, we move more slowly this time, and vice versa :
    Vector3D vecDist = ((Vector3D(view.x, 0, view.z)) - (Vector3D(position.x, 0, position.z)));
    float dist = vecDist.Magnitude();
    if (dist > VIEW_MAGNITUDE)
    {
        //we're too far
        speed *= APPROACH_RATIO;
    }
    else if (dist < VIEW_MAGNITUDE)
    {
        //we're too close
        speed *= MOVE_AWAY_RATIO;
    }

    Vector3D moveVec = ((Vector3D(newView.x, 0, newView.z)) - (Vector3D(position.x, 0, position.z)));
    moveVec = moveVec.Normalized();

    //printf("speed : %f\n", speed);

    position.x += moveVec.x * speed; // Add our acceleration to our position's X
    position.y += (newView.y - view.y);
    position.z += moveVec.z * speed; // Add our acceleration to our position's Z

    //we finally update the view
    view = newView;
}

void Camera::rotateAroundView(float ratio)
{
    rotateAroundPoint(view, ROTATION_ANGLE * ratio, 0, 1, 0);
}

void Camera::updateRotation(const Vector3D &newView, const Vector3D &charDirection)
{

    //we get the angle between our view vector and the vector which is the direction the character is facing :
    Vector3D moveVec = ((Vector3D(newView.x, 0, newView.z)) - (Vector3D(position.x, 0, position.z)));
    moveVec = moveVec.Normalized();

    float angle = angleBetweenVectors(moveVec, charDirection);

    if (!rotating)
    {
        //we weren't rotating, but we check if now we have to begin to rotate
        if (absolute(angle) > MAX_ANGLE)
            rotating = true;
    }

    if (!rotating)
        return;

    bool rotating_tmp = rotating;

    Vector3D tmp2 = CrossProduct(moveVec, charDirection);
    if (tmp2.y < 0)
        angle *= -1;

    if (absolute(angle) < ROTATION_ANGLE)
    {
        rotateAroundPoint(newView, angle, 0, 1, 0);
        rotating_tmp = false;
    }
    else
    {
        if (angle > 0)
            rotateAroundPoint(newView, ROTATION_ANGLE, 0, 1, 0);
        else
            rotateAroundPoint(newView, -ROTATION_ANGLE, 0, 1, 0);
    }

    /* If the rotation has made the camera to collide, we return back to our original position : */

    /* We didn't collide : */
    rotating = rotating_tmp;
}

//determine if the camera collided, if so update moveVec
/*bool Camera::hasCollided (const Vector3D& newView,  vector<Element&>& listOtherObjects, const Vector3D& moveVec)
{

  /* We get the transformation matrix of the camera : */
/*  glLoadIdentity();
  gluLookAt(position.x, position.y,  position.z,
	    newView.x, newView.y, newView.z,
	    up.x, up.y, up.z);
  float transMat[16];
  glGetFloatv(GL_MODELVIEW_MATRIX, transMat);
  box->setTransform (transMat);

  vector<Element&>::const_iterator it;
  for (it = listOtherObjects.begin(); it != listOtherObjects.end(); it++)
  {
    if (box->collision((*it).getBox(), -1, 0, NULL))
    {
      //we collided

      //lets find the direction we should now move to, ie the vector (view-position) projected on the plane of the triangle :

      int colThis, colOther; //index of the hit triangle
      box->getCollidingTriangles (colThis, colOther);
      Vector3D[3] collidedTriangle = (*it).getArrayT[colOther];

      //get the normalized normal of the hit plan :
      Vector3D normTri = getNormalOfPoly (collidedTriangle);
      float dPlane = planeDistanceFromOrigin (normTri, collidedTriangle[0]);
      float dPoint1 = getDistanceFromPlane (position, normTr, dPlane);
      float dPoint2 = getDistanceFromPlane (newView, normTr, dPlane);

      //now find the projection of each point on the plane :
      Vector3D pt1Proj = position - (normTri * dPoint1);
      Vector3D pt2Proj = newView - (normTri * dPoint2);

      //we now know the new move vector :
      moveVec = pt2Proj - pt1Proj;

      return true;
    }
  }
  return false;
}
*/

void Camera::rotateAroundPoint(const Vector3D &center, float angle, float x, float y, float z)
{
    Vector3D newPos;

    // To rotate our position around a point, what we need to do is find
    // a vector from our position to the center point we will be rotating around.
    // Once we get this vector, then we rotate it along the specified axis with
    // the specified degree.  Finally the new vector is added center point that we
    // rotated around (center) to become our new position.  That's all it takes.

    // Get the vVector from our position to the center we are rotating around
    Vector3D vPos = position - center;

    // Calculate the sine and cosine of the angle once
    float cosTheta = (float)cos(angle);
    float sinTheta = (float)sin(angle);

    // Find the new x position for the new rotated point
    newPos.x = (cosTheta + (1 - cosTheta) * x * x) * vPos.x;
    newPos.x += ((1 - cosTheta) * x * y - z * sinTheta) * vPos.y;
    newPos.x += ((1 - cosTheta) * x * z + y * sinTheta) * vPos.z;

    // Find the new y position for the new rotated point
    newPos.y = ((1 - cosTheta) * x * y + z * sinTheta) * vPos.x;
    newPos.y += (cosTheta + (1 - cosTheta) * y * y) * vPos.y;
    newPos.y += ((1 - cosTheta) * y * z - x * sinTheta) * vPos.z;

    // Find the new z position for the new rotated point
    newPos.z = ((1 - cosTheta) * x * z - y * sinTheta) * vPos.x;
    newPos.z += ((1 - cosTheta) * y * z + x * sinTheta) * vPos.y;
    newPos.z += (cosTheta + (1 - cosTheta) * z * z) * vPos.z;

    // Now we just add the newly rotated vector to our position to set
    // our new rotated position of our camera.
    position = center + newPos;
}
