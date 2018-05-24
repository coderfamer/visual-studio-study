#include <iostream>

using namespace std;

auto test(double x, int n) -> double;

int main()
{
	double x = 2.2;
	int n = 3;
	cout << test(x, n) << endl;


	return 0;
}

auto test(double x, int n) -> double
{
	double result = 1.34;
	for (int i = 1; i <= n; i++)
	{
		result *= x;
	}

	return result;
}