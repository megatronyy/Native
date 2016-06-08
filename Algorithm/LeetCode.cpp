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

void LeetCode::TestUglyNumber()
{
	int num = 60;
	string result = IsUgly(num) == false ? "否" : "是";
	cout << num << "是否是丑数：" << result << endl;
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