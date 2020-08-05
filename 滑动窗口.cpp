#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
/*
滑动窗口：
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是
他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另
一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的
连续正数序列?
*/
std::vector<std::vector<int>> FindContinuousSequence(int sum)
{
	std::vector<std::vector<int>> result;

	//初始化序列的两个边界值
	int low = 1;
	int high = 2;

	//循环查找
	while (low < high)
	{
		int total = (low + high) * (high - low + 1) / 2;
		if (total == sum)
		{
			std::vector<int> list;
			for (int i = low; i <= high; i++)
			{
				list.push_back(i);
			}
			result.push_back(list);
			low++;
		}
		else if (total < sum)
		{
			high++;
		}
		else
		{
			low++;
		}
	}
	return result;
}
