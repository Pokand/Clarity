#include "SurceHeder.h"
HWND Panel::returnHWND(int num) {
	switch (num)
	{
	case 1:
		return PANEL;
	case 2:
		return SettingPanel;
	case 3:
		return MusicPanel;
	case 4:
		return ReceiptPanel;
	
	default: return 0;
	}
}


void Panel::CreatePanel(HWND hwnd){
	PANEL = CreateWindowEx(0, L"button", L"", BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD | BS_ICON, 20, 20, 70, 50, hwnd , reinterpret_cast<HMENU>(1001), nullptr, nullptr);
	
}

void Panel::CreateMainPanel(HWND hwnd) {
//	PanelMenu = CreateWindowEx(0, L"static", L"", WS_VISIBLE | WS_CHILD | SS_BLACKFRAME, 10, 85, 170, 350, hwnd, nullptr, nullptr, nullptr);
	SettingPanel = CreateWindowEx(0, L"button", L"Настройки", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 5, 85, 100, 65, hwnd, (HMENU)1002, nullptr, nullptr);
	MusicPanel = CreateWindowEx(0, L"button", L"Музыка", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 5, 165, 100, 65, hwnd, (HMENU)1003, nullptr, nullptr);
	ReceiptPanel = CreateWindowEx(0, L"button", L"Расписание", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 5, 245, 100, 65, hwnd, (HMENU)1004, nullptr, nullptr);
}



