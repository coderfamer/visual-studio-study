#include <iostream>

using std::cout;
using std::endl;
using std::cin;

namespace myStuff
{
	int value = 0;
}

using namespace myStuff;

int main()
{
	cout << "enter an integer: ";
	cin >> value;
	cout << "your entered " << value << endl;

	return 0;
}