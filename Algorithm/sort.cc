#include "sort.h"

void testsort()
{
	int arr[6] = {5,3,6,4,2,1};
	int i;
	//sort(arr, 6);
	insertsort(arr, 6);
	for(i = 0; i<6; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void sort(int *a, int len)
{
	int i, j, t;
	for(i = 0; i<len -1; ++i)
	{
		for(j = 0; j<len - 1 - i; ++ j)
		{
			if(a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1]=t;
			}
		}
	}
}

void insertsort(int *a, int len)
{
	int i, j, key;
	for(j = 1; j < len; ++j)
	{
		key = a[j];
		i = j - 1;

		while (i >= 0 && a[i]>key)
		{
			a[i+1] = a[i];
			--i;
		}
		a[i+1] = key;
	}
}

