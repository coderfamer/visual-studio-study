#include <iostream>

using namespace std;

void record();

int main14()
{
	record();
	
	for (int i=0; i <= 3; i++)
	{
		record();
	}
	cout << endl;


	return 0;
}


void record()
{
	static int count = 0;
	cout << "This is the " << ++count;
	if ((count > 3) && (count < 21))
	{
		cout << "th";
	}
	else 
	{
		switch (count % 10)
		{
		case 1:
			cout << "st";
			break;
		case 2:
			cout << "nd";
			break;
		case 3:cout << "rd";
			break;
		default:
			break;
		}
	}
	cout << " time I hava been called" << endl;
	return ;
}