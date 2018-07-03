#include <iostream>
#include <thread>

using namespace std;

void hello()
{
	cout << "hello cuncurrent world\n";
}

int main()
{
	thread t(hello);
	t.join();

	return 0;
}