#include "Element.h"

Element::~Element()
{
    delete bounding_box;
}

inline const BoundingBox *Element::getBoundingBox()
{
    return bounding_box;
}

Vector3D &Element::getPosition()
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