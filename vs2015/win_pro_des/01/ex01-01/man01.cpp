#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

//sz表示以零结尾的字符串
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{

	MessageBox(NULL, TEXT("Hello win32"), TEXT("Hellomsg"), MB_CANCELTRYCONTINUE );
	//cout << "hello " << endl;
	return 0;
}

/*
int WINAPI WinMain(
	//实例句柄
	_In_ HINSTANCE hInstance,
	//通常为NULL
	_In_ HINSTANCE hPrevInstance,
	//运行程序的命令行
	_In_ LPSTR     lpCmdLine,
	//知名程序最初如何显示
	_In_ int       nCmdShow
);
*/