#include "QuickSort.h"

void testQuickSort()
{
	int i;
	int arr[9] = {6, 1, 5, 3, 7, 9, 2, 4, 8};
	quicksort(arr, 0, 8);

	for(i = 0; i < 9; ++i)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

void quicksort(int *arr, int left, int right)
{
	int pos;
	if(left < right)
	{
		pos = position(arr, left, right);
		quicksort(arr, left, pos - 1);
		quicksort(arr, pos + 1, right);
	}
}

int findpos(int *arr, int left, int right)
{
	int val = arr[left];
	while (left < right)
	{
		while (left < right && arr[right] > val)
		{
			--right;
		}
		arr[left] = arr[right];

		while (left < right && arr[left] < val)
		{
			++left;
		}
		arr[right] = arr[left];
	}

	arr[left] = val;

	return left;
}

int position(int *arr, int left, int right)
{
	int j;
	int val = arr[right];
	int i = left - 1;
	for(j = left; j<right;j++)
	{
		if(arr[j] <= val)
		{
			i++;
			exchange(arr, i, j);
		}
	}
	exchange(arr, i+1, j);
	//如果数据元素相等，返回(left+right)/2
	//if(i == right)
	return i + 1;	
}

void exchange(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}