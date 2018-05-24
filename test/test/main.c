#include <windows.h>

int WINAPI WinMain1(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	MessageBox(NULL, TEXT("hello world 98!!"), TEXT("Hello message"), 0 | 2);

	return 0;
}