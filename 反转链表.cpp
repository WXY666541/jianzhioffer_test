#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>

/*
��ת����
����һ��������ת��������������ı�ͷ
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL)
	{}
};


//����һ�����ǰ��ķ�ʽ
ListNode* ReverseList(ListNode* head) 
{
	if (head == NULL || head->next == NULL )
	{
		return head;
	}

	ListNode* newhead = NULL;
	while (head != NULL)
	{
		//�ȴ�ԭ������ȥ����һ�����
		ListNode* p = head;
		head = head->next;

		//�ٽ�p��ʶ�Ľڵ�ͷ�嵽��������
		p->next = newhead;
		newhead = p;
	}
	head = newhead;
	return head;
}

//��ʽ��������ָ���ѭ������
ListNode* ReverseList(ListNode* head)
{
	//����������ж���û��ͷ����û�н������
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	//��ʼ�����С�������ָ��
	ListNode* left = head;
	ListNode* mid = left->next;
	ListNode* right = mid->next;

	//���ú��ƵĹ��̡���������right��Ϊ�գ���Ϊright
	//һ����Ϊ����left��mid�Ϳ϶�����Ϊ��
	while (right)
	{
		//����
		mid->next = left;

		//����
		left = mid;
		mid = right;
		right = right->next;//��ʱ�п���right��Ϊ���ˣ��˳�ѭ��
	}
	//�����һ���������
	mid->next = left;
	//��ԭ����ĵ�һ�����Ϊ��
	head->next = NULL;
	//���������µ�ͷ���
	head = mid;
	return head;
}
