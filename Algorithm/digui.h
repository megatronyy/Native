/*
�ݹ�Ķ��壺
һ������ֱ�ӻ��߼�ӵĵ����Լ���

�ݹ�������������
1���ݹ�������һ����ȷ����ֹ��������
2���ú�������������ݹ�ģ�����ڵݼ���
3�����ת�������ǿɽ�ġ�

�ݹ���ѭ���ıȽ�
�ݹ飺
�������
�ٶ���
�洢�ռ��
ѭ��
�������
�ٶȿ�
�洢�ռ�С

��ŵ��
α�㷨��
�������ӣ�A��B��C
if(n > 1)
{
�Ȱ�A�����ϵ�ǰn-1�����Ӵ�A����C�Ƶ�B
��A�����ϵĵ�n������ֱ���Ƶ�C
�ٽ�B�����ϵ�n-1�����ӽ���A�Ƶ�C
}

n���ܴ���64
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

extern void hannuota(int n, char A, char B, char C);

void testHannuota()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	printf("������Ҫ�ƶ����ӵĸ���:");
	scanf_s("%d", &n);
	printf("\n");
	  
	hannuota(n, ch1, ch2, ch3);
}

