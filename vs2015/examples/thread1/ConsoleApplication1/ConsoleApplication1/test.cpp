#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>

using namespace std;

void thread_task()
{
	cout << "Hello thread" << endl;
}

int main_test()
{
	thread t(thread_task);
	t.join();

	return EXIT_SUCCESS;
}