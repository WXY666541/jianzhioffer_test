#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
����Ĺ�����㣺
�������������ҳ����ǵĵ�һ��������㡣
(ע����Ϊ�����������������Դ���������ݵ���ʾ��
��������ʽ��ʾ�ģ���֤������������ȷ�ģ�
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
	//�ֱ������������ĳ���
	int length1 = GetLength(phead1);
	int length2 = GetLength(phead2);

	//���������������ĳ���
	int step = abs(length1 - length2);

	//�ø�������������step��
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
	//Ȼ������������һ����
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
