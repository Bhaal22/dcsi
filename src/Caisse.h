#ifndef __CAISSEH__
#define __CAISSEH__

#include "GraphicalElement.h"

class Caisse: public GraphicalElement
{
	public:

		Caisse(char *, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
		
		~Caisse();
		
		void shape();
		
		void setColor(GLfloat, GLfloat, GLfloat);
		
	protected:
		GLfloat width, height, length;
		//GLfloat r, g, b;
	
	
};


#endif
