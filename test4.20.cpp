#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<list>
#include<assert.h>
#include <algorithm>
using namespace std;

#if 0
/*
******************************
数组中出现次数超过一半的数字
******************************
*/
//方法一
bool g_bInputInvalid = false;

bool CheckInvalidArray(int* numbers, int length)
{
	g_bInputInvalid = false;
	if (numbers == nullptr || length <= 0)
		g_bInputInvalid = true;

	return g_bInputInvalid;
}
bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] == number)
			times++;
	}

	bool isMoreThanHalf = true;
	if (times * 2 <= length)
	{
		g_bInputInvalid = true;
		isMoreThanHalf = false;
	}

	return isMoreThanHalf;
}
int MoreThanHalfNum(int* numbers, int length)
{
	if (CheckInvalidArray(numbers, length))
		return 0;

	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = partition(numbers, length, start, end);
	while (index != middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = partition(numbers, length, start, end);
		}
		else
		{
			start = index + 1;
			index = partition(numbers, length, start, end);
		}
	}
	int result = numbers[middle];
	if (!CheckMoreThanHalf(numbers, length, result))
		result = 0;
	return result;
}

//方法二
int MoreThanHalfNum(int* numbers, int length)
{
	if (CheckInvalidArray(numbers, length))
		return 0;

	int result = numbers[0];
	int times = 1;
	for (int i = 0; i < length; i++)
	{
		if (times == 0)
		{
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] = result)
			times++;
		else
			times--;
	}
	if (!CheckMoreThanHalf(numbers, length, result))
		result = 0;
	return result;
}
#endif

/*
******************************
最小的K个数
******************************
*/
int GetLeastNumbers(int* input, int n,int *output,int k)
{
	if(input == nullptr || output == nullptr || k>n || n <= 0||k<=0)

	int start = 0;
	int end = n - 1;
	int index = partition(input, n, start, end);
	while (index != k-1)
	{
		if (index > k-1)
		{
			end = index - 1;
			index = partition(input, n, start, end);
		}
		else
		{
			start = index + 1;
			index = partition(input, n, start, end);
		}
	}
	for (int i = 0; i < k; ++i)
		output[i] = input[i];
}