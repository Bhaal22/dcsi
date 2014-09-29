#ifndef  __ELEMENTH__
#define __ELEMENTH__

#include "Main.h"
#include "BoundingBox.h"
#include <math3d.h>


class Element
{
 public:
  
  Element() : position(Vector3D(0, 0, 0)) { };
  Element(Vector3D pos) : position(pos) { };
  Element(float x, float y, float z) : position(Vector3D(x, y, z)) { };
  /* destructor */
  virtual ~Element();
  
  /* get the Bounding Box */
  const BoundingBox *getBoundingBox();
  Vector3D &getPosition();
  
 protected:
  BoundingBox *box;
  Vector3D position;
};

/* Element.h */

/*class Element {
  
  public :*/
    
    /* - receives an array of its triangles (the ones used to draw it),
       - a bool which indicates if the object will always remain at the same place or if it will move
       (this improves the processing time, since its transformation matrix doesn't change and don't need to be calculated each frame)
       - a point which is its position on the map
    */
/*   Element (bool cIsStatic, const Vector3D& cPos) : position (cPos), box (new CollisionModel3DImpl (isStatic)), isStatic (cIsStatic), matrixSet (NULL), arrayT (new std::vector<Vector3D[3]>) { }

  	Element (bool cIsStatic, float x, float y, float z) : Element (cIsStatic, Vector3D (x,y,z)) { }

  	void setTriangleNumber(int size) 
  	{
    	box->setTriangleNumber();
  	}

  	void addTriangle (Vector3D[3] triangles) 
  	{
    	box->addTriangle((*it)[0], (*it)[1], (*it)[2]);    
    	arrayT.push_back (triangle);
  	}
  
  	void finalize () 
  	{
    	box->finalize();  
  	}
  
  	void addQuad (Vector3D[4] quad) 
  	{
    	Vector3D tmpA1 [3], tmpA2 [3];
    	box->addQuad((*it)[0], (*it)[1], (*it)[2], (*it)[3], tmpA1, tmpA2);
    	arrayT.push_back (tmpA1);
    	arrayT.push_back (tmpA2);
  	}*/

  	/* for elements that doesn't have any bounding box, like the ground */
/*  	Element (Vector3D cPos) : position (cPos), box (NULL) { }

  	Element (float x, float y, float z) : Element (Vector3D (x,y,z)) { }

  	~Element() 
  	{
    	delete (box);
  	}

  	inline const Vector* getPos () 
  	{
    	return position();
  	}

  	inline const vector<Vector3D[3]>& getArrayT () 
  	{
    	return arrayT;
    }

  	inline CollisionModel3DImpl* getBox () 
  	{
    	return box;
  	}*/

  	/* sets the new transform matrix of this, used to determine if a collision occured or not
     	if this function is called more than once for a static object, it won't do anything */
/*  	void setMatrix (float newMatrix [16]);

  	protected :
    
    	CollisionModel3DImpl* box;
  		Vector3D position;

  		//all the triangles ot this :
  		vector<Vector3D[3]> arrayT;
    
  		bool isStatic; //if the object is static
 	 	bool matrixSet; //if the matrix is set (initialized) ** usefull just for static elements **
};*/



#endif
