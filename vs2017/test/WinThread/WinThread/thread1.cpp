#include <iostream>
#include <string>
#include <Windows.h>
#include <process.h>

using namespace std;

class ThreadX
{
public:
	string thread_name;

	ThreadX(int start_value, int end_value, int frequency)
	{
		loop_start = start_value;
		loop_end = end_value;
		disp_frequency = frequency;
	}

	static unsigned __stdcall ThreadStaticEntryPoint(void* pThis)
	{
		ThreadX* pthx = (ThreadX*)pThis;
		pthx->threadEntryPoint();
		return 1;
	}

	void threadEntryPoint()
	{
		for (int i = loop_start; i <= loop_end; ++i)
		{
			if (i % disp_frequency == 0)
			{
				cout << thread_name.c_str() << ": i = " << i << endl;
			}
		}
		cout << thread_name.c_str() << " thread terminating" << endl;
	}

private:
	int loop_start;
	int loop_end;
	int disp_frequency;
};

int main()
{
	ThreadX* thd1 = new ThreadX(0, 3, 2000);

	HANDLE hth1;
	unsigned uiThread1Id;

	hth1 = (HANDLE)_beginthreadex(NULL, 0, ThreadX::ThreadStaticEntryPoint,
		thd1, CREATE_SUSPENDED, &uiThread1Id);

	if (hth1 == 0)
		cout << "Failed to create thread 1 " << endl;

	DWORD dwExitCode;
	GetExitCodeThread(hth1, &dwExitCode);
	cout << "initial thread1 exit code = " << dwExitCode << endl;

	thd1->thread_name = "t1";

	ThreadX* thd2 = new ThreadX(-100000, 0, 2000);

	HANDLE hth2;
	unsigned uiThread2Id;

	hth2 = (HANDLE)_beginthreadex(NULL, 0, ThreadX::ThreadStaticEntryPoint,
		thd2, CREATE_SUSPENDED, &uiThread2Id);

	if (hth2 == 0)
		cout << "Failed to create thread 2" << endl;

	GetExitCodeProcess(hth2, &dwExitCode);
	cout << "initial thread2 exit code = " << dwExitCode << endl;
	thd2->thread_name = "t2";

	ResumeThread(hth1);
	ResumeThread(hth2);

	WaitForSingleObject(hth1, INFINITE);
	WaitForSingleObject(hth2, INFINITE);

	GetExitCodeThread(hth1, &dwExitCode);
	cout << "thread 1 exit with code " << dwExitCode << endl;

	GetExitCodeThread(hth2, &dwExitCode);
	cout << "thread 2 exited with code " << dwExitCode << endl;

	CloseHandle(hth1);
	CloseHandle(hth2);

	delete thd1;
	thd1 = NULL;

	delete thd2;
	thd2 = NULL;

	cout << "Primary thread terminating." << endl;

	return 0;
}