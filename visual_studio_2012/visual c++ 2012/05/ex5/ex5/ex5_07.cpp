#include <iostream>

using namespace std;

int alter_num(int &);

int main07()
{
	int num = 3;
	int value = 6;

	int result = alter_num(num);
	cout << "alter num = " << result
		<<endl << "num = " << num << endl;
	
	result = alter_num(value);
	cout << "alter num(value) = " << result 
		<< endl << "value = " << value << endl;;

	return 0;
}

int alter_num(int &num)
{
	cout << "value received = " << num << endl;
	num += 10;
	return num;
}