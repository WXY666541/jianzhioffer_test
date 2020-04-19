#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<list>
#include<assert.h>
using namespace std;

#if 0
/*
******************************
��������ĵ�һ�������ڵ�
******************************
*/
struct ListNode
{
	int m_key;
	ListNode* m_pnext;
};

//�õ�������
unsigned int GetListLength(ListNode* pHead)
{
	ListNode* pNode = pHead;
	unsigned int count = 0;
	while (pNode != nullptr)
	{
		count++;
		pNode = pNode->m_pnext;
	}
	return count;
}

ListNode* FindFirstCommonNode(ListNode* pHead1,ListNode* pHead2)
{
	unsigned int length1 = GetListLength(pHead1);
	unsigned int length2 = GetListLength(pHead2);
	int lengthDif = length1 - length2;

	ListNode* pListHeadlong = pHead1;
	ListNode* pListHeadshort = pHead2;
	if (length1 < length2)
	{
		ListNode* pListHeadlong = pHead2;
		ListNode* pListHeadshort = pHead1;
		lengthDif = length2 - length1;
	}

	for (int i = 0; i < lengthDif; i++)
	{
		pListHeadlong = pListHeadlong->m_pnext;
	}

	while ((pListHeadlong != nullptr) && (pListHeadshort != nullptr) && (pListHeadlong != pListHeadshort))
	{
		pListHeadlong = pListHeadlong->m_pnext;
		pListHeadshort = pListHeadshort->m_pnext;
	}

	ListNode* pFirstCommonNode = pListHeadlong;
	return pFirstCommonNode;
}

#endif
/*
******************************
��������ĵ�һ�������ڵ�
******************************
*/
//����һ
int LastRemaining(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;

	unsigned int i = 0;
	list<int> numbers;
	for(i=0;i<n;i++)
	numbers.push_back(i);

	list<int>::iterator current = numbers.begin();

	while (numbers.size() > 1)
	{
		for (int i = 1; i < m; i++)
		{
			current++;
			if (current == numbers.end())
				current = numbers.begin();
		}

		list<int>::iterator next = ++current;
		if (next == numbers.end())
			next = numbers.begin();

		--current;
		numbers.erase(current);
		current = next;
	}

	return *(current);
}

//������
int LastRemaining(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;

	int last = 0;
	for (int i = 2; i <= n; i++)
	{
		last = (last + m) % i;
	}
	return last;
}