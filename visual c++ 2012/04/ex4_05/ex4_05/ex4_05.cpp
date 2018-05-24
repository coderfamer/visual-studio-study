#include <iostream>

using namespace std;


int main()
{
	long *pnumber = nullptr;
	long number1(55), number2(99);

	pnumber = &number1;
	*pnumber += 11;
	cout << "number1 = " << number1 << endl <<
		"&number = " << hex << pnumber << endl;

	pnumber = &number2;
	number1 = *pnumber * 10;

	cout << "number1 = " << dec << number1
		<< " pnumber = " << hex << pnumber
		<< " *pnumber = " << dec << *pnumber << endl;

	return 0;
}