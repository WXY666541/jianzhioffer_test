#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
最大连续子序列的和:
{6,-3,-2,7,-15,1,2,2},连续子向
量的最大和为8(从第0个开始,到第3个为止)。给一个数组，
返回它的最大连续子序列的和
*/

//方法一，采用动态规划的方式
int FindGreatestSumOfSubArray(std::vector<int> arr) {
	//特殊情况的判断
	if (arr.empty())
	{
		return 0;
	}

	//新开辟一个一维数组dp
	int* dp = new int[arr.size()];

	//初始化
	dp[0] = arr[0];
	int max_value = arr[0];

	//循环遍历寻找最大值
	for (int i = 1; i < arr.size(); i++)
	{
		//转移方程
		dp[i] = std::max(dp[i - 1] + arr[i], arr[i]);
		if (dp[i] > max_value)
		{
			max_value = dp[i];
		}
	}
	delete dp;
	return max_value;
}

//更加高效的方式
int FindGreateSumOfsubArry(std::vector<int> arr)
{
	//特殊情况的判断
	if (arr.empty())
	{
		return 0;
	}

	//初始化
	int max_value = arr[0];
	int total = arr[0];

	//循环遍历寻找最大值
	for (int i = 1; i < arr.size(); i++)
	{
		if (total > 0)
		{
			total += arr[i];
		}
		else
		{
			total = arr[i];
		}
		if (total > max_value)
		{
			max_value = total;
		}
	}
	return max_value;
}
