/**-----------------------------------------------------------------------------
 * Release - KallistiOS 1.2.0
 *
 * Init.cpp : initialisation code. Init OpenGl and Kos
 *
 *
 * version - v1.0
 *
 * (c) 2004 DreamTeamCast
 *
 *--------------------=+ Drinving Curse Syndrom : Ignition +=--------------------
*/

#include "Init.h"

pvr_init_params_t param = {
    /* Enable opaque and translucent polygons with size 16 */
    {PVR_BINSIZE_16, PVR_BINSIZE_0, PVR_BINSIZE_16, PVR_BINSIZE_0, PVR_BINSIZE_0},

    /* Vertex buffer size 512K */
    512 * 512};

void init()
{
    /* Kos initialisation */
    pvr_init(&param);

    /* initialise Kgl */
    glKosInit();

    initGL();
}

void initGL()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, 640.0f / 480.0f, 0.1f, 100.0f);
    //gluLookAt(-155.0f, 75.0f , 35.0f, -155.0f, 75.0f, 40.0f, 0.0f, 1.0f, 0.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glFrontFace(GL_CCW);

    //glClearColor(0.3f, 0.5f, 0.7f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glColor4f(1.0f, 1.0f, 1.0f, 0.5);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
