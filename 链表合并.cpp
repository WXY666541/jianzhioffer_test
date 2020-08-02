#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>

/*
链表合并
输入两个单调递增的链表，输出两个链表合成后的链表，
当然我们需要合成后的链表满足单调不减规则。
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x):val(x),next(NULL)
	{}
};

//方法一：非递归的方式
ListNode* Merge(ListNode* phead1, ListNode* phead2)
{
	//判定为空的特殊情况
	if (phead1 == NULL)
	{
		return phead2;
	}
	if (phead2 == NULL)
	{
		return phead1;
	}

	//定义合并链表的头尾
	ListNode* head = NULL;
	ListNode* tail = NULL;

	//合并过程，条件就是两张链表都不为空的时候
	while (phead1  && phead2 )
	{
		//比较结点值大小
		ListNode* p = phead1->val < phead2->val ?  phead1 : phead2;

		//结点值更小的链表后移的过程
		if (p == phead1)
		{
			phead1 = phead1->next;
		}
		else 
		{
			phead2 = phead2->next;
		}

		//第一次插入的特殊情况
		if (head == NULL)
		{
			head = p;
			tail = p;
		}
		//采用尾插的方式
		else
		{
			tail->next = p;
			tail = p;
		}
	}

	//最后两个链表中有一个为空的特殊情况
	if (phead1 == NULL)
	{
		tail->next = phead2;
	}
	else if (phead2 == NULL)
	{
		tail->next = phead1;
	}
	else
	{
	}
	return head;
}

//方法二：递归的方式
ListNode* Merge1(ListNode* phead1, ListNode* phead2)
{
	//递归出口
	if (phead1 == NULL)
	{
		return phead2;
	}
	if (phead2 == NULL)
	{
		return phead1;
	}

	//定义一个新的链表
	ListNode* head = NULL;

	//寻找值更小的结点
	if (phead1->val < phead2->val)
	{
		head = phead1;
		phead1 = phead1->next;
	}
	else
	{
		head = phead2;
		phead2 = phead2->next;
	}
	//递归的过程
	head->next = Merge1(phead1, phead2);
	return head;
}

