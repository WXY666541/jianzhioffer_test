#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>
/*
����ѹջ�����ж���ջ����:
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳�򡣼�
��ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ
��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ��������
�ģ�
*/
bool IsPopOrder(std::vector<int> pushv, std::vector<int> popv)
{
	//����������ж�
	if (pushv.size() == 0 || popv.size() == 0 || pushv.size() != popv.size())
	{
		return false;
	}
	//���¶���һ������ջ�ṹ
	std::stack<int> st1;
	int j = 0;
	int i = 0;
	for (; i < pushv.size(); i++)
	{
		//����ѹջ˳��ѹ�븨��ջ
		st1.push(pushv[i]);
		while (!st1.empty() && st1.top() == popv[j]  )
		{
			st1.pop();
			j++;
		}
	}
	return st1.empty();
}
