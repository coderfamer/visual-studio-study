// test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void printfArry(int *a)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
}

int main()
{

	int i = 0, j = 0;
	int tmp = 0;
	int a[10] = { 1,3,44,3,5,43,5,5,6,67 };
	printf("\nbefore sort: \n");
	printfArry(a);
	for (i = 0; i < 10; i++)
	{
		for (j = j + 1; j < 10; j++)
		{
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;

		}
	}

	printf("\nafter sort:\n");
	printfArry(a);

	system("pause");
    return 0;
}

