#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>

/*
ջ����Сֵ��
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪ
O��1������
ע�⣺��֤�����в��ᵱջΪ�յ�ʱ�򣬶�ջ����pop()����min()����top()������

*/
class solution
{
private:
	std::stack<int> st1;//����ջ
	std::stack<int> st2;//����ջ
public:
	void push(int x)
	{
		if (st2.empty() || x < st2.top())
		{
			st2.push(x);
		}
		else
		{
			st2.push(st2.top());
		}
		st1.push(x);
	}
	void pop()
	{
		if (st1.size() == 0 || st2.size() == 0)
		{
			return;
		}
		st1.pop();
		st2.pop();
	}
	int top()
	{
		return st1.top();
	}
	int min()
	{
		return st2.top();
	}

};

