#pragma once

#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class WindowsBase
{
private:
	// 自定义的单例窗口类
	class WindowClass
	{
	public:
		static const char* GetName();
		static HINSTANCE GetInstance();

	private:
		WindowClass();
		~WindowClass();
		WindowClass(const WindowClass& obj) = delete;				// 干掉拷贝构造函数
		WindowClass& operator=(const WindowClass& obj) = delete;	// 干掉拷贝赋值运算符

		static constexpr const char* wndClassName = "Yooo's Direct3D12 Window Class";		// 这是我的Windows类注册的名字
		static	WindowClass	wndClass;
		HINSTANCE	hInst;
	};
public:
	WindowsBase(unsigned int width, unsigned int height, const char* name);
	~WindowsBase();
	WindowsBase(const WindowsBase& obj) = delete;				// 干掉拷贝构造函数
	WindowsBase& operator=(const WindowsBase& obj) = delete;	// 干掉拷贝赋值运算符

	HWND GetWnd();

private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	unsigned int	m_iWidth;		// 宽
	unsigned int	m_iHeight;		// 高
	HWND			hWnd;			// 窗口句柄
};