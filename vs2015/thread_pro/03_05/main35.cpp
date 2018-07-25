#include <exception>
#include <stack>
#include <mutex>
#include <memory>

using namespace std;

struct empty_stack : exception
{
	const char *what() const throw()
	{
		return "empty stack";
	}
};

template<typename T>
class threadsafe_stack
{
private:
	stack<T> data;
	//mutable ¿É±äµÄ
	mutable mutex m;

public:
	threadsafe_stack() { }
	threadsafe_stack(const threadsafe_stack &ohter)
	{
		lock_guard<mutex> lock(other.m);
		data = other.data;
	}
	threadsafe_stack &operator=(const threadsafe_stack &) = delete;

	void push(T new_value)
	{
		lock_guard<mutex> lock(m);
		data.push(new_value);
	}
	
	shared_ptr<T> pop()
	{
		lock_guard<mutex> lock(m);
		if (data.empty()) throw empty_stack();
		shared_ptr<T> const res(make_shared<T>(data.top()));
		data.pop();
		return res;
	}

	void pop(T& value)
	{
		lock_guard<mutex> lock(m);
		if (data.empty()) throw empty_stack();
		value = data.top();
		data.pop();
	}

	bool empty() const
	{
		lock_guard<mutex> lock(m);
		return data.empty();
	}
};

int main()
{
	threadsafe_stack<int> si;
	si.push(5);
	si.pop();
	if (!si.empty())
	{
		int x;
		si.pop(x);
	}
}