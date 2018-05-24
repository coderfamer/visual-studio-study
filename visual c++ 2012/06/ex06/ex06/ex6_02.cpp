#include <iostream>

using namespace std;

double squared(double);
double cubed(double);
double sumarray(double array[], int len, double (*pfun)(double));

int main02()
{
	double array[] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5};
	int len(sizeof array / sizeof array[0]);

	cout << "sum of squares = " << sumarray(array, len, squared) << endl;
	cout << "sum of cubes = " << sumarray(array, len, cubed) << endl; 

	return 0;
}

double squared(double n)
{
	return n * n;
}

double cubed(double n)
{
	return n * n * n;
}

double sumarray(double array[], int len, double (*pfun)(double))
{
	double total = 0.0;
	for (int i = 0; i < len; i++)
	{
		cout << pfun(array[i]) << endl;
		total += pfun(array[i]);
	}

	return total;
}