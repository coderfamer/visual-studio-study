#include <mutex>

using namespace std;

class some_data
{
	int a;
	string b;
public:
	void do_something()
	{ }
};

class data_warpper
{
private:
	some_data data;
	mutex m;
public:
	template<typename Function>
	void process_data(Function func)
	{
		lock_guard<mutex> l(m);
		func(data);
	}
};

some_data *unprotected;

void malicious_function(some_data &protected_data)
{
	unprotected = &protected_data;
}

data_warpper x;
void foo()
{
	x.process_data(malicious_function);
	unprotected->do_something();
}

int main()
{
	foo();
	return 0;
}