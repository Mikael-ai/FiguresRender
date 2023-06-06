#pragma once
#include "windows.h"

class App {
private:
	App(HINSTANCE hInstance, int nCmdShow);
	~App();

public:
	static App *appInstance;

	int init();
	static App* getInstance(HINSTANCE hInstance, int nCmdShow);

	void EnableOpenGL(HWND hwnd, HDC *, HGLRC *);
	void DisableOpenGL(HWND, HDC, HGLRC);

	HINSTANCE hInstance;
	int nCmdShow;
};