#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
正整数拼接输出最小数字:
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一
个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/
class Solution
{
	static bool cmp(int x, int y)
	{
		std::string sx = std::to_string(x);
		std::string sy = std::to_string(y);

		std::string A = sx + sy;
		std::string B = sy + sx;

		return A < B;
	}
public:
	std::string PrintMinNumber(std::vector<int> arr)
	{
		std::string result = "";
		if (arr.size() == 0)
		{
			return result;
		}

		//使用sort函数对数组里面的所有整数进行排序
		sort(arr.begin(), arr.end(), cmp);

		//挨个遍历数组中的元素，使用to_string的方式转成字符串过后拼接到结果字符串中
		for ( unsigned int i = 0; i < arr.size(); i++)
		{
			result += std::to_string(arr[i]);
		}
		return result;
	}

};

