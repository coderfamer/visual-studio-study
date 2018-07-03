#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
	STARTUPINFO startupInfo = { 0 };
	PROCESS_INFORMATION processInformation = { 0 };

	//createprocess 创建一个线程及其主线程
	BOOL bSucess = CreateProcess(
		TEXT("C:\\Windows\\notepad.exe"), NULL, NULL,
		NULL, FALSE, NULL, NULL, NULL, &startupInfo,
		&processInformation
	);

	if (bSucess)
	{
		cout << "Process started. " << endl
			<< "Process ID:\t"
			<< processInformation.dwProcessId << endl;
	}
	else
	{
		cout << "Cannot start process!" << endl
			<< "Error code: \t" << GetLastError() << endl;
	}


	return 0;
}