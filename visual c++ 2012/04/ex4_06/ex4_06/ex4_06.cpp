#include <iostream>

using namespace std;

int main()
{
	size_t dice;
	cout << sizeof dice << endl;
	
	double temp[] = {56.5, 465.5, 342.6, 32.5, 32.6, 76.8};
	double sum = 0;
	for (auto t : temp)
	{
		sum += t;
	}
	double average = sum / ((sizeof temp) / (sizeof temp[0]));

	cout << average << endl;
	return 0;
}