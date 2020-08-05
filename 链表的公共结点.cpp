#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
链表的公共结点：
输入两个链表，找出它们的第一个公共结点。
(注意因为传入数据是链表，所以错误测试数据的提示是
用其他方式显示的，保证传入数据是正确的）
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL)
	{}
};

int GetLength(ListNode* list)
{
	int count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return count;
}
ListNode* FindFirstCommonNode(ListNode* phead1, ListNode* phead2)
{
	if (phead1 == NULL || phead2 == NULL)
	{
		return NULL;
	}
	//分别计算两个链表的长度
	int length1 = GetLength(phead1);
	int length2 = GetLength(phead2);

	//计算两个链表相差的长度
	int step = abs(length1 - length2);

	//让更长的链表先走step步
	if (length1 > length2)
	{
		while (step)
		{
			phead1 = phead1->next;
			step--;
		}
	}
	else
	{
		while (step)
		{
			phead1 = phead2->next;
			step--;
		}
	}
	//然后两个链表再一起走
	while (phead1 && phead2)
	{
		if (phead1 == phead2)
		{
			return phead1;
		}
		phead1 = phead1->next;
		phead2 = phead2->next;
	}
	return NULL;
}
