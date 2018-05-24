#include <iostream>

using namespace std;

template <typename T> 
T max(T x[], int len)
{
	T maximum = x[0];
	for (int i = 1; i < len; i++)
		if (maximum < x[i])
			maximum = x[i];
	return maximum;
}

int main08()
{
	int small[] = {1, 24, 34, 22};
	long medium[] = {23, 245, 123, 1, 234, 1234};
	double large[] = {23.3, 32.4, 4.324, 345.6, 12.5, 32.1};

	int lensmall = sizeof small / sizeof small[0];
	int lenmedium = sizeof medium / sizeof medium[0];
	int lenlarge = sizeof large / sizeof large[0];

	cout << max(small, lensmall) << endl;
	cout << max(medium, lenmedium) << endl;
	cout << max(large, lenlarge) << endl;

	return 0;
}