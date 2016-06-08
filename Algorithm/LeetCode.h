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
	//求第N个丑数
	int nthUglyNumber(int number);
	//判断是否为素数
	bool IsPrime(int n);
private:
	//找出每个数组的最在公用前缀
	string LongestCommonPrefix(vector<string> &strs);
	//判断数字是否为丑数，丑数只能被2，3，5，整除
	bool IsUgly(int number);
};

