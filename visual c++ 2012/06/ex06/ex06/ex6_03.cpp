#include <iostream>

using namespace std;


void show_msg(const char message[] = "something is wrong.");

int main03()
{
	const char mymsg[] = "the end of the world is nigh";

	show_msg();
	show_msg("something is terribly wrong!!");
	show_msg();
	show_msg(mymsg);

	return 0;
}

void show_msg(const char message[])
{
	cout << message << endl;
	return;
}