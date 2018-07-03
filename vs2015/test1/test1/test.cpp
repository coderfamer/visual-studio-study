#include <iostream>

#define FATE_FLAG(flag)   10* #flag

using namespace std;

int main()
{

	int n = 2;
	int flag = 2;
	cout <<  FATE_FLAG(2) << endl;

	return 0;
}