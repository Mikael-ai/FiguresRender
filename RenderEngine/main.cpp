#include <windows.h>
#include <gl/gl.h>

#include "App.h"

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    int result = App::getInstance(hInstance, nCmdShow)->init();

    return result;
}
