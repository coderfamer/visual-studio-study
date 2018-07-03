#include <Windows.h>
#include <winternl.h>
#include <iostream>

using namespace std;

typedef NTSTATUS(NTAPI * QEURYINFROMATIONPROCESS)(
	IN HANDLE ProcessHandle,
	IN PROCESSINFOCLASS ProcessInformationClass,
	OUT PVOID ProcessInfomation,
	IN ULONG ProcessInfomationLength,
	OUT PULONG ReturnLength OPTIONAL
	);

int main()
{
	STARTUPINFO startupInfo = { 0 };
	PROCESS_INFORMATION processInformation = { 0 };

	BOOL bSucess = CreateProcess(
		TEXT("C:\\Windows\\notepad.exe"), NULL, NULL,
		NULL, FALSE, NULL, NULL, NULL, &startupInfo,
		&processInformation
	);

	if (bSucess)
	{
		cout << "Process started. " << endl << "Process Id: "
			<< processInformation.dwProcessId << endl;

		PROCESS_BASIC_INFORMATION pbi;
		ULONG uLength = 0;

		HMODULE hDll = LoadLibrary(
			TEXT("C:\\Windows\\System32\\ntdll.dll"));

		if (hDll)
		{
			QEURYINFROMATIONPROCESS QueryInformationProcess =
				(QEURYINFROMATIONPROCESS)GetProcAddress(
					hDll, "NtQueryInformationProcess"
				);

			if (QueryInformationProcess)
			{
				NTSTATUS ntStatus = QueryInformationProcess(
					processInformation.hProcess,
					PROCESSINFOCLASS::ProcessBasicInformation,
					&pbi, sizeof(pbi), &uLength
				);

				if (NT_SUCCESS(ntStatus))
				{
					cout << "Process ID(from PCB):\t"
						<< pbi.UniqueProcessId << endl;
				}
				else
				{
					cout << "Cannot open PCB!" << endl
						<< "Error doce: \t" << GetLastError()
						<< endl;
				}
			}
			else
			{
				cout << "Cannot get "
					<< "NtQueryInformationProcess function!" << endl
					<< "Error code:\t"
					<< GetLastError() << endl;
			}
			FreeLibrary(hDll);
		}
		else
		{
			cout << "Cannot load ntdll.dll!" << endl
				<< "Error code:\t" << GetLastError() << endl;
		}
	}
	else
	{
		cout << "Cannot start process!" << endl
			<< "Error code:\t" << GetLastError() << endl;
	}


	return 0;
}