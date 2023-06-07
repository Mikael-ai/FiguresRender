#include "App.h"
#include "ShapeDrawer.h"
#include "ShapeCreator.h"

App *App::appInstance = nullptr;

LRESULT CALLBACK WindowProc(HWND hwnd, 
                            UINT uMsg, 
                            WPARAM wParam, 
                            LPARAM lParam);

App::App() :
    m_hInstance(NULL),
    m_hAppWindow(NULL),
    m_nCmdShow(NULL),
    m_isRun(false),
    m_currentShape(Shapes::Quad),
    m_currentEnumId(0),
    m_currentScale(0.5f)
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
    this->m_hInstance = hInstance;
    this->m_nCmdShow = nCmdShow;
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
    wcex.hInstance = m_hInstance;
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
                                  m_hInstance,
                                  NULL);

    ShowWindow(m_hAppWindow, m_nCmdShow);

    m_currentShapeVertices = ShapeFabric::createBasicShape(m_currentShape);
    m_isRun = true;

    return true;
}

bool App::isRun() const
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
            ShapeDrawer::drawShape(m_currentShapeVertices, 
                                   m_currentScale, 
                                   &hDC);
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

void App::nextShape()
{
    if (++m_currentEnumId >= (sizeof(shapesEntry) / sizeof(shapesEntry[0])))
    {
        m_currentEnumId = 0;
        m_currentShape = shapesEntry[m_currentEnumId].shape;
    }
    else
    {
        m_currentShape = shapesEntry[m_currentEnumId].shape;
    }

    m_currentShapeVertices = ShapeFabric::createBasicShape(m_currentShape);
}

void App::setCurrentScale(const float scale)
{
    m_currentScale = (scale > 0.0f) ? scale : 1.0f;
}

float App::getCurrentScale() const
{
    return m_currentScale;
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

LRESULT CALLBACK WindowProc(HWND hwnd, 
                            UINT uMsg, 
                            WPARAM wParam,
                            LPARAM lParam)
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
        {
            PostQuitMessage(0);
            break;
        }
        case VK_SPACE:
        {
            App::getInstance()->nextShape();
            break;
        }
        case VK_UP:
        {
            const float currentScale = App::getInstance()->getCurrentScale();
            App::getInstance()->setCurrentScale(currentScale + 0.1f);
            break;
        }
        case VK_DOWN:
        {
            const float currentScale = App::getInstance()->getCurrentScale();
            App::getInstance()->setCurrentScale(currentScale - 0.1f);
            break;
        }
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
