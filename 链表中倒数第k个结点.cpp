#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>
/*
链表中的倒数第k个结点:
输入一个链表，输出该链表中倒数第k个结点。
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x):val(x),next(NULL)
	{}
};

//采用快慢指针的方式
ListNode* FindKthToTail(ListNode* head, unsigned int k)
{
	//特殊情况的判断
	if (head == NULL)
	{
		return NULL;
	}

	//初始化快慢两个指针
	ListNode* fast = head;
	ListNode* low = head;

	//先让快指针走k个结点
	while (k > 0 && fast)
	{
		fast = fast->next;
		k--;
	}

	//两个指针同时一起走
	while (fast)
	{
		fast = fast->next;
		low = low->next;
	}

	//最后要对k的合法性进行一个判断
	return k > 0 ? NULL : low;
}
