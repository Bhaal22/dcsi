#pragma once

#include <vector>

#include "Element.h"
#include "Main.h"
#include <math3d.h>

class GraphicalElement : public Element
{
public:
    GraphicalElement(float, float, float);
    GraphicalElement(){};

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

