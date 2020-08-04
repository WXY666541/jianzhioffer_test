#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
Topk����:
����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������
1,2,3,4,��
*/

//ʹ�����ȼ��������
struct comp
{
	bool operator()(const int& a, const int& b)
	{
		return a < b;//��Ҫ���ѣ����Բ��ý�������
	}
};

std::vector<int> TopK(std::vector<int> input, int k)
{
	std::vector<int> list;

	//�������
	if (input.size() < k || input.empty() || k<= 0)
	{
		return std::vector<int>();
	}

	//����һ�����ȼ����У�ʵ�ִ����
	std::priority_queue<int, std::vector<int>, comp> queue;

	//ѭ������,�������ȼ����������ǰk��С����
	for (int i = 0; i < input.size(); i++)
	{
		if (i < k)
		{
			//��ǰk�����ִ浽��������
			queue.push(input[i]);
		}
		else
		{
			//������µ�Ԫ��С��queue�ײ�Ԫ�أ����ֵ�������и���
			if (queue.top() > input[i])
			{
				queue.pop();
				queue.push(input[i]);
			}
		}
	}

	//ѭ��������queue�����ǰk�����ַ��뵽list����
	for (int i = 0; i < k; i++)
	{
		list.push_back(queue.top());
		queue.pop();
	}
	return list;
}
