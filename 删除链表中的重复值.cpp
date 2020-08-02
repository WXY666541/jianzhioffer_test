#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>

/*
删除链表中的重复值：
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x):val(x),next(NULL)
	{}
};
ListNode* deleteDuplication(ListNode* head)
{
	//特殊情况判断
	if (head == NULL)
	{
		return NULL;
	}
	//构建一个新的头结点
	ListNode* newhead = new ListNode(0);
	newhead->next = head;

	//定义前后两个指针
	ListNode* pre = newhead;
	ListNode* last = pre->next;

	while (last != NULL)
	{
		//没有遇到重复值的情况
		while (last->next != NULL && last->val != last->next->val)
		{
			pre = pre->next;
			last = last->next;
		}
		//遇到了重复值的情况
		while (last->next != NULL && last->val == last->next->val)
		{
			last = last->next;
		}
		//删除的过程。如果pre->next == last，说明这个区域不存在，不应该删除
		if (pre->next != last)
		{
			pre->next = last->next;
		}
		last = last->next;
	}
	return newhead->next;

}

