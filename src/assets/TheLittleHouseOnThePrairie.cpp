#include "TheLittleHouseOnThePrairie.h"

TheLittleHouseOnThePrairie::TheLittleHouseOnThePrairie(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat h, GLfloat l) : GraphicalElement(x, y, z), width(w), height(h), length(l)
{
    createTexturePNG("/rd/bois02.png", PNG_FULL_ALPHA);
    createTexturePNG("/rd/porte15.png", PNG_FULL_ALPHA);
    createTexturePNG("/rd/desert05.png", PNG_FULL_ALPHA);
    createTexturePCX("/rd/bois24.pcx");
}

TheLittleHouseOnThePrairie::~TheLittleHouseOnThePrairie()
{
    delete box;
}

void TheLittleHouseOnThePrairie::shape()
{
    float x, y, z;

    x = position.x - width / 2;
    y = position.y - height / 2;
    z = position.z - length / 2;

    glEnable(GL_TEXTURE_2D);

    /* Assignation for the display List */
    displayList = glGenLists(1);
    glNewList(displayList, GL_COMPILE);

    glBindTexture(GL_TEXTURE_2D, listeTexture[0]);

    glBegin(GL_QUADS);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x, y, z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 10.0, y, z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + 10.0, y + 15, z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x, y + 15.0, z);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + 20.0, y, z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 30.0, y, z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + 30.0, y + 15, z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + 20.0, y + 15.0, z);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + 30.0, y, z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 30.0, y, z - 20.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + 30.0, y + 15, z - 20.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + 30.0, y + 15.0, z);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x, y, z - 20.0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 10.0, y, z - 20.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + 10.0, y + 15, z - 20.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x, y + 15.0, z - 20.0);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + 10.0, y, z - 20.0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 20.0, y, z - 20.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + 20.0, y + 15.0, z - 20.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + 10.0, y + 15.0, z - 20.0);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + 20.0, y, z - 20.0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 30.0, y, z - 20.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + 30.0, y + 15, z - 20.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + 20.0, y + 15.0, z - 20.0);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x, y, z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x, y, z - 20.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x, y + 15, z - 20.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x, y + 15.0, z);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, listeTexture[1]);
    glBegin(GL_QUADS);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + 10.0, y, z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + 20.0, y, z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + 20.0, y + 15.0, z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 10.0, y + 15.0, z);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, listeTexture[2]);
    glBegin(GL_QUADS);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + 10.0, y + 14.5, z + 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + 20.0, y + 14.5, z + 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + 20.0, y + 21.0, z - 10.0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 10.0, y + 21.0, z - 10.0);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + 10.0, y + 14.5, z - 22);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + 20.0, y + 14.5, z - 22);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + 20.0, y + 21.0, z - 10.0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 10.0, y + 21.0, z - 10.0);

    glEnd();

    glBegin(GL_TRIANGLES);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x - 2, y + 14.5, z + 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 10, y + 14.5, z + 2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + 10, y + 21.0, z - 10.0);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + 20, y + 14.5, z + 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 32, y + 14.5, z + 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + 20, y + 21.0, z - 10.0);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x - 2, y + 14.5, z - 22);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 10, y + 14.5, z - 22);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + 10, y + 21.0, z - 10.0);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + 20, y + 14.5, z - 22);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 32, y + 14.5, z - 22);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + 20, y + 21.0, z - 10.0);

    glTexCoord2f(0.0f, 2.0f);
    glVertex3f(x - 2, y + 14.5, z - 22);
    glTexCoord2f(2.0f, 2.0f);
    glVertex3f(x - 2, y + 14.5, z + 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 10, y + 21.0, z - 10.0);

    glTexCoord2f(0.0f, 2.0f);
    glVertex3f(x + 32.0, y + 14.5, z - 22);
    glTexCoord2f(2.0f, 2.0f);
    glVertex3f(x + 32.0, y + 14.5, z + 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + 20, y + 21.0, z - 10.0);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, listeTexture[3]);
    glBegin(GL_QUADS);

    glTexCoord2f(2.0f, 0.0f);
    glVertex3f(x - 10.0, y, z + 10);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + 40.0, y, z + 10);
    glTexCoord2f(0.0f, 3.0f);
    glVertex3f(x + 40.0, y, z - 30.0);
    glTexCoord2f(2.0f, 3.0f);
    glVertex3f(x - 10.0, y, z - 30.0);

    glTexCoord2f(2.0f, 0.0f);
    glVertex3f(x - 10.0, y - 0.8, z + 10);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + 40.0, y - 0.8, z + 10);
    glTexCoord2f(0.0f, 3.0f);
    glVertex3f(x + 40.0, y - 0.8, z - 30.0);
    glTexCoord2f(2.0f, 3.0f);
    glVertex3f(x - 10.0, y - 0.8, z - 30.0);

    glTexCoord2f(2.0f, 0.0f);
    glVertex3f(x - 10.0, y - 0.8, z + 10);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + 40.0, y - 0.8, z + 10);
    glTexCoord2f(0.0f, 0.24f);
    glVertex3f(x + 40.0, y, z + 10);
    glTexCoord2f(2.0f, 0.24f);
    glVertex3f(x - 10.0, y, z + 10);

    glTexCoord2f(2.0f, 0.0f);
    glVertex3f(x - 10.0, y - 0.8, z - 30);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + 40.0, y - 0.8, z - 30);
    glTexCoord2f(0.0f, 0.24f);
    glVertex3f(x + 40.0, y, z - 30);
    glTexCoord2f(2.0f, 0.24f);
    glVertex3f(x - 10.0, y, z - 30);

    glTexCoord2f(0.16f, 0.0f);
    glVertex3f(x - 10.0, y - 0.8, z - 30);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x - 10, y - 0.8, z + 10);
    glTexCoord2f(0.0f, 3.0f);
    glVertex3f(x - 10, y, z + 10);
    glTexCoord2f(0.16f, 3.0f);
    glVertex3f(x - 10.0, y, z - 30);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + 40.0, y - 0.8, z - 30);
    glTexCoord2f(0.84f, 0.0f);
    glVertex3f(x + 40.0, y - 0.8, z + 10);
    glTexCoord2f(0.84f, 3.0f);
    glVertex3f(x + 40.0, y, z + 10);
    glTexCoord2f(1.0f, 3.0f);
    glVertex3f(x + 40.0, y, z - 30);

    glEnd();
    glEndList();
}
