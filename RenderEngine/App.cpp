#include "App.h"
#include "ShapeDrawer.h"
#include "ShapeCreator.h"

App* App::appInstance = nullptr;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

App::App() : 
    hInstance(NULL),
    m_hAppWindow(NULL),
    nCmdShow(NULL),
    m_isRun(false),
    currentShape(Shapes::Circle)
{
}

App::~App()
{
    if (appInstance)
    {
        delete appInstance;
        appInstance = nullptr;
    }
}

App *App::getInstance()
{
    if (!appInstance)
        appInstance = new App();

    return appInstance;
}

void App::setup(HINSTANCE hInstance, int nCmdShow)
{
    this->hInstance = hInstance;
    this->nCmdShow = nCmdShow;
}

bool App::init()
{
    WNDCLASSEX wcex;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = L"GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return false;

    /* create main window */
    m_hAppWindow = CreateWindowEx(0,
                          L"GLSample",
                          L"OpenGL Sample",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          512,
                          512,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(m_hAppWindow, nCmdShow);
    
    currentShapeVertices = ShapeCreator::createBasicShape(currentShape);
    m_isRun = true;

    return true;
}

bool App::isRun()
{
    return m_isRun;
}

int App::broadCast()
{
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;

    /* enable OpenGL for the window */
    EnableOpenGL(m_hAppWindow, &hDC, &hRC);

    ShapeDrawer shapeDrawer;

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */
            ShapeDrawer::drawShape(currentShapeVertices, 1.0f, &hDC);
            Sleep(1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(m_hAppWindow, hDC, hRC);

    m_isRun = false;

    return msg.wParam;
}

void App::onDestroy()
{
    DestroyWindow(m_hAppWindow);
}

void App::EnableOpenGL(HWND hwnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
        PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}

void App::DisableOpenGL(HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
    {
        PostQuitMessage(0);
        break;
    }

    case WM_DESTROY:
    {
        App::getInstance()->onDestroy();
        return 0;
    }

    case WM_KEYDOWN:
    {
        switch (wParam)
        {
        case VK_ESCAPE:
        PostQuitMessage(0);
        break;
        }
    }
    break;

    default:
    {
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    }

    return 0;
}
