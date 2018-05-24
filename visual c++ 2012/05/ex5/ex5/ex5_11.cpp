#include <iostream>
#include <cstdarg>

using namespace std;

int sum(int count, ...)
{
	if(count <= 0)
		return 0;

	va_list arg_ptr;
	va_start(arg_ptr, count);

	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += va_arg(arg_ptr, int);
	}
	va_end(arg_ptr);
	return sum;

}

int main11(int argc, char *argv[])
{
	int sum1;
	int sum2;
	sum1 = sum(6, 2, 3, 4, 5, 6);
	sum2 = sum(9, 11, 22, 33, 44, 55, 66, 77, 88, 99);
	cout << "sum1 = " << sum1 << endl
		<< "sum2 = " << sum2 << endl;


	return 0;
}