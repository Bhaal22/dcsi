#include "GraphicalElement.h"

class StartPane : public GraphicalElement
{
public:
    StartPane(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
    ~StartPane();

    void shape();

protected:
    GLfloat width, height, length;
};
