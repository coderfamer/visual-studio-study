#include <windows.h>

LRESULT CALLBACK Wndproc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain3(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
				   PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppname[] = TEXT("hellowin");
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;

	wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc	= Wndproc;
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.hInstance		= hInstance;
	wndclass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);//加载图标，供程序使用
	wndclass.hCursor		= LoadCursor(NULL, IDC_ARROW);//加载鼠标光标，供程序使用
	wndclass.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);//获取一个图形对象
	wndclass.lpszMenuName	= NULL;
	wndclass.lpszClassName	= szAppname;

	if (!RegisterClass(&wndclass))//为应用程序窗口注册一个窗口类
	{
		MessageBox(NULL, TEXT("this program require windows nt!"),//显示消息框
			szAppname, MB_ICONERROR);
		return 0;
	}
	/*
	CreateWindowA(lpClassName, lpWindowName, dwStyle, x, y,\
	nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)\
	CreateWindowExA(0L, lpClassName, lpWindowName, dwStyle, x, y,\
	nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
	#define CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y,\
	nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)\
	CreateWindowExW(0L, lpClassName, lpWindowName, dwStyle, x, y,\
	nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
	*/
	hwnd = CreateWindow(szAppname,//基于窗口类创建一个窗口
		TEXT("the hello program"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	ShowWindow(hwnd, iCmdShow);//在屏幕中显示窗口
	UpdateWindow(hwnd);//指示窗口对自身进行重绘

	while (GetMessage(&msg, NULL, 0, 0))//从消息队列获取消息
	{
		TranslateMessage(&msg);//翻译一些键盘消息
		DispatchMessage(&msg);//讲消息发给窗口过程
	}


	return msg.wParam;
}

LRESULT CALLBACK Wndproc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	switch (message)
	{
	case WM_CREATE:
		//PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);//播放声音文件
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);//获取窗口客户区的尺寸
		DrawText(hdc, TEXT("hello, window 98"), -1, &rect, 
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);//显示一个文本字符串
		EndPaint(hwnd, &ps);//结束窗口绘制
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);//将推出消息插入消息队列
		return 0;
	}
	return DefWindowProc(hwnd, message, wparam, lparam);//执行默认的消息处理
}