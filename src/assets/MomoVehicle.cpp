#include "MomoVehicle.h"

MomoVehicle::MomoVehicle(GLfloat x, GLfloat y, GLfloat z, GLfloat xFront, GLfloat yFront, GLfloat zFront, GLfloat w, GLfloat h, GLfloat l, float hOffset) : Vehicle(x, y, z, xFront, yFront, zFront, w, h, l, hOffset)
{
    createTexturePNG("/rd/vehicles/momo/stereo.png", PNG_FULL_ALPHA);
    createTexturePNG("/rd/vehicles/momo/bois.png", PNG_FULL_ALPHA);
}

MomoVehicle::~MomoVehicle()
{
    delete box;
}

void MomoVehicle::shape()
{

    glEnable(GL_TEXTURE_2D);

    /* Assignation for the display List */
    displayList = glGenLists(1);
    glNewList(displayList, GL_COMPILE);

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, listeTexture[1]);
    glBegin(GL_QUADS);
    // The bottom square quads
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(width / 2, 0, -length / 4);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-width / 2, 0, -length / 4);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-width / 2, 0, length / 4);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(width / 2, 0, length / 4);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(width / 2, 0, -length / 4);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-width / 2, 0, -length / 4);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-width / 2, height, -length / 4);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(width / 2, height, -length / 4);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(width / 2, height, length / 4);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-width / 2, height, length / 4);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-width / 2, 0, length / 4);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(+width / 2, 0, length / 4);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(width / 2, 0, -length / 4);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(width / 2, 0, length / 4);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(width / 2, height, length / 4);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(width / 2, height, -length / 4);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-width / 2, 0, -length / 4);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-width / 2, 0, length / 4);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-width / 2, height, length / 4);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-width / 2, height, -length / 4);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, listeTexture[0]);
    glBegin(GL_QUADS);
    // The hight square quad
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(width / 2, height, -length / 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-width / 2, height, -length / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-width / 2, height, length / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(width / 2, height, length / 2);
    glEnd();

    glEndList();
}
