#include "GraphicalElement.h"

class TheLittleHouseOnThePrairie : public GraphicalElement
{
	public:

		TheLittleHouseOnThePrairie(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
		~TheLittleHouseOnThePrairie();
		
		void shape();
		
		
	protected:
		GLfloat width, height, length;
};
