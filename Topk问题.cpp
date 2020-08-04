#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
Topk问题:
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是
1,2,3,4,。
*/

//使用优先级队列求解
struct comp
{
	bool operator()(const int& a, const int& b)
	{
		return a < b;//需要最大堆，所以采用降序排序
	}
};

std::vector<int> TopK(std::vector<int> input, int k)
{
	std::vector<int> list;

	//特殊情况
	if (input.size() < k || input.empty() || k<= 0)
	{
		return std::vector<int>();
	}

	//定义一个优先级队列，实现大根堆
	std::priority_queue<int, std::vector<int>, comp> queue;

	//循环遍历,更新优先级队列里面的前k个小的数
	for (int i = 0; i < input.size(); i++)
	{
		if (i < k)
		{
			//把前k个数字存到容器当中
			queue.push(input[i]);
		}
		else
		{
			//如果有新的元素小于queue首部元素（最大值），进行更新
			if (queue.top() > input[i])
			{
				queue.pop();
				queue.push(input[i]);
			}
		}
	}

	//循环遍历将queue里面的前k个数字放入到list里面
	for (int i = 0; i < k; i++)
	{
		list.push_back(queue.top());
		queue.pop();
	}
	return list;
}
