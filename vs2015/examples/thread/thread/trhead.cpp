#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void f1(int n)
{
	for (int i = 0; i < 5; ++i)
	{
		cout << "Thread " << n << " executing " << endl;
		this_thread::sleep_for(chrono::microseconds(10));
	}
}

void f2(int &n)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Thread 2 executing " << endl;
		++n;
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

int main()
{
	int n = 0;
	thread t1;
	thread t2(f1, n+1);
	thread t3(f2, ref(n));
	thread t4
}