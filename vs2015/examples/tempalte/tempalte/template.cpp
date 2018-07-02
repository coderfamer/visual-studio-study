#include <iostream>
#include <string>
#include <typeinfo>
#include <strstream>
using namespace std;

//类模板定义中class和typename么有区别
//模板的声明和定义只能在全局、命名空间或者类范围内进行
template<typename T1, typename T2>
class A
{
public:
	void f(T1 a, T2 b);
};

template<typename T1, typename T2>
void A<T1, T2>::f(T1 a, T2 b)
{
	cout << "class A --------->T1: " << a << ";T2: " << b << endl;
}

//定义类模板的默认类型实参，默认类型形参不适用于函数模板
template<typename T3, typename T4 = int> // T4 默认模板类型形参
class B
{
private:
	T3 t3;
	T4 t4;
public:
	B(T3 a, T4 b);
	void show();
};

//在类模板外部定义带有默认类型的形参时，在template的形参表中默认自应该省略
template<typename T3, typename T4>
B<T3, T4>::B(T3 a, T4 b) : t3(a), t4(b)
{}

template<typename T3, typename T4>
void B<T3, T4>::show()
{
	cout << "class B --------->T3: " << t3 << "; T4: " << t4 <<  endl;
}

//======================================================================================================
//非类型模板参数
//非类型形参只能是整型、指针和引用
template<typename T5, int a>
class C
{
private:
	T5 max[a];
public:
	void cshow()
	{
		cout << "class c --------->T5: " << typeid(T5).name() << endl;
	}
};


template<typename t_print>
class  Printer {
public:
	explicit Printer(const t_print& param) : t(param) {}
	string && to_string();
	void print()
	{
		cout << t << endl;
	}
private:
	t_print t;
};

template<typename t_print>
string && Printer<t_print>::to_string()
{
	strstream ss;
	ss << t;
	return move(string(ss.str()));
}

//========================================================================================
//类模板中的成员函数模板
template<typename t_print2>
class Printer2
{
public:
	explicit Printer2(const t_print2& param) : t(param) {}
	template<typename U>
	void add_and_print(const U& u);
private:
	t_print2 t;
};

//要有两层template说明
template<typename t_print2>
template<typename U>
void Printer2<t_print2>::add_and_print(const U& u)
{
	cout << t + u << endl;
}

//=============================================================================================
//类模板中可以声明static成员，在类外定义的时候要增加template相关的关键词
//每个不同的模板实例都会有一个独有的static成员对象
template<typename t_print3>
class Printer3
{
public:
	explicit Printer3(const t_print3& param) : t(param) {}
	static int s_value;
	void print3();
private:
	t_print3 t;
};

template<typename t_print3>
int Printer3<t_print3>::s_value = 1;

template<typename t_print3>
void Printer3<t_print3>::print3()
{
	cout << s_value << endl;
}

int main()
{
	A<int, int> a1;
	a1.f(2, 3);
	A<int, char> a2;
	a2.f(2, 'a');
	A<string, int> a3;
	a3.f("hello world!", 5);

	B<char, char> b1('a', 'b');
	b1.show();
	B<char> b2('c', 6);
	b2.show();
	B<string, string> b3("陈", "西");

	const int i = 5;
	C<int, i> c1;
	c1.cshow();
	C<char, i> c2;
	c2.cshow();

	Printer<int> p(20);
	p.print();

	//=============================
	//Printer2
	Printer2<int> p2(30);
	p2.add_and_print(1.1);
	
	//================================
	//static成员属于实例化后的类,不同的实例有不同的static成员，只有相同类型的实例的static成员才会受影响
	//所以 int型的实例值会改变，而double实例的值不会改变
	Printer3<int> p3_1(10);
	Printer3<int> p3_2(100);
	Printer3<double> p3_3(1.0);
	p3_1.s_value += 3;
	p3_1.print3();
	p3_2.print3();
	p3_3.print3();
	return 0;
}