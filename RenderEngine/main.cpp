#include <windows.h>
#include <gl/gl.h>

#include "App.h"

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    App *app = App::getInstance();
    app->setup(hInstance, nCmdShow);
    int result = app->init();

    int wParam = 0;
    while (app->isRun())
    {
        wParam = app->broadCast();
    }

    return wParam;
}
