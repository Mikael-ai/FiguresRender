#pragma once
#include "windows.h"

class App {
private:
	App();
	~App();

	HWND m_hAppWindow;
	bool m_isRun;

public:
	static App *appInstance;
	static App *getInstance();

	void setup(HINSTANCE hInstance, int nCmdShow);

	bool init();
	bool isRun();
	int broadCast();
	void onDestroy();


	void EnableOpenGL(HWND hwnd, HDC *, HGLRC *);
	void DisableOpenGL(HWND, HDC, HGLRC);

	HINSTANCE hInstance;
	int nCmdShow;
};