#define  _CRT_SECURE_NO_WARNINGS
/*'_vsnwprintf': This function or variable may be unsafe.
Consider using _vsnwprintf_s instead.To disable deprecation, 
use _CRT_SECURE_NO_WARNINGS.See online help for details.

-----You have to define _CRT_SECURE_NO_WARNINGS before #include <Windows.h>.---

*/
#include <Windows.h>
#include <tchar.h>
#include <stdio.h>

#define  _CRT_SECURE_NO_WARNINGS

int CDECL MessageBoxPrintf(TCHAR *szCaption, TCHAR *szFormat, ...)
{
	TCHAR szBuffer[1024];
	va_list pArgList;
	va_start(pArgList, szFormat);

	_vsntprintf(szBuffer, sizeof(szBuffer) / sizeof(TCHAR), szFormat, pArgList);

	va_end(pArgList);

	return MessageBox(NULL, szBuffer, szCaption, 0);
}

int test_va( int count, ...)
{
	int sum = 0;
	int a;
	va_list pArgList;
	va_start(pArgList, count);
	
	for (int i = 0; i < count; i++)
	{
		sum += va_arg(pArgList, int);
	}

	va_end(pArgList);
	return sum;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	int cxScreen, cyScreen;
	int test = test_va(3, 3, 4, 5);
	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);

	MessageBoxPrintf(TEXT("scrnSize"),
		TEXT("The screen is %i pixels wide by %i pixels high.%d"),
		cxScreen, cyScreen, test);

	return 0;
}

