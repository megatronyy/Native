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

void quicksort(int *arr, int right, int left)
{
	int pos;
	if(right < left)
	{
		pos = findpos(arr, right, left);
		quicksort(arr, right, pos - 1);
		quicksort(arr, pos + 1, left);
	}
}

int findpos(int *arr, int right, int left)
{
	int val = arr[right];
	while (right < left)
	{
		while (right < left && arr[left] > val)
		{
			--left;
		}
		arr[right] = arr[left];

		while (right < left && arr[right] < val)
		{
			++right;
		}
		arr[left] = arr[right];
	}

	arr[right] = val;

	return right;
}