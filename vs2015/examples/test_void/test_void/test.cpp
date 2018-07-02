#include <iostream>

using namespace std;

class A
{
public:
	A(int a1) : a(a1) { cout << "A" << endl; }
	~A() {}

	int a;
};

class B
{
public:
	B(int b1) : b(b1) { cout << "B" << endl; }
	~B() {}

	int b;
};

void(*mf)(A *m, B* n);
void(*a)(int *b, int *c);

int main()
{
	A m(5);
	A *m1(&m);
	B n(6);
	B *m2(&n);

	int a1 = 4;
	int a2 = 5;

	//(*a)(&a1, &a2);
	(*mf)(m1, m2);
	//int a = 2;



	return 0;
}