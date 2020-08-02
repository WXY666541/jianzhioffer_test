#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>

/*
反转链表
输入一个链表，反转链表后，输出新链表的表头
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL)
	{}
};


//方法一：结点前插的方式
ListNode* ReverseList(ListNode* head) 
{
	if (head == NULL || head->next == NULL )
	{
		return head;
	}

	ListNode* newhead = NULL;
	while (head != NULL)
	{
		//先从原链表中去掉第一个结点
		ListNode* p = head;
		head = head->next;

		//再将p标识的节点头插到新链表中
		p->next = newhead;
		newhead = p;
	}
	head = newhead;
	return head;
}

//方式二：三个指针的循环操作
ListNode* ReverseList(ListNode* head)
{
	//特殊情况的判定，没有头或者没有结点的情况
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	//初始化左、中、右三个指针
	ListNode* left = head;
	ListNode* mid = left->next;
	ListNode* right = mid->next;

	//逆置后移的过程。条件就是right不为空，因为right
	//一旦不为空则left和mid就肯定不会为空
	while (right)
	{
		//逆置
		mid->next = left;

		//后移
		left = mid;
		mid = right;
		right = right->next;//此时有可能right就为空了，退出循环
	}
	//把最后一个结点逆置
	mid->next = left;
	//让原链表的第一个结点为空
	head->next = NULL;
	//更新现在新的头结点
	head = mid;
	return head;
}
