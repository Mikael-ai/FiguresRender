#pragma once

#include "windows.h"
#include "Shapes.h"

#include <vector>


class App 
{
private:
	App();
	~App();

	HWND m_hAppWindow; // Appliction window handle
	HINSTANCE m_hInstance; // Appliction instance handle
	int m_nCmdShow; // Appliction window flags

	bool m_isRun; // Window running status

	short m_currentEnumId; // Current shape ID
	Shapes m_currentShape; // Current shape
	std::vector<POINTFLOAT> m_currentShapeVertices; // Array of current shape points

	float m_currentScale; // Current shape scale
	float m_currentRotation; // Current shape rotation

	static App *appInstance; // Singleton instance

public:	
	/**
	 *  Get singlton class instance
	 *  @return - instance of the class
	 */
	static App *getInstance();
	/**
	 *  Setup base window parametes
	 *  @param hInstance - instance handle
	 *  @param nCmdShow - window flags
	 */
	void setup(HINSTANCE hInstance, int nCmdShow);
	/** 
	 *  Init the window
	 */
	bool init();
	/**
	 *  Get window running status
	 */
	bool isRun() const;
	/**
	*  Broadcast window
	*  @return - out message
	*/
	int broadCast();
	/**
	*  Window destroy event
	*/
	void onDestroy();
	/**
	*  Change current shape
	*/
	void nextShape();
	/**
	*  Change current scale
	*  @param scale - new scale
	*/
	void setCurrentScale(const float scale);
	/**
	*  Get current scale
	*/
	float getCurrentScale() const;
	/**
	*  Change current rotation
	*  @param scale - new rotation
	*/
	void setCurrentRotation(const float rotation);
	/**
	*  Get current rotation
	*/
	float getCurrentRotation() const;
	/**
	*  Enable OpenGL for the window
	*  @param hwnd - window handle
	*  @param hDC - device context handle
	*  @param hRC - rendering context handle
	*/
	void EnableOpenGL(HWND hwnd, HDC *hDC, HGLRC *hRC);
	/**
	*  Enable OpenGL for the window
	*  @param hwnd - window handler
	*  @param hDC - device context handle
	*  @param hRC - rendering context handle
	*/
	void DisableOpenGL(HWND hwnd, HDC hDC, HGLRC hRC);
};
