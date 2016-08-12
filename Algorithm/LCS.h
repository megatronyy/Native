
#pragma once

#include<stdio.h>
#include<string.h>

/*
�ݹ������������������
LCS(i,j) = {
1��1+LCS(i+1, j+1)					a[i]=b[j]
2��MAX(LCS(i, j+1), LCS(i+1, j))    a[i]!=b[j]
}
*/
//char a[30], b[30];
//int lena, lenb;
//���������ֱ��ʾ��������±�
//int LCS(int i, int j)
//{
//	if (i >= lena || j >= lenb)
//		return 0;
//	if (a[i] == b[j])
//		return 1 + LCS(i + 1, j + 1);
//	else
//	{
//		int aVal = LCS(i + 1, j);
//		int bVal = LCS(i, j + 1);
//		return aVal > bVal ? aVal : bVal;
//	}
//}

/*
	��̬�滮��������������
	״̬ת�Ʒ���ʽ��
	num[i][j]={
		1��0										i=0����j=0
		2��1 + num[i-1][j - 1]						i,j>0, a[i]=b[j]
		3��MAX{num[i][j-1], num[i-1][j]}
	}
*/

extern void LCSDP();
extern void getLCSDP();
extern void testDpMain();
