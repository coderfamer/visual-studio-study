#include <iostream>

using namespace std;

double power(double x, int n);

int main()
{
	cout << "power(2.0, -5)" <<  power(2.0, -5) << endl;
	cout << "power(2.0, 5)" << power(2.0, 5) << endl;

	return 0;
}

double power(double	x, int n)
{
	if (n < 0)
	{
		x = 1.0 / x;
		n = -n;
	}
	if (n > 0)
	{
		return x * power(x, n-1);
	}
	else
	{
		return 1.0;
	}
}