#include "Landscape.h"

/*
 *  Constructor to do a landScape
 *  Parameters : int jpeg :                   indicate if we use a jpeg
 * 								                       use with : NJPEG or JPEG
 * 						char *fileTxrJpg :   jpeg file
 * 						char *txr :   texture file (4 the moment : only pcx)
 * 					   flat dimension : ras
 * 					   int subdiv1 : number of subdivision for all the triangles
 * 					   int nbSubDiv : ras
 */
Landscape::Landscape(int jpeg, char *fileTxrJpg, char *txr, float dim, int subdiv1, int f, float fMult, float fAdd, GLfloat red, GLfloat green, GLfloat blue) : dimension(dim), nbSubdiv(subdiv1), factor(f), factorMult(fMult), factorAdd(fAdd), r(red), g(green), b(blue)
{
    /* Load the JpegFile */
    if (jpeg == JPEG)
    {
        loadJpeg(fileTxrJpg);
    }
    else
    {
        for (int i = 0; i < SIZEMAP; i++)
            for (int j = 0; j < SIZEMAP; j++)
                image[i][j] = fAdd;
    }

    createTexturePCX(txr, listeTexture.size());

    pas = dimension / nbSubdiv;
}

Landscape::~Landscape() {}

void Landscape::loadJpeg(char *filename)
{
    FILE *file;
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    unsigned char *im, *ligne;

    im = (unsigned char *)image;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);

    if (!(file = fopen(filename, "rb")))
    {
        printf("Failed open the file %s\n", filename);
        return;
    }

    jpeg_stdio_src(&cinfo, file);
    jpeg_read_header(&cinfo, TRUE);
    if ((cinfo.image_width != 256) || (cinfo.image_height != 256))
    {
        printf("Failed : image must be 256x256\n");
        return;
    }

    if (cinfo.out_color_space != JCS_GRAYSCALE)
    {
        printf("Failed : image must be GrayScale \n");
        return;
    }
    jpeg_start_decompress(&cinfo);

    while (cinfo.output_scanline < 256)
    {
        ligne = im + 256 * cinfo.output_scanline;
        jpeg_read_scanlines(&cinfo, &ligne, 1);
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
}

float Landscape::getHautPoint(float x, float z)
{

    int i, j;
    float ext = dimension / 2;

    i = (2 * x + dimension) / (2 * pas);
    j = (2 * z + dimension) / (2 * pas);

    return ((elevation(i, j) * factorMult) + factorAdd);
}

//tells the y of point (x, y, z) on the terrain, where x and z are parameters
float Landscape::getYFromXZ(float x, float z)
{
    int i, j;
    float ext = dimension / 2;

    i = (2 * x + dimension) / (2 * pas);
    j = (2 * z + dimension) / (2 * pas);

    //return elevation(i, j)* factorMult + factorAdd;
    float P1[3], P2[3], P3[3], P4[3];

    P1[0] = -ext + i * pas;
    P1[1] = elevation(i, j) * factorMult + factorAdd;
    P1[2] = -ext + j * pas;
    P2[0] = -ext + (i + 1) * pas;
    P2[1] = elevation(i + 1, j) * factorMult + factorAdd;
    P2[2] = -ext + j * pas;
    P3[0] = -ext + (i + 1) * pas;
    P3[1] = elevation(i + 1, j + 1) * factorMult + factorAdd;
    P3[2] = -ext + (j + 1) * pas;
    P4[0] = -ext + i * pas;
    P4[1] = elevation(i, j + 1) * factorMult + factorAdd;
    P4[2] = -ext + (j + 1) * pas;
    Vector3D Tri11[3] = {Vector3D(P4[0], 0, P4[2]), Vector3D(P3[0], 0, P3[2]), Vector3D(P1[0], 0, P1[2])};
    Vector3D Tri12[3] = {Vector3D(P3[0], 0, P3[2]), Vector3D(P2[0], 0, P2[2]), Vector3D(P1[0], 0, P1[2])};
    Vector3D Tri21[3] = {Vector3D(P4[0], P4[1], P4[2]), Vector3D(P3[0], P3[1], P3[2]), Vector3D(P1[0], P1[1], P1[2])};
    Vector3D Tri22[3] = {Vector3D(P3[0], P3[1], P3[2]), Vector3D(P2[0], P2[1], P2[2]), Vector3D(P1[0], P1[1], P1[2])};

    Vector3D *tri;
    Vector3D point(x, 0, z);
    if (isInsidePoly(Tri11, 3, point))
        tri = Tri21;
    else
    {
        if (isInsidePoly(Tri12, 3, point))
            tri = Tri22;
        else
        {
            //probleme...
            //printf ("dans aucun triangle !!!!!!!!!\n");
            return ERR;
        }
    }

    //get the normalized normal of the hit plan :
    Vector3D normTriTmp = getNormalOfPoly(tri);
    Vector3D normTri = normTriTmp.Normalized();
    float dPlane = planeDistanceFromOrigin(normTri, tri[0]);

    //we look for y in : Ax + By + Cz + D = 0
    //By = -(Ax + Cz + D)
    //y = [-(Ax + Cz + D)] / B

    float Ax = x * normTri.x;
    float Cz = z * normTri.z;
    float By = -(dPlane + Ax + Cz);
    float y = By / normTri.y;

    return y;

    /*
  float dPoint1 = getDistanceFromPlane (vec1, normTri, dPlane);
  float dPoint2 = getDistanceFromPlane (vec2, normTri, dPlane);

  //now find the projection of the points on the plane :
  Vector3D tmp1 = dPoint1 * normTri;
  Vector3D ptProj1 = vec1 - tmp1;
  vecRes1 = &ptProj1;

  Vector3D tmp2 = dPoint2 * normTri;
  Vector3D ptProj2 = vec2 - tmp2;
  vecRes2 = &ptProj2;
*/
    //	return ptProj;
}

//put in vecRes1 and vecRes2 the projection of (x1,0,z1) and (x2,0,z2) on the plane of the triangle of the terrain (x1,0,z1) is on
void Landscape::getProjPoint(const Vector3D &vec1, const Vector3D &vec2, Vector3D *vecRes1, Vector3D *vecRes2)
{
    int i, j;
    float ext = dimension / 2;

    i = (2 * vec1.x + dimension) / (2 * pas);
    j = (2 * vec1.z + dimension) / (2 * pas);

    //	return elevation(i, j)* factorMult + factorAdd;
    float P1[3], P2[3], P3[3], P4[3];

    P1[0] = -ext + i * pas;
    P1[1] = elevation(i, j) * factorMult + factorAdd;
    P1[2] = -ext + j * pas;
    P2[0] = -ext + (i + 1) * pas;
    P2[1] = elevation(i + 1, j) * factorMult + factorAdd;
    P2[2] = -ext + j * pas;
    P3[0] = -ext + (i + 1) * pas;
    P3[1] = elevation(i + 1, j + 1) * factorMult + factorAdd;
    P3[2] = -ext + (j + 1) * pas;
    P4[0] = -ext + i * pas;
    P4[1] = elevation(i, j + 1) * factorMult + factorAdd;
    P4[2] = -ext + (j + 1) * pas;

    Vector3D Tri11[3] = {Vector3D(P4[0], 0, P4[2]), Vector3D(P3[0], 0, P3[2]), Vector3D(P1[0], 0, P1[2])};
    Vector3D Tri12[3] = {Vector3D(P3[0], 0, P3[2]), Vector3D(P2[0], 0, P2[2]), Vector3D(P1[0], 0, P1[2])};

    Vector3D Tri21[3] = {Vector3D(P4[0], P4[1], P4[2]), Vector3D(P3[0], P3[1], P3[2]), Vector3D(P1[0], P1[1], P1[2])};
    Vector3D Tri22[3] = {Vector3D(P3[0], P3[1], P3[2]), Vector3D(P2[0], P2[1], P2[2]), Vector3D(P1[0], P1[1], P1[2])};

    Vector3D *tri;
    Vector3D point1(vec1.x, 0, vec1.z);
    Vector3D point2(vec2.x, 0, vec2.z);
    if (isInsidePoly(Tri11, 3, point1))
        tri = Tri21;
    else
    {
        if (isInsidePoly(Tri12, 3, point1))
            tri = Tri22;
        else
        {
            //probleme...
            printf("dans aucun triangle !!!!!!!!!\n");
            vecRes1 = NULL;
            vecRes2 = NULL;
            return;
        }
    }

    //get the normalized normal of the hit plan :
    Vector3D normTriTmp = getNormalOfPoly(tri);
    Vector3D normTri = normTriTmp.Normalized();
    float dPlane = planeDistanceFromOrigin(normTri, tri[0]);
    float dPoint1 = getDistanceFromPlane(vec1, normTri, dPlane);
    float dPoint2 = getDistanceFromPlane(vec2, normTri, dPlane);

    //now find the projection of the points on the plane :
    Vector3D tmp1 = dPoint1 * normTri;
    Vector3D ptProj1 = vec1 - tmp1;
    vecRes1 = &ptProj1;

    Vector3D tmp2 = dPoint2 * normTri;
    Vector3D ptProj2 = vec2 - tmp2;
    vecRes2 = &ptProj2;

    //	return ptProj;
}

double Landscape::elevation(int i, int j)
{
    int valeur = image[(int)((float)i / nbSubdiv * 255)][(int)((float)j / nbSubdiv * 255)];
    return valeur * ECHELLE_VERT_INIT;
}

void Landscape::shape()
{
    int i, j;
    float pas2 = dimension;
    float ext = pas2 / 2;
    float P1[3], P2[3], P3[3], P4[3];

    //pas = pas2/nbSubdiv;
    pas2 = pas2 / factor;
    /* Liste pour l'objet terrain */
    displayList = glGenLists(1);
    glNewList(displayList, GL_COMPILE);

    glColor3f(r, g, b);
    for (i = 0; i < nbSubdiv; i++)
        for (j = 0; j < nbSubdiv; j++)
        {
            P1[0] = -ext + i * pas;
            P1[1] = elevation(i, j) * factorMult + factorAdd;
            P1[2] = -ext + j * pas;
            P2[0] = -ext + (i + 1) * pas;
            P2[1] = elevation(i + 1, j) * factorMult + factorAdd;
            P2[2] = -ext + j * pas;
            P3[0] = -ext + (i + 1) * pas;
            P3[1] = elevation(i + 1, j + 1) * factorMult + factorAdd;
            P3[2] = -ext + (j + 1) * pas;
            P4[0] = -ext + i * pas;
            P4[1] = elevation(i, j + 1) * factorMult + factorAdd;
            P4[2] = -ext + (j + 1) * pas;

            glBegin(GL_TRIANGLES);

            glBindTexture(GL_TEXTURE_2D, listeTexture[0]);
            /* Triangle 1 */
            glTexCoord2f((j + 1) * pas / pas2, i * pas / pas2);
            glVertex3fv(P4);
            glTexCoord2f((j + 1) * pas / pas2, (i + 1) * pas / pas2);
            glVertex3fv(P3);
            glTexCoord2f(j * pas / pas2, i * pas / pas2);
            glVertex3fv(P1);

            /* Triangle 2 */
            glTexCoord2f((j + 1) * pas / pas2, (i + 1) * pas / pas2);
            glVertex3fv(P3);
            glTexCoord2f(j * pas / pas2, (i + 1) * pas / pas2);
            glVertex3fv(P2);
            glTexCoord2f(j * pas / pas2, i * pas / pas2);
            glVertex3fv(P1);
            glEnd();
        }
    glColor3f(1.0f, 1.0f, 1.0f);
    glEndList();
}

float Landscape::getPas()
{
    return pas;
}
