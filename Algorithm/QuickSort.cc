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
		pos = findpos(arr, left, right);
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