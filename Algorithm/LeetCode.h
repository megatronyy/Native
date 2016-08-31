#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

typedef struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
} LISTNODE, *PLISTNODE;

class LeetCode
{
public:
	void TestCommonPrefixMothed();
	void TestNumber();
	//���N������
	int nthUglyNumber(int number);
	//�ж��Ƿ�Ϊ����
	bool IsPrime(int n);
	int KMP(char *A, char *B, int len, int len2);

private:
	//�ҳ�ÿ����������ڹ���ǰ׺
	string LongestCommonPrefix(vector<string> &strs);
	//�ж������Ƿ�Ϊ����������ֻ�ܱ�2��3��5������
	bool IsUgly(int number);
	void get_next(char *T, int *next, int len);
};

