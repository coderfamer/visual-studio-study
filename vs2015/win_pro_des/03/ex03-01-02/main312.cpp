#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("HelloWin");
	HWND		hwnd;
	MSG			msg;
	WNDCLASS	wndclass;

	//位标记
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	//窗口过程， 该函数处理传递给所有基于该窗口类创建的窗口的所有消息
	wndclass.lpfnWndProc = WndProc;
	//这个两字字段用于在类结构和windows内部维护的窗口结构中预留一些额外的空间
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	//应用程序的实例句柄
	wndclass.hInstance = hInstance;
	//为所有基于该窗口设定一个图标
	//如果是windows预定义图标，第一个参数必须为NULL
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//载入鼠标指针
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	//设置背景颜色
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//指定窗口类的菜单
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	//必须调用 registerclass 来注册窗口类
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT"),
			szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppName,//窗口类名称
		TEXT("The hello Program"),//窗口标题
		WS_OVERLAPPEDWINDOW,//窗口风格
		CW_USEDEFAULT,//初始X坐标
		CW_USEDEFAULT,//初始Y坐标
		CW_USEDEFAULT,//初始X方向尺寸
		CW_USEDEFAULT,//初始Y方向尺寸
		NULL,//父窗口句柄
		NULL,//窗口菜单句柄
		hInstance,//程序实例句柄
		NULL);//创建参数

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
} 

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	switch (message)
	{
	case WM_CREATE:
		//PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);

		DrawText(hdc, TEXT("Hello, Window!!"), -1, &rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}