#pragma once
#include <Windows.h>
#include "resource.h"
#include <d2d1.h>
#include <windowsx.h>
#include <algorithm>
#include <string>


//ID2D1Factory* pfactory = nullptr;



class Graphics {
	ID2D1RenderTarget* pRander;
	ID2D1Factory* pfactory;
	ID2D1HwndRenderTarget* rendertarget;
	ID2D1SolidColorBrush* brush;
	ID2D1SolidColorBrush* brushButn;
	
public:
	
	Graphics();
	~Graphics();

	bool Init(HWND windowhandle);
	void BeginDraw() {
		rendertarget->BeginDraw();
	}
	void EndDraw() {
		rendertarget->EndDraw();
	}

	void ClearScreen(float r, float g,float b);
	void DrawCircle(float x, float y, float rad, float r, float g, float b, float a);
	
	void DrawPanel(float x, float y,float x1, float y1,  float r, float g, float b, float a);

	void Panel(float r, float g, float b, float r1, float g1, float b1);

	void Taimer(float x, float y, float r, float g, float b);
	
	void MouseDown(int xPos, int yPos);

};


class MainPanel : Graphics{
	
public:

	bool Panel1 = false;
	bool SettingPanel1 = false;
	bool MotivPanel1 = false;
	bool ReceiptPanel1 = false;
	bool SupportPanel1 = false;
	void SetingsPanel();
	void MotivPanel();
	void ReceiptPanel();
	void SupportPanel();
};

	
