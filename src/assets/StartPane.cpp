#include "StartPane.h"

StartPane::StartPane(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat h, GLfloat l) : GraphicalElement(x, y, z), width(w), height(h), length(l)
{
    createTexturePNG("/rd/porte15.png", PNG_FULL_ALPHA);
    createTexturePNG("/rd/flamme.png", PNG_FULL_ALPHA);
    createTexturePNG("/rd/start.png", PNG_FULL_ALPHA);
}

StartPane::~StartPane() {}

void StartPane::shape()
{
    float x, y, z;

    x = position.x - width / 2;
    y = position.y - height / 2;
    z = position.z - length / 2;

    glEnable(GL_TEXTURE_2D);
    glDisable(GL_CULL_FACE);

    /* Assignation for the display List */
    displayList = glGenLists(1);
    glNewList(displayList, GL_COMPILE);

    glBindTexture(GL_TEXTURE_2D, listeTexture[0]);
    glBegin(GL_QUADS);
    /* The left column */
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x - (length - 10) / 2, y, z - 2.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x - (length - 10) / 2, y, z + 2.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x - (length - 10) / 2, y + height - 5, z + 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x - (length - 10) / 2, y + height - 5, z - 2.5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x - length / 2, y, z - 2.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x - length / 2, y, z + 2.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x - length / 2, y + height - 5, z + 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x - length / 2, y + height - 5, z - 2.5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x - length / 2, y, z + 2.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x - (length - 10) / 2, y, z + 2.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x - (length - 10) / 2, y + height - 5, z + 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x - length / 2, y + height - 5, z + 2.5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x - length / 2, y, z - 2.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x - (length - 10) / 2, y, z - 2.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x - (length - 10) / 2, y + height - 5, z - 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x - length / 2, y + height - 5, z - 2.5);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x - (length - 10) / 2, y + height - 5, z + 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x - (length - 10) / 2, y + height - 5, z - 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x - length / 2, y + height - 5, z - 2.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x - length / 2, y + height - 5, z + 2.5);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, listeTexture[0]);
    glBegin(GL_QUADS);
    /* The right column */
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + (length - 10) / 2, y, z - 2.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + (length - 10) / 2, y, z + 2.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + (length - 10) / 2, y + height - 5, z + 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + (length - 10) / 2, y + height - 5, z - 2.5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + length / 2, y, z - 2.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + length / 2, y, z + 2.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + length / 2, y + height - 5, z + 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + length / 2, y + height - 5, z - 2.5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + length / 2, y, z + 2.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + (length - 10) / 2, y, z + 2.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + (length - 10) / 2, y + height - 5, z + 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + length / 2, y + height - 5, z + 2.5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + length / 2, y, z - 2.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + (length - 10) / 2, y, z - 2.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + (length - 10) / 2, y + height - 5, z - 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + length / 2, y + height - 5, z - 2.5);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + (length - 10) / 2, y + height - 5, z + 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + (length - 10) / 2, y + height - 5, z - 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + length / 2, y + height - 5, z - 2.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + length / 2, y + height - 5, z + 2.5);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, listeTexture[2]);
    glBegin(GL_QUADS);
    /* The flag */
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + (length - 10) / 2, y + height - 15, z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + (length - 10) / 2, y + height - 5, z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x - (length - 10) / 2, y + height - 5, z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x - (length - 10) / 2, y + height - 15, z);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, listeTexture[1]);
    glBegin(GL_QUADS);
    /* The left fire */
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x - (length - 10) / 2 + 10, y + height - 5, z + 2.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x - length / 2 - 10, y + height - 5, z - 2.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x - length / 2 - 10, y + height + 10, z - 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x - (length - 10) / 2 + 10, y + height + 10, z + 2.5);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, listeTexture[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x - length / 2 - 10, y + height - 5, z + 2.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x - (length - 10) / 2 + 10, y + height - 5, z - 2.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x - (length - 10) / 2 + 10, y + height + 10, z - 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x - length / 2 - 10, y + height + 10, z + 2.5);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, listeTexture[1]);
    glBegin(GL_QUADS);
    /* The right fire */
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + (length - 10) / 2 - 10, y + height - 5, z + 2.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + length / 2 + 10, y + height - 5, z - 2.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + length / 2 + 10, y + height + 10, z - 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + (length - 10) / 2 - 10, y + height + 10, z + 2.5);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, listeTexture[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + length / 2 + 10, y + height - 5, z + 2.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + (length - 10) / 2 - 10, y + height - 5, z - 2.5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + (length - 10) / 2 - 10, y + height + 10, z - 2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + length / 2 + 10, y + height + 10, z + 2.5);
    glEnd();
    glEndList();
}
