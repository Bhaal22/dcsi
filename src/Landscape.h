#ifndef __LANDSCAPEH__
#define __LANDSCAPEH__

#include "GraphicalElement.h"

#define NB_SUBDIV_INIT 32
#define NB_SUBDIV_MAX 64
#define ECHELLE_VERT_INIT 0.5
#define ECHELLE_VERT_MAX 1.0
#define DISTANCE_INIT 4.0
#define ERR -257

class Landscape : public GraphicalElement
{
public:
    Landscape(int, char *, char *, float, int, int, float, float, GLfloat = 1.0f, GLfloat = 1.0f, GLfloat = 1.0f);
    ~Landscape();

    /* Virtual Method */
    void shape();

    /* Method for loading a jpeg file */
    void loadJpeg(char *);
    float getHautPoint(float x, float z);
    void getProjPoint(const Vector3D &vec1, const Vector3D &vec2, Vector3D *vecRes1, Vector3D *vecRes2);
    float getYFromXZ(float x, float z);
    double elevation(int, int);

    float getPas();

protected:
    //unsigned char **image;
    unsigned char image[256][256];
    float dimension;
    int nbSubdiv;
    int factor;
    float factorMult, factorAdd;
    float pas;
    GLfloat r, g, b;
};

#endif
