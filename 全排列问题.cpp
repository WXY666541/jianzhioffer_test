#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>
#include<queue>

/*
全排列问题：
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c
所能排列出来的所有字符串 abc,acb,bac,bca,cab 和 cba 。
*/
//解析：把目标串理解成两部分，第一部分是以哪个字符开头
//第二部分就是，剩下的子问题

//交换函数
void swap(std::string& str, int i, int j)
{
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

//去重函数
bool IsExist(std::vector<std::string>& result, std::string& str)
{
	auto it = result.begin();
	for (; it != result.end(); ++it)
	{
		if (*it == str)
		{
			return true;
		}
	}
	return false;
}

//深度优先遍历函数
void Permutation(std::string& str, int start, std::vector<std::string>& result)
{
	if (start == str.length() - 1)
	{
		if (!IsExist(result, str))
		{
			result.push_back(str);
		}
		return;
	}

	for (int i = start; i < str.length(); i++)
	{
		swap(str, start, i);
		Permutation(str, start + 1, result);
		swap(str, start, i);
	}
}


std::vector<std::string> Permutation(std::string str)
{
	std::vector<std::string> result;
	if (str.length() > 0)
	{
		Permutation(str, 0, result);//递归调用，深度优先遍历式查找
		sort(result.begin(), result.end());
	}
	return result;
}

