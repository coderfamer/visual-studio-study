#include <iostream>
#include <string>

using namespace std;

class Data
{
public:
	Data() {};
	Data(int _data) : data(_data)
	{
		cout << "constructor" << endl;
	}
	//Data& operator=(const int _data)
	//{
	//	cout << "operator = (int _data)" << endl;
	//	data = _data;
	//	return *this;
	//}
private:
	int data;
};

int main_data()
{
	Data data1(1);
	Data data2, data3;
	cout << "===================" << endl;
	data2 = 1;
	cout << "===================" << endl;
	data3 = data2;

	return 0;
}