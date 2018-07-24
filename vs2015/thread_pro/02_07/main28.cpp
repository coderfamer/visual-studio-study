#include <iostream>
#include <thread>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

template<typename Iterator, typename T>
struct accumulate_block
{
	void operator()(Iterator first, Iterator last, T &result)
	{
		result = accumulate(first, last, result);
	}
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
	unsigned long const length = distance(first, last);

	if (!length)
	{
		return init;
	}

	unsigned long const min_per_thread = 25;
	unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread;
	cout << "max_threads = " << max_threads << endl;
	unsigned long const hardware_threads = thread::hardware_concurrency();
	cout << "hardware_threads = " << hardware_threads << endl;
	unsigned long const num_threads =
		min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
	cout << "num_threads = " << num_threads << endl;
	unsigned long const block_size = length / num_threads;
	cout << "block_size = " << block_size << endl;
	vector<T> results(num_threads);
	vector<thread> threads(num_threads - 1);

	Iterator block_start = first;
	for (unsigned long i = 0; i < (num_threads - 1); ++i)
	{
		Iterator block_end = block_start;
		//std::advance 增加给定的迭代器指定数量元素的步长
		advance(block_end, block_size);

		threads[i] = thread(
			accumulate_block<Iterator, T>(),
			block_start, block_end, ref(results[i]));
		block_start = block_end;
	}

	accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);

	for_each(threads.begin(), threads.end(),
		mem_fn(&thread::join));

	return accumulate(results.begin(), results.end(), init);
}

int main()
{
	vector<int> vi;
	for (int i = 0; i < 100; ++i)
	{
		vi.push_back(10);
	}

	int sum = parallel_accumulate(vi.begin(), vi.end(), 5);

	cout << "sum = " << sum << endl;

	return 0;
}