#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int CDECL MessageBoxPrintf(TCHAR *szCaption, TCHAR *szFormat, ...)
{
	TCHAR szBuffer[1024];
	va_list pArglist;

	va_start (pArglist, szFormat);
	_vsnprintf(szBuffer, sizeof(szBuffer)/sizeof(TCHAR), szFormat, pArglist);
	va_end(pArglist);

	return MessageBox(NULL, szBuffer, szCaption, 0);
}

int WINAPI WinMain2( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd )
{
	int cxScreen,cyScreen;

	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);

	MessageBoxPrintf(TEXT("Screen size"), 
		TEXT("the screen is %i pixels wide by %i pixels high."),
		cxScreen, cyScreen);


	return 0;
}