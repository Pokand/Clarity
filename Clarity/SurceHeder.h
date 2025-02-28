#pragma once
#include <Windows.h>
#include "resource.h"
#include <d2d1.h>
#include <windowsx.h>
#include <algorithm>
#include <string>
#include <CommCtrl.h>




class Panel {
	HWND PANEL;
	HWND PanelMenu;
	HWND SettingPanel;
	HWND MusicPanel;
	HWND ReceiptPanel;
	RECT rc{ 20, 100, 250, 600 };
	
public:
	HWND returnHWND(int num);
	void CreateMainPanel(HWND hwnd);
	void CreatePanel(HWND hwnd);
	void Setting();
	void Musik();
	void Receipt();
};


class Setting_Panel {





};