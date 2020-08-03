#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>
#include<queue>

/*
�ж�һ�����������ǲ���ĳ�������ĺ���������
����һ���ǿ��������飬�жϸ������ǲ���ĳ����������
�ĺ�������Ľ��������������Yes,�������No��
�������������������������ֶ�������ͬ��
*/

//����������BST�������һ��Ԫ���Ǹ���㣬��벿�ֵ�ֵС�ڸ�ֵ
//�Ұ벿�ֵ�ֵ���ڸ�ֵ���ص㣬�����еݹ����֤��ǰ���к����Ӧ��������

bool VerifySquenceOfBSTcore(std::vector<int> arr, int start, int end)
{
	//�ݹ������ĳ���
	if (start >= end)
	{
		return true;
	}

	//���ݺ������������ԣ���ȡ����������ֵ
	int root = arr[end];
	int i = 0;

	//���������ҵ������������ٽ�㣬��֤ǰ�벿������ֵ
	while (arr[i] < root && i < end)
	{
		i++;
	}
	//��֤��벿������ֵ
	for (int j = i; j < end; j++)
	{
		if (arr[j] < root)
		{
			return false;
		}
	}

	//��������������������㣬�ߵ���һ��˵����ǰ����ֵ��ȷ���޳�������ٵݹ���֤����������
	return VerifySquenceOfBSTcore(arr, 0, i - 1) && VerifySquenceOfBSTcore(arr, i, end-1);
}
bool VerifySquenceOfBST(std::vector<int> arr)
{
	if (arr.empty())
	{
		return false;
	}
	return VerifySquenceOfBSTcore( arr, 0, arr.size()-1);
}
