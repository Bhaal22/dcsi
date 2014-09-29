#include "GraphicalElement.h"

class PalmTree : public GraphicalElement
{
	public:
	
		/* Constructor && Destructor */
		PalmTree(char *, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
		~PalmTree();
		
		/* Tree Creation */
		void shape();
		
		void setColor(GLfloat, GLfloat, GLfloat);
	
	protected:
		GLfloat width, height, length;
		GLfloat r, g, b;
};
