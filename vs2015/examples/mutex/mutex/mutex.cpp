#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

map<string, string> g_pages;
mutex g_pages_mutex;

void save_page(const string &url)
{
	this_thread::sleep_for(chrono::seconds(2));
	string result = "fake content";
	cout << "join" << endl;
	lock_guard<mutex> guard(g_pages_mutex);
	g_pages[url] = result;
}

int main()
{
	thread t1(save_page, "http://foo");
	thread t2(save_page, "http://bar");

	t1.join();
	t2.join();

	for (const auto &pair : g_pages)
	{
		cout << pair.first << " => " << pair.second << endl;
	}


	return 0;
}