/*
	表达式中各个符号的具体含义。
　　w[i] :  第i个物体的重量；
  　p[i] : 第i个物体的价值；
　　c[i][m] ： 前i个物体放入容量为m的背包的最大价值；
	c[i-1][m] ： 前i-1个物体放入容量为m的背包的最大价值；
	c[i-1][m-w[i]] ： 前i-1个物体放入容量为m-w[i]的背包的最大价值；
	由此可得：
	c[i][m]=max{c[i-1][m-w[i]]+pi , c[i-1][m]}
*/
#include "knap.h"

int c[10][100] = { 0 };

void knapMethod()
{
	int m, n; int i, j;
	printf("input the max capacity and the number of the goods:\n");
	scanf("%d,%d", &m, &n);
	printf("Input each one(weight and value):\n");
	knap(m, n);
	printf("\n");
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++)
		{
			printf("%4d", c[i][j]);
			if (m == j) printf("\n");
		}
	}
}

void knap(int m, int n)
{
	int i, j, w[10], p[10];
	for (i = 1; i < n + 1; i++) {
		scanf_s("%d, %d", &w[i], &p[i]);
	}
	for (j = 0; j < m + 1; j++) {
		for (i = 0; i < n + 1; i++) {
			if (j < w[i]) {
				c[i][j] = c[i - 1][j];
				continue;
			}
			else if (c[i - 1][j - w[i]] + p[i] > c[i - 1][j]) {
				c[i][j] = c[i - 1][j - w[i]] + p[i];
			}
			else {
				c[i][j] = c[i - ][j];
			}
		}
	}
}