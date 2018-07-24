#include <thread>

using namespace std;

void some_function()
{}

void some_other_function(int)
{}

thread f()
{
	void some_function();
	return thread(some_function);
}

thread g()
{
	void some_other_function(int);
	thread t(some_other_function, 42);
	return t;
}

int main()
{
	thread t1 = f();
	t1.join();

	thread t2 = g();
	t2.join();

	return 0;
}

