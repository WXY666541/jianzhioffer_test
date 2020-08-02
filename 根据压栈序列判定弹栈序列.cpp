#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>
/*
根据压栈序列判定弹栈序列:
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假
设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应
的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等
的）
*/
bool IsPopOrder(std::vector<int> pushv, std::vector<int> popv)
{
	//特殊情况的判定
	if (pushv.size() == 0 || popv.size() == 0 || pushv.size() != popv.size())
	{
		return false;
	}
	//重新定义一个辅助栈结构
	std::stack<int> st1;
	int j = 0;
	int i = 0;
	for (; i < pushv.size(); i++)
	{
		//按照压栈顺序压入辅助栈
		st1.push(pushv[i]);
		while (!st1.empty() && st1.top() == popv[j]  )
		{
			st1.pop();
			j++;
		}
	}
	return st1.empty();
}
