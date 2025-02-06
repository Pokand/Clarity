#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include "SurceHeder.h"
#include "resource.h"

bool Panel1 = false;
bool SettingPanel1 = false;
bool MotivPanel1 = false;
bool ReceiptPanel1 = false;
bool SupportPanel1 = false;
Graphics* graphics;
MainPanel* panelwindow;

int CALLBACK wWinMain(HINSTANCE hinstance, HINSTANCE, PWSTR pwstr, int cmdShow) {
	
	MSG msg{};
	static HWND hwnd{}, lButton{};
	WNDCLASSEX wc{ sizeof(WNDCLASSEX) };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = NULL;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = LoadIcon(hinstance, MAKEINTRESOURCE(IDI_ICON1));
	
	wc.hInstance = hinstance;
	
	wc.lpfnWndProc = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)->LRESULT
		{
			
			switch (uMsg)
			{
	

				case WM_PAINT:
				{
					graphics->BeginDraw();

					

					graphics->ClearScreen(0.4f, 0.6f, 1.0f);

					graphics->Taimer(300, 100, 0.2f, 0.3f, 0.5f);
					
					graphics->DrawPanel(10, 20, 50, 20, 0,0,0, 1);

					if (Panel1) {
						graphics->Panel(0.6f, 0.7f, 0.7f, 0.94f, 0.36f, 0.5f);

					}

					

					graphics->EndDraw();
				}
				return 0;
				

				case WM_LBUTTONDOWN:
				{
					
					int xPos = GET_X_LPARAM(lParam);
					int yPos = GET_Y_LPARAM(lParam);
					if (xPos >= 10 && xPos <= 50 && yPos >= 20 && yPos <= 40) {
						Panel1 = true;
					}
					
				}
				return 0;

				case WM_DESTROY:
				{
					PostQuitMessage(EXIT_SUCCESS);
				}
				return 0;
			}

			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		};
	


	wc.lpszClassName = L"MyAPP";
	wc.lpszMenuName = nullptr;
	wc.style = CS_VREDRAW | CS_HREDRAW  ;

	if (!RegisterClassEx(&wc)) {
		return EXIT_FAILURE;
	}

	RECT rc = { 0, 0, 500, 600 };
	AdjustWindowRectEx(&rc, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	if (hwnd = CreateWindow(wc.lpszClassName, L"Clarity", WS_OVERLAPPEDWINDOW &~WS_THICKFRAME & ~WS_MAXIMIZEBOX & ~(WS_MAXIMIZEBOX | WS_MINIMIZEBOX), 0, 0, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, wc.hInstance, nullptr); hwnd == INVALID_HANDLE_VALUE)
		return EXIT_FAILURE;
	graphics = new Graphics();

	if(!graphics->Init(hwnd))
	{
		delete graphics;
		return -1;
	}
	

	ShowWindow(hwnd, cmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	delete graphics;
	return static_cast<int>(msg.wParam);
}

/*std::pair<bool, HWND> AddWindow(const std::wstring&& winClass, const std::wstring&& title, HWND hParentwindow, const WNDPROC wndproc) {
	UnregisterClass(winClass.c_str(), DrvGetModuleHandle(nullptr));
	WNDCLASSEX wc(sizeof(WNDCLASSEX));
	HWND hwnd;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = LoadIcon(nullptr, MAKEINTRESOURCE(IDI_ICON1));
	wc.lpszClassName = winClass.c_str();
	wc.lpfnWndProc = wndproc;
	wc.style = CS_VREDRAW | CS_HREDRAW;

	const auto create_window = [&hwnd, &winClass, &title, &hParentwindow]() -> std::pair<bool, HWND>
		{
			if (hwnd = CreateWindow(winClass.c_str(), title.c_str(), WS_OVERLAPPEDWINDOW, 100, 100, 300, 300, hParentwindow, nullptr, nullptr, nullptr); !hwnd) {
				return { false,nullptr };
			}

			ShowWindow(hwnd, SW_SHOWDEFAULT);
			return { true, hwnd };
		};

	if (!RegisterClassEx(&wc)) return create_window();

	return create_window();
}*/

/*
//HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pfactory);
//ID2D1HwndRenderTarget* ptargetrender;
//ID2D1SolidColorBrush* pbrushcolor;
//CreateWindowA("static", "Hellow window!", WS_VISIBLE | WS_CHILD, 5, 5, 50, 20, hWnd, nullptr, nullptr, nullptr);
//RECT rc {};
//GetClientRect(hWnd, &rc);
//	if (FAILED(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pfactory)) return -1;
//CreateWindow(L"IMAGE", L"image1", WS_)
//lButton = CreateWindow (L"BUTTON", L"Таймер", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 100, 100, 100, 100, hWnd, reinterpret_cast<HMENU>(1337), nullptr, nullptr);
//MessageBox(hWnd, L"PRIVET", L"OK", MB_ICONERROR);
//RECT rc{};
/GetClientRect(hWnd, &rc);
//SetWindowPos(lButton, nullptr, 0, 0, LOWORD(lParam), HIWORD(lParam), SWP_NOMOVE | SWP_NOZORDER | SWP_NOOWNERZORDER);
*/
