#include "merge.h"

void testMerge()
{
	int i;
	//int arr[16] = {3, 4, 2, 6, 1, 5, 7, 9, 10, 8, 13, 11, 18, 31, 19};
	const int len = 50000;
	int arr[len];
	srand((unsigned int)time(0));
	
	for(i = 0; i < len; ++i)
	{
		arr[i] = rand();
	}

	merge_sort(arr, 0, len -1);
	for(i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void merge(int *a, int start, int middle, int end)
{
	int i, j=0, k;
	int n1 = middle - start + 1;
	int n2 = end - middle;

	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];

	for(i = 0; i < n1; i++)
	{
		*(L+i) = *(a + start + i);
	}
	*(L + n1) = 1000000;

	for(i = 0; i < n1; i++)
	{
		*(R+i) = *(a + middle + i + 1);
	}
	*(R + n2) = 1000000;

	i = 0;

	for(k = start; k <= end; k++)
	{
		if(L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
	}

	delete [] L;
	delete [] R;
}

void merge_sort(int *a, int start, int end)
{
	int mid;
	if(start < end)
	{
		mid =(start + end) / 2;
		merge_sort(a, start, mid);
		merge_sort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}