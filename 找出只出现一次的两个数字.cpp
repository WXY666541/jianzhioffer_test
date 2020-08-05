#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
�ҳ�ֻ����һ�ε���������:
һ�����������������������֮�⣬���������ֶ����������Ρ�
��д�����ҳ�������ֻ����һ�ε�����
*/

void FindNumsAppearOnce(std::vector<int> arr, int* num1, int* num2)
{
	if (arr.empty() || num1 == NULL || num2 == NULL)
	{
		return;
	}

	//�������е��������ֽ������
	int result = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		result ^= arr[i];
	}

	//�ж�����Ľ���Ǹ��Ϸ�
	if (result == 0)
	{
		return;
	}

	//Ѱ��result�б���λΪ1��Ϊ��
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

	//�������
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
