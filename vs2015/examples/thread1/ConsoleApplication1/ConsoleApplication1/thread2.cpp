#include <iostream>
#include <thread>

using namespace std;

void foo()
{
	this_thread::sleep_for(chrono::seconds(1));
}

int main_thread2()
{
	thread t1(foo);
	thread::id t1_id = t1.get_id();


	thread t2(foo);
	thread::id t2_id = t2.get_id();

	cout << "before starting, joinable: " << t1.joinable() << endl;
	cout << "t1's id: " << t1_id << endl;
	cout << "fater starting, joinbable: " << t1.joinable() << endl;
	cout << "t2's id: " << t2_id << endl;

	t1.join();
	t2.join();


	return 0;
}