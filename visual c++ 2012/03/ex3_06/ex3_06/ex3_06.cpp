#include <iostream>

using namespace std;

int main()
{
	char letter(0);
	cout << "Enter a small letter: ";
	cin >> letter;

	switch (letter * (letter >= 'a' && letter <= 'z'))
	{
	case 'a': case 'e': case 'i': case 'o' : case 'u':
		cout << "you enterd a vowel." << endl;
		break;
	case 0:
		cout << "this is not a small letter!!!" << endl;
		break;

	default:
		cout << "a normal consoant " << endl;
		break;
	}

	return 0;
}