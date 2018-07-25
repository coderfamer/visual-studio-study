#include <mutex>

using namespace std;

class some_big_object
{};

void swap(some_big_object &lhs, some_big_object &rhs)
{}

class X
{
private:
	some_big_object some_detail;
	mutable mutex m;
public:
	X(some_big_object const &sd) : some_detail(sd) {}
	friend void swap(X &lhs, X &rhs)
	{
		//首先判断实例是否相同，避免相同实例上多个锁
		if (&lhs == &rhs)
			return;
		lock(lhs.m, rhs.m);
		lock_guard<mutex> lock_a(lhs.m, adopt_lock);
		lock_guard<mutex> lock_b(rhs.m, adopt_lock);
		swap(lhs.some_detail, rhs.some_detail);
	}
};

int main()
{

}