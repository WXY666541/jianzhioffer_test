#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
������������еĺ�:
{6,-3,-2,7,-15,1,2,2},��������
��������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����һ�����飬
��������������������еĺ�
*/

//����һ�����ö�̬�滮�ķ�ʽ
int FindGreatestSumOfSubArray(std::vector<int> arr) {
	//����������ж�
	if (arr.empty())
	{
		return 0;
	}

	//�¿���һ��һά����dp
	int* dp = new int[arr.size()];

	//��ʼ��
	dp[0] = arr[0];
	int max_value = arr[0];

	//ѭ������Ѱ�����ֵ
	for (int i = 1; i < arr.size(); i++)
	{
		//ת�Ʒ���
		dp[i] = std::max(dp[i - 1] + arr[i], arr[i]);
		if (dp[i] > max_value)
		{
			max_value = dp[i];
		}
	}
	delete dp;
	return max_value;
}

//���Ӹ�Ч�ķ�ʽ
int FindGreateSumOfsubArry(std::vector<int> arr)
{
	//����������ж�
	if (arr.empty())
	{
		return 0;
	}

	//��ʼ��
	int max_value = arr[0];
	int total = arr[0];

	//ѭ������Ѱ�����ֵ
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
