#include <iostream>

using namespace std;

int alter_num(int num);
int alter_num1(int* num);

int main02()
{
	int num = 5;
	int i_num = alter_num(num);

	cout << "value transmit " << num << endl
		<< i_num;
	cout << "----------------" << endl;

	int num1 = 3;
	int i_num1 = alter_num1(&num1);
	cout << "point tarnsmit " << num1 << endl
		<< i_num1 << endl;

	return 0;
}

int alter_num(int num)
{
	num += 10;
	return num;
}

int alter_num1(int* num)
{
	*num += 10;
	return *num;
}