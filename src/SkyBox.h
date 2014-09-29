#include "GraphicalElement.h"

class SkyBox : public GraphicalElement
{
	public:

		SkyBox(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
		~SkyBox();
		
		void shape();
	protected:
	
		void quad(int);
		GLfloat width, height, length;
	

};
