#include <windows.h>
#include <gl/gl.h>

#include "App.h"

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    App app(hInstance, nCmdShow);
    int result = app.init();

    return result;
}
