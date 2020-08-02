#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>

/*
栈的最小值：
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为
O（1））。
注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。

*/
class solution
{
private:
	std::stack<int> st1;//数据栈
	std::stack<int> st2;//辅助栈
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

