#include "SteelCutDP.h"

int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int r[11] = { -1 }, s[11] = {-1};

int bottom_up_cut_aux(int n)
{
	int j, i, q, a;
	r[0] = 0;
	for (j = 1; j <= n; j++)
	{
		q = -1;
		for (i = 1; i <= j; i++)
		{
			a = p[i] + r[j - i];
			if (q < a)
			{
				q = a;
				s[j] = i;
			}
			//q = a > q ? a : q;
		}
		r[j] = q;
	}
	return r[n];
}
void print_cut_rod_solution(int n)
{
	int v = bottom_up_cut_aux(n);
	printf_s("最大价值：%d\n", v);

	while (n > 0)
	{
		printf_s("切割方案：%d\n", s[n]);
		n = n - s[n];
	}
}

int top_down_cut(int n)
{
	return top_down_cut_aux(n);
}

int top_down_cut_aux(int n)
{
	int i, q, a;
	if (r[n] >= 0)
		return r[n];
	if (n == 0)
	{
		q = 0;
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			q = 0;
			a = p[i] + top_down_cut_aux(n - i);
			q = q > a ? q : a;
		}
	}
	r[n] = q;
	return q;
}

void testSteelMain()
{
	print_cut_rod_solution(7);
}