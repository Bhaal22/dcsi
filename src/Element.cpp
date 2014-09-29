#include "Element.h"

Element::~Element()
{
        delete box;
}


inline const BoundingBox *Element::getBoundingBox()
{
        return box;
}

Vector3D& Element::getPosition()
{
	return position;
}

/*void Element::setMatrix (float newMatrix[16])
{
	if (!isStatic || (isStatic && !matrixSet)) 
	{
    	matrixSet = true;
    	box->setTransform(newMatrix); 
  	}
}*/