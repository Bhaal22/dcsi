#pragma once

#include "Element.h"
#include "Main.h"
#include <math3d.h>
#include <vector>
//#include "Texture.h"

class GraphicalElement : public Element
{
public:
    /* Constructor */
    GraphicalElement(float, float, float);
    GraphicalElement(){};

    /*  Destructor */
    virtual ~GraphicalElement() {}

    /* Virtual Method for painting the Element */
    virtual void shape() = 0;

    /* Methods for loading texture */
    void createTexturePCX(const char *);
    void createTexturePNG(const char *, int);

    /* Display the Graphical Element */
    void displayElement();

protected:
    GLuint displayList;
    std::vector<GLuint> listeTexture;
};

