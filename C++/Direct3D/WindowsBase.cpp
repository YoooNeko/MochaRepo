#include "WindowsBase.h"

WindowsBase::WindowClass WindowsBase::WindowClass::wndClass;
unsigned int	WNDCOUNT = 0;

WindowsBase::WindowClass::WindowClass()
	: hInst(GetModuleHandle(nullptr))
{
	// Register window class
	WNDCLASSEX	wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = HandleMsgSetup;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetInstance();
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = GetName();
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);
}

WindowsBase::WindowClass::~WindowClass()
{
	UnregisterClass(wndClassName, GetInstance());
}

HINSTANCE WindowsBase::WindowClass::GetInstance()
{
	return wndClass.hInst;
}

const char* WindowsBase::WindowClass::GetName()
{
	return wndClassName;
}

WindowsBase::WindowsBase(unsigned int width, unsigned int height, const char* name)
{
	RECT	windowRect;
	windowRect.left = 0;
	windowRect.right = windowRect.left + width;
	windowRect.top = 0;
	windowRect.bottom = windowRect.top + height;

	AdjustWindowRect(&windowRect, WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU, FALSE);

	// Create window
	hWnd = CreateWindow(
		WindowClass::GetName(),
		name,
		WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top,
		nullptr,
		nullptr,
		WindowClass::GetInstance(),
		this
		);

	// Show Window
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	WNDCOUNT++;
}

WindowsBase::~WindowsBase()
{
	DestroyWindow(hWnd);
}

LRESULT	WINAPI WindowsBase::HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_NCCREATE)
	{
		// 当接收到WM_NCCREATE类型消息时，其wParam不被使用，但lParam包含了指向CREATESTRUCT结构的指针（并且其成员和CreateWindowEx的参数相同）
		const CREATESTRUCTW* 	pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);		// 所以先将指针拿出来
		WindowsBase* const pWnd = static_cast<WindowsBase*>(pCreate->lpCreateParams);	// lParam所指向的结构体中包含了窗口的指针也就是pCreate->lpCreateParams
		// 把窗口实例指针存到WINAPI中
		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));

		SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&WindowsBase::HandleMsgThunk));

		return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT	WINAPI WindowsBase::HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	WindowsBase* const pWnd = reinterpret_cast<WindowsBase*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
}

LRESULT WindowsBase::HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
	{
		DestroyWindow(hWnd);
		WNDCOUNT--;
		if (WNDCOUNT == 0)
		{
			PostQuitMessage(0);
		}
		break;
	}
		return 0;
	case WM_LBUTTONDOWN:
	{
		POINTS pt = MAKEPOINTS(lParam);
		std::stringstream oss;
		oss << "(" << pt.x << ", " << pt.y << ")";
		SetWindowText(hWnd, oss.str().c_str());
	}
	break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

HWND WindowsBase::GetWnd()
{
	return hWnd;
}