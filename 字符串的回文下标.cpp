#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
字符串的回文：
给定一个仅由小写字母组成的字符串。现在请找出一个位置，
删掉那个字母之后，字符串变成回文。请放心总会有一个合法的解。
如果给定的字符串已经是一个回文串，那么输出-1。
*/
bool IsPalindrome(std::string s, int* start, int* end)
{
	//初始化i和j的值分别用于向前向后的遍历
	int i = 0;
	int j = s.size()-1;

	bool result = true;
	while (i <= j)
	{
		//表示不是回文序列，返回false
		if (s[i] != s[j])
		{
			result = false;
			break;
		}
		i++;
		j--;
	}

	//判断是否将下标的值传出去
	if (start != nullptr) *start = i;
	if (end != nullptr) *end = j;
	return result;
}
int main()
{
	int num;
	std::cin >> num;

	//循环输入num条字符串，进行判断
	while (num)
	{
		std::string s;
		std::cin >> s;

		//初始化字符串的起始末尾位置
		int start = 0;
		int end = s.size() - 1;

		//如果是回文序列直接返回-1
		if (IsPalindrome(s, &start, &end))
		{
			std::cout << -1 << std::endl;
		}
		else
		{
			//删除end所指向的字符
			s.erase(end,1);

			//继续判断是否是回文序列
			if (IsPalindrome(s, nullptr,nullptr))
			{
				//如果还是回文序列就返回end下标的值
				std::cout << end << std::endl;
			}
			else
			{
				//如果不是就返回另外的start下标
				std::cout << start << std::endl;
			}
		}
		num--;
	}
}
