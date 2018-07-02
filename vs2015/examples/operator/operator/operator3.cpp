#include <iostream>
#include <string>

using namespace std;

class A
{
public:
	int X;
	A() {}
	A &operator = (const int x)
	{
		X = x;
		return *this;
	}
};

class B : public A
{
public:
	B(void) : A() {}
};

int main()
{
	A a;
	B b;
	a = 45;
	b = 67;
	(A)b = 67;

	return 0;
}