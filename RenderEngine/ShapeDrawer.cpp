#include <windows.h>
#include <gl/gl.h>

#include "ShapeDrawer.h"
#include "ShapeCreator.h"

#include <vector>


ShapeDrawer::ShapeDrawer()
{
}

ShapeDrawer::~ShapeDrawer()
{
}

void ShapeDrawer::drawShape(const std::vector<POINTFLOAT> &vertices,
                            const float scale, 
                            HDC *hDC)
{
    ShapeCreator shapeCreator;
    //std::vector<POINTFLOAT> vertices = shapeCreator.createBasicShape(shape);

    glClearColor(0.85f, 0.6f, 0.6f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.2f, 0.6f, 0.7f);
    for (const auto &point : vertices)
    {
        glVertex2f(point.x, point.y);
    }
    glEnd();

    glPopMatrix();

    SwapBuffers(*hDC);
}
