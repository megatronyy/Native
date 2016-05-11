#include "recursion.h"

int Sum(int n)
{
	if (1 == n)
		return 1;
	else
		return Sum(n - 1) + n;
}

int multi(int n)
{
	if (1 == n)
		return 1;
	else
		return multi(n - 1) * n;
}