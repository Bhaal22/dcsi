#include "OisisVehicle.h"

OisisVehicle::OisisVehicle(GLfloat x, GLfloat y, GLfloat z, GLfloat xFront, GLfloat yFront, GLfloat zFront, GLfloat w, GLfloat h, GLfloat l, float hOffset) : Vehicle(x, y, z, xFront, yFront, zFront, w, h, l, hOffset)
{
    createTexturePNG("/rd/vehicles/oisis/oisis.PNG", PNG_FULL_ALPHA);
    createTexturePNG("/rd/vehicles/oisis/bouchon.png", PNG_FULL_ALPHA);
    createTexturePNG("/rd/vehicles/oisis/orange.png", PNG_FULL_ALPHA);
}

OisisVehicle::~OisisVehicle() {}

void OisisVehicle::shape()
{

    glEnable(GL_TEXTURE_2D);

    /* Assignation for the display List */
    displayList = glGenLists(1);
    glNewList(displayList, GL_COMPILE);

    glBindTexture(GL_TEXTURE_2D, listeTexture[0]);
    glBegin(GL_QUADS);
    /* The square quads */
    glTexCoord2f(0.2f, 1.0f);
    glVertex3f(length / 2, 0, -(width / 2 - width / 3));
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-length / 2, 0, -(width / 2 - width / 3));
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-length / 2, 0, (width / 2 - width / 3));
    glTexCoord2f(0.2f, 0.0f);
    glVertex3f(length / 2, 0, (width / 2 - width / 3));

    glTexCoord2f(0.2f, 1.0f);
    glVertex3f(length / 2, height, -width / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-length / 2, height, -width / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-length / 2, height, (width / 2 - width / 3));
    glTexCoord2f(0.2f, 0.0f);
    glVertex3f(length / 2, height, (width / 2 - width / 3));

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(length / 2, 0, -width / 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(length / 2, 0, (width / 2 - width / 3));
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(length / 2, height, (width / 2 - width / 3));
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(length / 2, height, -width / 2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-length / 2, 0, -width / 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-length / 2, 0, (width / 2 - width / 3));
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-length / 2, height, (width / 2 - width / 3));
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-length / 2, height, -width / 2);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, listeTexture[2]);
    glBegin(GL_QUADS);
    /* The bottom of the bottle */
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(length / 2, 0, -width / 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-length / 2, 0, -width / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-length / 2, height, -width / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(length / 2, height, -width / 2);

    /* The hight part */
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(length / 4, 3 * height / 4, (width / 2 - width / 12));
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-length / 4, 3 * height / 4, (width / 2 - width / 12));
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-length / 2, height, (width / 2 - width / 3));
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(length / 2, height, (width / 2 - width / 3));

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(length / 4, height / 4, (width / 2 - width / 12));
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-length / 4, height / 4, (width / 2 - width / 12));
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-length / 2, 0, (width / 2 - width / 3));
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(length / 2, 0, (width / 2 - width / 3));

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(length / 4, 3 * height / 4, (width / 2 - width / 12));
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(length / 4, height / 4, (width / 2 - width / 12));
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(length / 2, 0, (width / 2 - width / 3));
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(length / 2, height, (width / 2 - width / 3));

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-length / 4, 3 * height / 4, (width / 2 - width / 12));
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-length / 4, height / 4, (width / 2 - width / 12));
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-length / 2, 0, (width / 2 - width / 3));
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-length / 2, height, (width / 2 - width / 3));
    glEnd();

    glBindTexture(GL_TEXTURE_2D, listeTexture[1]);
    glBegin(GL_QUADS);
    /* The stopper */
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-length / 4, 3 * height / 4, (width / 2 - width / 12));
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-length / 4, height / 4, (width / 2 - width / 12));
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-length / 4, height / 4, width / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-length / 4, 3 * height / 4, width / 2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(length / 4, 3 * height / 4, (width / 2 - width / 12));
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(length / 4, height / 4, (width / 2 - width / 12));
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(length / 4, height / 4, width / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(length / 4, 3 * height / 4, width / 2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(length / 4, 3 * height / 4, (width / 2 - width / 12));
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-length / 4, 3 * height / 4, (width / 2 - width / 12));
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-length / 4, 3 * height / 4, width / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(length / 4, 3 * height / 4, width / 2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(length / 4, height / 4, (width / 2 - width / 12));
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-length / 4, height / 4, (width / 2 - width / 12));
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-length / 4, height / 4, width / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(length / 4, height / 4, width / 2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(length / 4, 3 * height / 4, width / 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-length / 4, 3 * height / 4, width / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-length / 4, height / 4, width / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(length / 4, height / 4, width / 2);
    glEnd();

    glEndList();
}
