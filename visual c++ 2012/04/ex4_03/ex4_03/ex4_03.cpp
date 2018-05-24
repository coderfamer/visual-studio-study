#include <iostream>

using namespace std;

int main()
{
	const int MAX(80);
	char buffer[MAX];
	int count(0);

	cout << "Enter a string of less than " << MAX << " characters: " << endl;
	cin.getline(buffer, MAX, '\n');

	while (buffer[count] != '\0')
		count++;

	cout << endl << "the string \" " << buffer << "\" has " << count << " characters.";
	cout << endl;


	return 0;
}