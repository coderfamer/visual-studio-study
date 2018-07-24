#include <list>
#include <iostream>
#include <mutex>
#include <algorithm>

using namespace std;

list<int> some_list;
mutex some_mutex;

void add_to_list(int new_value)
{
	lock_guard<mutex> guard(some_mutex);
	some_list.push_back(new_value);
}

bool list_contains(int value_to_find)
{
	lock_guard<mutex> guard(some_mutex);
	return find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}

int main()
{
	add_to_list(42);
	std::cout << "contains(1)=" << list_contains(1)
		<< ", contains(42)=" << list_contains(42) << std::endl;
}