#include <iostream>
#include <thread>
#include <functional>

using namespace std;

void f1(int n)
{
	for (int i = 0; i < 5; ++i)
	{
		cout << i << ": thread " << n << " executing" << endl;;
		this_thread::sleep_for(chrono::microseconds(10000));
	}
}

void f2(int &n)
{
	for (int i = 0; i < 5; ++i)
	{
		cout << "f2: " << i << ": thread 2 executing" << endl;
		++n;
		this_thread::sleep_for(chrono::microseconds(10000));
	}
}

int main_thread1()
{
	int n = 0;
	thread t1;
	thread t2(f1, n + 1);
	thread t3(f2, ref(n));
	thread t4(move(t3));
	t2.join();
	t4.join();

	cout << "Final value of n is " << n << endl;

	return  0;
}