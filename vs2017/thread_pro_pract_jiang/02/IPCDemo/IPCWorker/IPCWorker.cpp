#include <Windows.h>
#include <iostream>
#include <tchar.h>

#define COMMUNICATION_OBJECT_NAME TEXT("__FILE_MAPPING__")
#define SYNCHARONIZING_MUTEX_NAME TEXT("__TEST_MUTEX__")

typedef struct _tagCOMMUNICATIONBOJECT
{
	HWND hWndClient;
	BOOL bExitLoop;
	LONG LSleepTimeout;
} COMMUNICATIONOBJECT, *PCOMMUNICATIONBOJECT;

int main(int argc, _TCHAR* argv[])
{
	HBRUSH hBrush = NULL;

	if (_tcscmp(TEXT("blue"), argv[0]) == 0)
	{
		hBrush = CreateSolidBrush(RGB(0, 0, 255));
	}
	else
	{
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
	}

	HWND hWnd = NULL;
	HDC hDc = NULL;
	RECT rectClient = { 0 };
	LONG lWaitTimeout = 0;
	HANDLE hMapping = NULL;
	PCOMMUNICATIONBOJECT pCommObject = NULL;
	BOOL bContinueLoop = TRUE;

	HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, SYNCHARONIZING_MUTEX_NAME);
	hMapping = OpenFileMapping(FILE_MAP_READ, FALSE, COMMUNICATION_OBJECT_NAME);

	if (hMapping)
	{
		while (bContinueLoop)
		{
			WaitForSingleObject(hMutex, INFINITE);
			pCommObject = (PCOMMUNICATIONBOJECT)MapViewOfFile(hMapping,
				FILE_MAP_READ, 0, 0, sizeof(COMMUNICATIONOBJECT));

			if (pCommObject)
			{
				bContinueLoop = !pCommObject->bExitLoop;
				hWnd = pCommObject->hWndClient;
				lWaitTimeout = pCommObject->LSleepTimeout;
				UnmapViewOfFile(pCommObject);
				hDc = GetDC(hWnd);
				if (GetClientRect(hWnd, &rectClient))
				{
					FillRect(hDc, &rectClient, hBrush);
				}

				ReleaseDC(hWnd, hDc);
				Sleep(lWaitTimeout);
			}
			ReleaseMutex(hMutex);
		}
	}

	CloseHandle(hMapping);
	CloseHandle(hMutex);
	DeleteObject(hBrush);

	return 0;
}