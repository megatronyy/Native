#include "LCS.h"

char a[500], b[500];
char num[501][501]; //记录中间结果的数组
char flag[501][501]; //标记数组，用于标识下标的走向，构造出公共子序列

void LCSDP()
{
	int i, j;
	for (i = 1; i <= strlen(a); i++)
	{
		for (j = 1; j <= strlen(b); j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				num[i][j] = num[i - 1][j - 1] + 1;
				flag[i][j] = 1; //斜向下标记
			}
			else if (num[i][j - 1] > num[i - 1][j])
			{
				num[i][j] = num[i][j - 1];
				flag[i][j] = 2; //向右标记
			}
			else
			{
				num[i][j] = num[i - 1][j];
				flag[i][j] = 3;//向下标记
			}
		}
	}
}

void getLCSDP()
{
	char res[500];
	int i = strlen(a);
	int j = strlen(b);

	int k = 0; //用于保存结果的数组标志位
	while (i>0 && j>0)
	{
		if (flag[i][j] == 1)
		{
			res[k] = a[i - 1];
			k++;
			i--;
			j--;
		}
		else if (flag[i][j] == 1) {
			j--;
		}
		else {
			i--;
		}
	}

	for (i = k - 1; i >= 0; i--)
	{
		printf("%c", res[i]);
	}
}

void testDpMain()
{
	int i;
	strcpy_s(a, "ABCBDAB");
	strcpy_s(b, "BDCABA");
	//lena = strlen(a);
	//lenb = strlen(b);
	//printf("%d\n", LCS(0, 0));

	memset(num, 0, sizeof(num));
	memset(flag, 0, sizeof(num));
	LCSDP();
	printf("%d\n", num[strlen(a)][strlen(b)]);
	getLCSDP();

	return;
}