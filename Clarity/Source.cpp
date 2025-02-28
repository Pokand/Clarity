#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include "SurceHeder.h"
#include "resource.h"

Panel* panel = new Panel;

bool Panel1 = true;
bool SettingPanel1 = false;
bool MotivPanel1 = false;
bool ReceiptPanel1 = false;
bool SupportPanel1 = false;


int CALLBACK wWinMain(HINSTANCE hinstance, HINSTANCE, PWSTR pwstr, int cmdShow) {
	
	MSG msg{};
	HWND hwnd{};
	WNDCLASSEX wc{ sizeof(WNDCLASSEX) };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = NULL;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = LoadIcon(hinstance, MAKEINTRESOURCE(IDI_ICON1));
	wc.hInstance = hinstance;
	static HICON icon = LoadIcon(hinstance, MAKEINTRESOURCE(IDI_ICON2));
	wc.lpfnWndProc = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)->LRESULT
		{
			
			
			switch (uMsg)
			{
				case WM_CREATE:
				{
					panel->CreatePanel(hWnd);
					panel->CreateMainPanel(hWnd);

					SendMessage(panel->returnHWND(1), BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)icon); 
				}
				return 0;
				
				case WM_COMMAND:
				{
					switch (LOWORD(wParam))
					{
					case 1001:
					{	
	
					}
					return 0;
					}
				}
				return 0;
				case WM_PAINT:
				{

					PAINTSTRUCT ps;
					HDC hd = BeginPaint(hWnd, &ps);
					RECT rc{ 120,0,500,600 };
					FillRect(hd, &rc, (HBRUSH)(1,1,1));
					
					EndPaint(hWnd, &ps);
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
	


	ShowWindow(hwnd, cmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	
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
