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
                            const float rotation,
                            HDC *hDC)
{
    glClearColor(0.85f, 0.6f, 0.6f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glScalef(scale, scale, scale);
    glRotatef(rotation, 0.0f, 0.0f, 1.0f);
    
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
