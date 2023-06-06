#include <windows.h>
#include <gl/gl.h>

#include "App.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance,
                   _In_opt_ HINSTANCE hPrevInstance,
                   _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow)
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
