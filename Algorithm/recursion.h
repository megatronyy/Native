#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

extern int Sum(int); //�����Ӻ�
extern int multi(int); //������(�׳�)

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
