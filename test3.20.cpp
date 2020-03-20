#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
/**************************************************************
题目大意：数组中有一个数字出现的次数超过数组长度的一半，
请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
如果不存在则输出0。
***************************************************************/

//方法一：
/*
数组排序后，如果符合条件的数存在，则一定是数组中间那个数
（比如：1，2，2，2，3；或2，2，2，3，4；或2，3，4，4，4等等）
所以，先用快排使数组有序，其时间复杂度是O(NlogN)，并非最优
*/
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	if (numbers.empty()) return 0;
	sort(numbers.begin(), numbers.end());
	int middle = numbers[numbers.size() / 2];

	int count = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] = middle) ++count;
	}
	return (count > numbers.size() / 2) ? middle : 0;
}

//方法二：
/*
采用阵地攻守的思想
第一个数字作为第一个士兵，守阵地，count = 1;
遇到相同元素，count++
遇到不同的元素，即为敌人，同归于尽，count--.当遇到count为0的情况时
又以新的i值作为守阵地士兵，继续下去，到最后还留在阵地上的兵，有可能是主元素
再加一次循环，记录这个士兵的个数看是否大于数组一半即可
*/
int MoreThanHalfNum_Solution1(vector<int> numbers)
{
	if (numbers.empty()) return 0;
	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < numbers.size(); ++i)
	{
		if (times == 0)
		{
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result)
		{
			++times;
		}
		else//不同
		{
			--times;
		}
	}
	times = 0;
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (numbers[i] == result) ++times;
	}
	return (times > numbers.size()/2) ? result : 0;
}

/**************************************************************
题目大意：输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
分析：利用快排中的获取分割（中轴）点的函数partion
基于数组的第k个数字来调整，使得比第k个数字小的所有数字都位于
数组的左边，大的所有数字都位于数组的右边。调整之后，位于数组左边的
k个数字就是最小的k位数
***************************************************************/
void swap(int& fir, int& sec)
{
	int temp = fir;
	fir = sec;
	sec = temp;
}
int getPartution(vector<int>& input, int start,int end)
{
	if (input.empty() || start > end) return -1;
	int temp = input[end];
	int j = start - 1;
	for (int i = start; i < end; i++)
	{
		if (input[i] <= temp)
		{
			++j;
			if (i != j)swap(input[i], input[j]);
		}
	}
	swap(input[j + 1], input[end]);
	return (j + 1);
}
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	vector<int> result;
	if (input.empty() || k > input.size() || k <= 0) return result;

	int start = 0;
	int end = input.size() - 1;
	int index = getPartution(input, start, end);

	while (index != (k - 1))
	{
		if (index > (k - 1))
		{
			end = index - 1;
			index = getPartution(input, start, end);
		}
		else
		{
			start = index + 1;
			index = getPartution(input, start, end);
		}
	}
	for (int i = 0; i < k; i++)
	{
		result.push_back(input[i]);
	}
	return result;
}

