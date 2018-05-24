#include <iostream>

using namespace std;


int main()
{
	char stars[6][80] = {
		"Robert redford",
		"hopalong cassidy",
		"lassie",
		"slim picksnes",
		"boris karloff",
		"oliver hardy"
	};
	int dice(0);

	cout << "pick a lucky star!!" << "Enter a number between 1 and 6: ";
	cin >> dice;
	if (dice >= 1 && dice <= 6)
	{
		cout << "Your luky star is " << stars[dice - 1];
	}
	else
	{
		cout << "sorry, you haven't got a lucky star. ";
	}
	cout << endl;


	return 0;
}