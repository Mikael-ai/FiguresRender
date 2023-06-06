#pragma once
#include "windows.h"

class App {
public:
	App(HINSTANCE hInstance, 
		int nCmdShow);
	~App();

	int init();
	void EnableOpenGL(HWND hwnd, HDC *, HGLRC *);
	void DisableOpenGL(HWND, HDC, HGLRC);

	HINSTANCE hInstance;
	int nCmdShow;
};