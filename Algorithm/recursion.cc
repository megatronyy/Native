#include "recursion.h"

void testRecursion()
{
	printf("请输入多少个数之和：num=");
	int num = 0;
	scanf_s("%d", &num);

	printf("最后的结果是：%d\n", Sum(num));

	printf("请输入多少个数阶乘：num=");
	scanf_s("%d", &num);

	printf("最后的结果是：%d\n", multi(num));

}

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