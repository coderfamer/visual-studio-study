#include <iostream>

using namespace std;

long sum(long a, long b);
long product(long a, long b);

int main01()
{
	long (*pdo_it)(long, long);

	pdo_it = product;
	cout << "3 * 5 = " << pdo_it(3, 5) << endl;;

	pdo_it = sum;
	cout << "3 * (4 + 5) + 6 = " << pdo_it(product(3, pdo_it(4, 5)), 6) << endl;


	return 0;
}

long product(long a, long b)
{
	return a * b;
}

long sum(long a, long b)
{
	return a + b;
}