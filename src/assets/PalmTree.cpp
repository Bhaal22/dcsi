#include "PalmTree.h"

PalmTree::PalmTree(char *fn, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat h, GLfloat l) : GraphicalElement(x, y, z), width(w), height(h), length(l)
{
    createTexturePNG(fn, PNG_FULL_ALPHA, 0);
    r = g = b = 1.0f;
}

PalmTree::~PalmTree()
{
    delete box;
}

void PalmTree::shape()
{
    float x, y, z;

    x = position.x - width / 2;
    y = position.y - height / 2;
    z = position.z - length / 2;

    glEnable(GL_TEXTURE_2D);

    /* Display the textures both side  the polygons*/
    glDisable(GL_CULL_FACE);

    /* Assignation for the display List */
    displayList = glGenLists(1);
    glNewList(displayList, GL_COMPILE);

    glColor3f(r, g, b);
    glBindTexture(GL_TEXTURE_2D, listeTexture[0]);

    glBegin(GL_QUADS);
    // Assign the texture coordinates and vertices for the FRONT Side
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x, y, z + length);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x, y + height, z + length);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + width, y + height, z + length);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + width, y, z + length);
    glEnd();

    //glBindTexture(GL_TEXTURE_2D, listeTexture[0]);
    glBegin(GL_QUADS);
    // Assign the texture coordinates and vertices for the FRONT Side
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + width / 2, y, z + length / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + width / 2, y, z + 3 * length / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + width / 2, y + height, z + 3 * length / 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + width / 2, y + height, z + length / 2);

    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glEndList();
}

void PalmTree::setColor(GLfloat r, GLfloat g, GLfloat b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}
