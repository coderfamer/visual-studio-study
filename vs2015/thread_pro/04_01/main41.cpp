#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>

using namespace std;

bool more_data_to_prepare()
{
	return false;
}

struct data_chunk
{};

data_chunk prepare_data()
{
	return data_chunk();
}

void process(data_chunk &)
{}

bool is_last_chunk(data_chunk &)
{
	return true;
}

mutex mut;
queue<data_chunk> data_queue;
condition_variable data_cond;

void data_preparation_thread()
{
	while (more_data_to_prepare())
	{
		data_chunk const data = prepare_data();
		lock_guard<mutex> lk(mut);
		data_queue.push(data);
		data_cond.notify_one();
	}
}

void data_processing_thread()
{
	while (true)
	{
		unique_lock<mutex> lk(mut);
		data_cond.wait(lk, [] { return !data_queue.empty(); });
		data_chunk data = data_queue.front();
		data_queue.pop();
		lk.unlock();
		process(data);
		if (is_last_chunk(data))
			break;
	}
}

int main()
{
	thread t1(data_preparation_thread);
	thread t2(data_processing_thread);

	t1.join();
	t2.join();

	return 0;
}