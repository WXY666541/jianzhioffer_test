#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>
/*
�����еĵ�����k�����:
����һ����������������е�����k����㡣
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x):val(x),next(NULL)
	{}
};

//���ÿ���ָ��ķ�ʽ
ListNode* FindKthToTail(ListNode* head, unsigned int k)
{
	//����������ж�
	if (head == NULL)
	{
		return NULL;
	}

	//��ʼ����������ָ��
	ListNode* fast = head;
	ListNode* low = head;

	//���ÿ�ָ����k�����
	while (k > 0 && fast)
	{
		fast = fast->next;
		k--;
	}

	//����ָ��ͬʱһ����
	while (fast)
	{
		fast = fast->next;
		low = low->next;
	}

	//���Ҫ��k�ĺϷ��Խ���һ���ж�
	return k > 0 ? NULL : low;
}
