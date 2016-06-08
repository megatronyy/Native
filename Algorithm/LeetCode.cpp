#include "LeetCode.h"

void LeetCode::TestCommonPrefixMothed()
{
	//string strs[] = {"289","25324","22434","232","234"};
	//vector<string> vstr(strs, strs+5);

	vector<string> vstr;
	vstr.push_back("289");
	vstr.push_back("25324");
	vstr.push_back("22434");
	vstr.push_back("232");
	vstr.push_back("234");

	string prefix = LongestCommonPrefix(vstr);
	cout << "最大公共前缀是：" << prefix << endl;
}
string LeetCode::LongestCommonPrefix(vector<string> &strs)
{
	if(strs.size() == 0)
		return "";

	string prefix = strs[0];

	for(int i=1; i<strs.size(); ++i)
	{
		if(prefix.length() == 0 || strs[i].length() == 0)
			return "";

		int len = prefix.length() < strs[i].length() ? prefix.length() : strs[i].length();
		int j;

		for(j = 0; j < len; ++j)
		{
			if(prefix[j] != strs[i][j])
			{
				break;
			}
		}

		prefix = strs[i].substr(0, j);
	}

	return prefix;
}

void LeetCode::TestNumber()
{
	int num = 60;
	int uglyNum = nthUglyNumber(num);
	cout << "第" << num <<"个丑数是：" << uglyNum << endl;
	string result = IsUgly(uglyNum) == false ? "否" : "是";
	cout << uglyNum << "是否为丑数：" << result << endl;

	int prime = 2147483647;
	result = IsPrime(prime) == false ? "否" : "是";
	cout << prime << "是否为素数：" << result << endl;

}
bool LeetCode::IsUgly(int number)
{
	while (number % 2 == 0)
	{
		number /= 2;
	}
		
	while (number % 3 == 0)
	{
		number /= 3;
	}

	while (number % 5 == 0)
	{
		number /= 5;
	}

	return number == 1 ? true : false; 
}
int LeetCode::nthUglyNumber(int n)
{
	vector<long> twos, threes, fives;
	twos.push_back(1L);
	threes.push_back(1L);
	fives.push_back(1L);

	long minUgly = 0;
	int a = 0, b = 0, c = 0;
	for(int i = 1; i<= n; i++)
	{
		minUgly = min(twos[a], threes[b]);
		minUgly = min(minUgly, fives[c]);

		if(minUgly == twos[a]){ a++; }
		if(minUgly == threes[b]){ b++; }
		if(minUgly == fives[c]){ c++; }

		twos.push_back(minUgly * 2L);
		threes.push_back(minUgly * 3L);
		fives.push_back(minUgly * 5L);
	}

	return (int)minUgly;
}
bool LeetCode::IsPrime(int number)
{
	int k = sqrt(number);
	for(int m = 2; m <= k; m++)
	{
		if(number % m == 0) break;
		if(m > k)
			return true;
		return false;
	}
}