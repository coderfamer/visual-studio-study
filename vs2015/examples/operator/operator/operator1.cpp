#include <iostream>
#include <string>

using namespace std;

class MyStr
{
public:
	MyStr();
	MyStr(int _id, char *_name);
	MyStr(const MyStr& str);

	MyStr &operator = (const MyStr& str);

	~MyStr();

private:
	char *name;
	int id;
};

MyStr::MyStr()
{
}

MyStr::MyStr(int _id, char *_name)
{
	cout << "constructor " << endl;
	id = _id;
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}

MyStr::MyStr(const MyStr& str)
{
	cout << "copy constructor " << endl;
	id = str.id;
	if (name != NULL)
	{
		delete name;
	}
	name = new char[strlen(str.name) + 1];
	strcpy_s(name, strlen(str.name) + 1, str.name);
}

MyStr &MyStr::operator=(const MyStr& str)
{
	cout << "operator = " << endl;
	if (this != &str)
	{
		if (name != NULL)
		{
			delete name;
		}
		this->id = str.id;
		int len = strlen(str.name);
		name = new char[len + 1];
		strcpy_s(name, strlen(str.name) + 1, str.name);
	}
	return *this;
}

MyStr::~MyStr()
{
	delete name;
}


int main_mystr()
{
	MyStr str1(1, "hhxx");
	cout << "==========================" << endl;
	MyStr str2;
	str2 = str1;
	cout << "==========================" << endl;
	MyStr str3 = str2;
	cout << "==========================" << endl;
	MyStr str4(str2);
	return 0;
}