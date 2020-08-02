#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>

/*
ɾ�������е��ظ�ֵ��
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
�ظ��Ľ�㲻��������������ͷָ�롣 
���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
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
	//��������ж�
	if (head == NULL)
	{
		return NULL;
	}
	//����һ���µ�ͷ���
	ListNode* newhead = new ListNode(0);
	newhead->next = head;

	//����ǰ������ָ��
	ListNode* pre = newhead;
	ListNode* last = pre->next;

	while (last != NULL)
	{
		//û�������ظ�ֵ�����
		while (last->next != NULL && last->val != last->next->val)
		{
			pre = pre->next;
			last = last->next;
		}
		//�������ظ�ֵ�����
		while (last->next != NULL && last->val == last->next->val)
		{
			last = last->next;
		}
		//ɾ���Ĺ��̡����pre->next == last��˵��������򲻴��ڣ���Ӧ��ɾ��
		if (pre->next != last)
		{
			pre->next = last->next;
		}
		last = last->next;
	}
	return newhead->next;

}

