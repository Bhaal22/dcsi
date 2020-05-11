#include "NoelVehicle.h"

NoelVehicle::NoelVehicle(GLfloat x, GLfloat y, GLfloat z, GLfloat xFront, GLfloat yFront, GLfloat zFront, GLfloat w, GLfloat h, GLfloat l, float hOffset):Vehicle(x, y, z, xFront, yFront, zFront, w, h, l, hOffset)
{
	createTexturePNG("/rd/vehicles/noel/traineau.png", PNG_FULL_ALPHA, 0);
	createTexturePNG("/rd/vehicles/noel/dessus.png", PNG_FULL_ALPHA, 1);
}

NoelVehicle::~NoelVehicle()
{
	delete box;
}


void NoelVehicle::shape()
{
	
	
	glEnable(GL_TEXTURE_2D);  
  
  	/* Assignation for the display List */
  	displayList = glGenLists(1);
  	glNewList(displayList, GL_COMPILE);
  	
	
  	glEnable(GL_TEXTURE_2D);  
  
  	glBindTexture(GL_TEXTURE_2D, listeTexture[0]);
  	glBegin(GL_QUADS);
  		// The side quads
  		glTexCoord2f(1.0f, 0.0f); glVertex3f(width/2,            0,       length/2);
  		glTexCoord2f(1.0f, 1.0f); glVertex3f(width/2,    height,       length/2);
  		glTexCoord2f(0.0f, 1.0f); glVertex3f(width/2,    height,       -length/2);
  		glTexCoord2f(0.0f, 0.0f); glVertex3f(width/2,             0,      -length/2);

  		glTexCoord2f(1.0f, 0.0f); glVertex3f(-width/2,             0,       length/2);
  		glTexCoord2f(1.0f, 1.0f); glVertex3f(-width/2,      height,      length/2);
  		glTexCoord2f(0.0f, 1.0f); glVertex3f(-width/2,      height,      -length/2);
  		glTexCoord2f(0.0f, 0.0f); glVertex3f(-width/2,              0,      -length/2);
  	glEnd();

  	glBindTexture(GL_TEXTURE_2D, listeTexture[1]);
  	glBegin(GL_QUADS);
  	// The midle quads
  	glTexCoord2f(1.0f, 0.0f); glVertex3f(7*width/8,          5*height/8,          -length/3);
  	glTexCoord2f(1.0f, 1.0f); glVertex3f(-7*width/8,           5*height/8,         -length/3);
  	glTexCoord2f(0.0f, 1.0f); glVertex3f(-7*width/8,               height/2,         -length/4);
  	glTexCoord2f(0.0f, 0.0f); glVertex3f(7*width/8,               height/2,         -length/4);

  	glTexCoord2f(1.0f, 0.0f); glVertex3f(7*width/8,                height/2,     -2*length/6);
  	glTexCoord2f(1.0f, 1.0f); glVertex3f(-7*width/8,                height/2,     -2*length/6);
  	glTexCoord2f(0.0f, 1.0f); glVertex3f(-7*width/8,                height/2,       length/4);
  	glTexCoord2f(0.0f, 0.0f); glVertex3f(7*width/8,                height/2,        length/4);
  glEnd();
  
  glEndList();
}
