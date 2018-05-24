#include <iostream>

using namespace std;

int main04()
{
	int counts[] = {34, 54, 0, 27, 0, 10, 0};
	int time = 60;

	for (int i = 0; i < sizeof counts / sizeof counts[0]; i++)
	{
		try
		{
			cout << "Hour " << i + 1;
			if (counts[i] == 0)
			{
				throw "zero count - calculation not possible.";
			}
			cout << " minutes per item: " << static_cast<double>(time) / counts[i] << endl;
		}
		catch (const char aMessage[])
		{
			cout << endl ;
			cout << aMessage << endl;
		}
	}


	return 0;
}