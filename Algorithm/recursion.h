#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

extern int Sum(int); //连续加合
extern int multi(int); //连续乘(阶乘)

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
