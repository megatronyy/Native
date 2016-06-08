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
	void TestUglyNumber();
	void TestReverseList();
	//���N������
	int nthUglyNumber(int n);
private:
	//�ҳ�ÿ����������ڹ���ǰ׺
	string LongestCommonPrefix(vector<string> &strs);
	//�ж������Ƿ�Ϊ����������ֻ�ܱ�2��3��5������
	bool IsUgly(int number);
};

