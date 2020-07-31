#include<iostream>
#include<vector>
#include<string>
#include<stack> 
/*
��������
����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��
*/

//����һ�����ýڵ�ǰ��ķ�ʽ
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x):val(x),next(NULL)
	{}
};

void Reverse(ListNode* plist)
{
	if (plist == NULL || plist->next == NULL || plist->next->next == NULL)
	{
		return;
	}
	ListNode* p = plist->next;
	ListNode* q;

	plist->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = plist->next;
		plist->next = p;

		p = q;
	}
}

//��ʽ��������ջ
std::vector<int> Reverse1(ListNode* plist)
{
	std::vector<int> res;
	if (plist == NULL)
	{
		return res;
	}

	std::stack<int> st;
	while (plist != NULL)
	{
		st.push(plist->val);
		plist = plist->next;
	}

	while (!st.empty())
	{
		res.push_back(st.top());
		st.pop();
	}
	return res;
}

//��ʽ��������vector���������reverse����
std::vector<int> Reverse2(ListNode* plist)
{
	std::vector<int> res;
	while (plist)
	{
		res.push_back(plist->val);
		plist = plist->next;
	}
	reverse(res.begin(),res.end());
	return res;
}
