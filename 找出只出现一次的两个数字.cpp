#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
找出只出现一次的两个数字:
一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字
*/

void FindNumsAppearOnce(std::vector<int> arr, int* num1, int* num2)
{
	if (arr.empty() || num1 == NULL || num2 == NULL)
	{
		return;
	}

	//对数组中的所有数字进行异或
	int result = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		result ^= arr[i];
	}

	//判断异或后的结果是个合法
	if (result == 0)
	{
		return;
	}

	//寻找result中比特位为1的为数
	int num = sizeof(int);
	int flag = 1;
	for (int i = 0; i < num; i++)
	{
		if ((flag << i) & result)
		{
			flag <<= i;
			break;
		}
	}

	*num1 = 0;
	*num2 = 0;

	//分组异或
	for (int i = 0; i < arr.size(); i++)
	{
		if (flag & arr[i])
		{
			*num1 ^= arr[i];
		}
		else
		{
			*num2 ^= arr[i];
		}
	}
}
