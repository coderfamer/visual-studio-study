#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

enum  Suit : long {Clubs, Diamonds, Hearts, Speades};

int main()
{
	Suit suit = Clubs;
	Suit another = Suit::Diamonds;

	cout << "suit value:" << suit << endl;
	cout << "Add 10 to another: " << another + 10 <<  endl;

	enum class Color : char {Red, Orange, Yellow, Green, Blue, Indigo, Violet};
	Color skyColor(Color::Blue);

	cout << "Sky color value: " << static_cast<long>(skyColor) << endl;

	cout << "Incremented sky color: " << static_cast<long>(skyColor) + 10L << endl;

	/**
	int num1 = 1234, num2 = 5678;

	cout << setw(6) << num2 << setw(6) << num1 << endl;
	*/
	return 0;
}