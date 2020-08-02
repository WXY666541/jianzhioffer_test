#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>

/*
����ϲ�
���������������������������������ϳɺ������
��Ȼ������Ҫ�ϳɺ���������㵥����������
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x):val(x),next(NULL)
	{}
};

//����һ���ǵݹ�ķ�ʽ
ListNode* Merge(ListNode* phead1, ListNode* phead2)
{
	//�ж�Ϊ�յ��������
	if (phead1 == NULL)
	{
		return phead2;
	}
	if (phead2 == NULL)
	{
		return phead1;
	}

	//����ϲ������ͷβ
	ListNode* head = NULL;
	ListNode* tail = NULL;

	//�ϲ����̣�������������������Ϊ�յ�ʱ��
	while (phead1  && phead2 )
	{
		//�ȽϽ��ֵ��С
		ListNode* p = phead1->val < phead2->val ?  phead1 : phead2;

		//���ֵ��С��������ƵĹ���
		if (p == phead1)
		{
			phead1 = phead1->next;
		}
		else 
		{
			phead2 = phead2->next;
		}

		//��һ�β�����������
		if (head == NULL)
		{
			head = p;
			tail = p;
		}
		//����β��ķ�ʽ
		else
		{
			tail->next = p;
			tail = p;
		}
	}

	//���������������һ��Ϊ�յ��������
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

//���������ݹ�ķ�ʽ
ListNode* Merge1(ListNode* phead1, ListNode* phead2)
{
	//�ݹ����
	if (phead1 == NULL)
	{
		return phead2;
	}
	if (phead2 == NULL)
	{
		return phead1;
	}

	//����һ���µ�����
	ListNode* head = NULL;

	//Ѱ��ֵ��С�Ľ��
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
	//�ݹ�Ĺ���
	head->next = Merge1(phead1, phead2);
	return head;
}

