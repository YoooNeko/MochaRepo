#pragma once

#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class WindowsBase
{
private:
	// �Զ���ĵ���������
	class WindowClass
	{
	public:
		static const char* GetName();
		static HINSTANCE GetInstance();

	private:
		WindowClass();
		~WindowClass();
		WindowClass(const WindowClass& obj) = delete;				// �ɵ��������캯��
		WindowClass& operator=(const WindowClass& obj) = delete;	// �ɵ�������ֵ�����

		static constexpr const char* wndClassName = "Yooo's Direct3D12 Window Class";		// �����ҵ�Windows��ע�������
		static	WindowClass	wndClass;
		HINSTANCE	hInst;
	};
public:
	WindowsBase(unsigned int width, unsigned int height, const char* name);
	~WindowsBase();
	WindowsBase(const WindowsBase& obj) = delete;				// �ɵ��������캯��
	WindowsBase& operator=(const WindowsBase& obj) = delete;	// �ɵ�������ֵ�����

	HWND GetWnd();

private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	unsigned int	m_iWidth;		// ��
	unsigned int	m_iHeight;		// ��
	HWND			hWnd;			// ���ھ��
};