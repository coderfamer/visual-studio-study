#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void independentThread()
{
	cout << "Starting concurrent thread." << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Exiting concurrent thread." << endl;
}

void threadCaller()
{
	cout << "Starting thread caller." << endl;
	thread t(independentThread);
	t.detach();
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Exiting thread caller." << endl;
}

int main()
{
	threadCaller();
	this_thread::sleep_for(chrono::seconds(5));

	return 0;
}