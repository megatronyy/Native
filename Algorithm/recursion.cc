#include "recursion.h"

void testRecursion()
{
	printf("��������ٸ���֮�ͣ�num=");
	int num = 0;
	scanf_s("%d", &num);

	printf("���Ľ���ǣ�%d\n", Sum(num));

	printf("��������ٸ����׳ˣ�num=");
	scanf_s("%d", &num);

	printf("���Ľ���ǣ�%d\n", multi(num));

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