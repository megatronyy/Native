#include "merge.h"

void testMerge()
{
	int i;
	int arr[7] = {3,4,2,6,1,5,7};
	merge_sort(arr, 0, 6);
	for(i = 0; i<6; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void merge(int *a, int p, int q, int r)
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;

	int *l = (int*)malloc(sizeof(int) * n1);
	int *h = (int*)malloc(sizeof(int) * n2);

	for(i = 0; i < n1; i++)
	{
		 *(l+i) = a[p+i];
	}

	for(j = 0; j < n2; j++)
	{
		 *(h+j) = a[q + j + 1];
	}

	i = 0, j = 0;

	for(k = p; k < r; k++)
	{
		if(l[i] <= h[j])
		{
			a[k] = l[i];
			i++;
		}
		else
		{
			a[k] = h[j];
			j++;
		}
	}
}

void merge_sort(int *a, int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = floor((float)((high - low) / 2));
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}