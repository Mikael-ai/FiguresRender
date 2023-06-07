#pragma once

#include "windows.h"
#include "Shapes.h"

#include <vector>

class App {
private:
	App();
	~App();

	HWND m_hAppWindow;
	HINSTANCE hInstance;
	int nCmdShow;

	bool m_isRun;

	short currentEnumId;
	Shapes currentShape;
	std::vector<POINTFLOAT> currentShapeVertices;

public:
	static App *appInstance;
	static App *getInstance();

	void setup(HINSTANCE hInstance, int nCmdShow);

	bool init();
	bool isRun();
	int broadCast();
	void onDestroy();

	void nextShape();

	void EnableOpenGL(HWND hwnd, HDC *, HGLRC *);
	void DisableOpenGL(HWND, HDC, HGLRC);
};