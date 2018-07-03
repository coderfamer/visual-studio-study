
#include <iostream>

using namespace std;

void print_arr(int arr[], int n)
{
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << "";
	}
	cout << endl;
}


void quick_sort(int arr[], int l, int r)
{
	int beg = l;
	int end = r;
	int key = arr[l];

	if (beg > end)
	{
		return;
	}

	while (beg < end)
	{
		while (arr[end] >= key && beg < end)
		{
			end--;
		}
		if (key >= arr[end])
		{
			int temp = arr[end];
			arr[end] = arr[beg];
			arr[beg] = temp;
		}
		//print_arr(arr, 7);
		while (arr[beg] <= key && beg < end)
		{
			beg++;
		}
		if (key <= arr[beg])
		{ 
			int temp = arr[beg];
			arr[beg] = arr[end];
			arr[end] = temp;
		}
		print_arr(arr, 7);
	}
	
	quick_sort(arr, l, beg - 1);
	quick_sort(arr, end + 1, r);
}


int main()
{
	int arr[] = { 6, 2, 7, 1, 5, 4, 3, 8 };
	quick_sort(arr, 0, 7);
	print_arr(arr, 7);
	system("pause");
	return 0;
}