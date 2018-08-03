#include <iostream>
#include <string> 
#include <mutex>
#include <vector>
#include <chrono>

using namespace std;

struct Employee {
	Employee(string id) : id(id) {}
	string id;
	vector<string> lunch_partners;
	mutex m;
	string output() const
	{
		string ret = "Employee " + id + " has lunch partners: ";
		for (const auto &partner : lunch_partners)
			ret += partner + " ";
		return ret;
	}
};

void send_mail(Employee &, Employee &)
{
	this_thread::sleep_for(chrono::seconds(1));
}

void assign_lunch_partner(Employee &e1, Employee &e2)
{
	static mutex io_mutex;
	{
		lock_guard<mutex> lk(io_mutex);
		cout << e1.id << " and " << e2.id << " are waiting for locks!!" << endl;
	}
	{
		lock(e1.m, e2.m);
		lock_guard<mutex> lk1(e1.m, adopt_lock);
		lock_guard<mutex> lk2(e2.m, adopt_lock);

		{
			lock_guard<mutex> lk(io_mutex);
			cout << e1.id << " and " << e2.id << " got locks" << endl;
		}
		e1.lunch_partners.push_back(e2.id);
		e2.lunch_partners.push_back(e1.id);
	}
	send_mail(e1, e2);
	send_mail(e2, e1);
}

int main()
{
	Employee alice("alice"), bob("bob"), christina("christina"), dave("dave");

	vector<thread> threads;
	threads.emplace_back(assign_lunch_partner, std::ref(alice), std::ref(bob));
	threads.emplace_back(assign_lunch_partner, std::ref(christina), std::ref(bob));
	threads.emplace_back(assign_lunch_partner, std::ref(christina), std::ref(alice));
	threads.emplace_back(assign_lunch_partner, std::ref(dave), std::ref(bob));

	for (auto &thread : threads) thread.join();
	std::cout << alice.output() << '\n' << bob.output() << '\n'
		<< christina.output() << '\n' << dave.output() << '\n';
	
	return 0;
}