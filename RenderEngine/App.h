#pragma once

#include "windows.h"
#include "Shapes.h"

#include <vector>

class App 
{
private:
	App();
	~App();

	HWND m_hAppWindow;
	HINSTANCE m_hInstance;
	int m_nCmdShow;

	bool m_isRun;

	short m_currentEnumId;
	Shapes m_currentShape;
	std::vector<POINTFLOAT> m_currentShapeVertices;

	float m_currentScale;
	float m_currentRotation;

public:
	static App *appInstance;
	static App *getInstance();

	void setup(HINSTANCE hInstance, int nCmdShow);

	bool init();
	bool isRun() const;
	int broadCast();
	void onDestroy();

	void nextShape();
	void setCurrentScale(const float scale);
	float getCurrentScale() const;
	void setCurrentRotation(const float rotation);
	float getCurrentRotation() const;

	void EnableOpenGL(HWND hwnd, HDC *, HGLRC *);
	void DisableOpenGL(HWND, HDC, HGLRC);
};