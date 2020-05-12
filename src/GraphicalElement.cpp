#include "GraphicalElement.h"

GraphicalElement::GraphicalElement(float x, float y, float z) : Element(x, y, z) {}

/* Load a PCX texture
 *
 * Parameters : none
 *
 * */
void GraphicalElement::createTexturePCX(char *fileName, int indiceTex)
{
    kos_img_t img;
    pvr_ptr_t txaddr;
    GLuint txr;

    if (pcx_to_img(fileName, &img) < 0)
    {
        printf("can't load %s\n", fileName);
        return;
    }

    txaddr = pvr_mem_malloc(img.w * img.h * 2);
    pvr_txr_load_kimg(&img, txaddr, PVR_TXRLOAD_INVERT_Y);
    kos_img_free(&img, 0);

    glGenTextures(1, &txr);

    /* insertion in the vector */
    listeTexture.push_back(txr);
    glBindTexture(GL_TEXTURE_2D, listeTexture.back());

    glKosTex2D(GL_RGB565_TWID, img.w, img.h, txaddr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_FILTER, GL_FILTER_BILINEAR);
}

/* Load a PNG texture
 *
 *  Parameters : constant which indicate if we use alpha or not
 *                        alpha = PNG_FULL_ALPHA or PNG_NO_ALPHA
 *
 * */
void GraphicalElement::createTexturePNG(char *fileName, int alpha, int indiceTex)
{
    kos_img_t img;
    pvr_ptr_t txaddr;
    GLuint txr;

    if (png_to_img(fileName, alpha, &img) < 0)
    {
        printf("can't load %s\n", fileName);
        return;
    }

    txaddr = pvr_mem_malloc(img.w * img.h * 2);
    pvr_txr_load_kimg(&img, txaddr, PVR_TXRLOAD_INVERT_Y);
    kos_img_free(&img, 0);

    glGenTextures(1, &txr);

    /* insertion in the vector */
    listeTexture.push_back(txr);
    glBindTexture(GL_TEXTURE_2D, listeTexture.back());

    glKosTex2D(GL_ARGB4444_TWID, img.w, img.h, txaddr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_FILTER, GL_FILTER_BILINEAR);
}

/* Display the Graphical Element */
void GraphicalElement::displayElement()
{
    glCallList(displayList);
}
