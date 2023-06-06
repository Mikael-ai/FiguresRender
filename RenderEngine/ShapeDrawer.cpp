#include <windows.h>
#include <gl/gl.h>

#include "ShapeDrawer.h"


ShapeDrawer::ShapeDrawer()
{

}

ShapeDrawer::~ShapeDrawer()
{
}

void ShapeDrawer::draw(HDC *hDC)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);

    glEnd();

    glPopMatrix();

    SwapBuffers(*hDC);
}
