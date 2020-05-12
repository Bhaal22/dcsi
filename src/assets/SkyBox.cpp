#include "SkyBox.h"

SkyBox::SkyBox(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat h, GLfloat l) : GraphicalElement(x, y, z), width(w), height(h), length(l)
{
    createTexturePCX("/rd/skybox/back.pcx");
    createTexturePCX("/rd/skybox/front.pcx");
    createTexturePCX("/rd/skybox/top.pcx");
    createTexturePCX("/rd/skybox/right.pcx");
    createTexturePCX("/rd/skybox/left.pcx");
}

SkyBox::~SkyBox()
{
    delete box;
}

void SkyBox::quad(int noFace)
{
    float x = -1.0f;
    float y = -1.0f;

    float incr = 2.0f;

    glBindTexture(GL_TEXTURE_2D, listeTexture[noFace]);

    glBegin(GL_TRIANGLE_STRIP);
    while (x <= 1.0f - incr)
    {
        while (y <= 1.0f - incr)
        {
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x, y + incr, 0.0f);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x + incr, y + incr, 0.0f);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x + incr, y, 0.0f);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x, y + incr, 0.0f);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(x, y, 0.0f);

            y += incr;
        }
        y = -1.0f;
        x += incr;
    }
    glEnd();
}

void SkyBox::shape()
{
    //glTranslatef(0.0f, 1.0f, 0.0f);
    /* Front */
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 1.0f);
    quad(0);
    glPopMatrix();

    /* Back */
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -1.0f);
    glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
    glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
    quad(1);
    glPopMatrix();

    /*glPushMatrix();
  			glRotatef(90, 1.0f, 0.0f, 0.0f);
  			glTranslatef(0.0f, 0.0f, 1.0f);
  			quad(2);
  		glPopMatrix(); */

    glPushMatrix();
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 1.0f);
    quad(2);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 1.0f);
    quad(3);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 1.0f);
    quad(4);
    glPopMatrix();
}
