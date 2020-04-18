#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<assert.h>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

#if 0
/*
******************************
反转链表
******************************
*/
ListNode* ReverseList(ListNode* phead)
{
	ListNode* ReverseHead = nullptr;
	ListNode* pnode = phead;
	ListNode* prev = nullptr;

	while (pnode != nullptr)
	{
		ListNode* pnext = pnode->m_pNext;

		//只有一个结点的情况
		if (pnext == nullptr)
			ReverseHead = pnode;

		pnode->m_pNext = prev;
		prev = pnode;
		pnode = pnext;
	}
	return ReverseHead;
}


/*
******************************
合并两个排序的链表
******************************
*/
ListNode* Merge(ListNode* p1, ListNode* p2)
{
	if (p1 == nullptr)
		return p2;
	else if (p2 == nullptr)
		return p1;

	ListNode* Mergelist = nullptr;

	if (p1->m_nKey < p2->m_nKey)
	{
		Mergelist = p1;
		Mergelist->m_pNext = Merge(p1->m_pNext, p2);
	}
	else
	{
		Mergelist = p2;
		Mergelist->m_pNext = Merge(p1, p2->m_pNext);
	}
	return Mergelist;
}
#endif

/*
******************************
复杂链表的复制
******************************
*/
struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		ComplexListNode* pCloned = new ComplexListNode();
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;
		pCloned->m_pSibling = nullptr;

		pNode->m_pNext = pCloned;
		pNode = pCloned->m_pNext;
	}
}

void ConnectSibilingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		ComplexListNode* pCloned = pNode->m_pNext;
		if (pNode->m_pSibling != nullptr)
		{
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}

		pNode = pCloned->m_pNext;
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	ComplexListNode* pCloneHead = nullptr;
	ComplexListNode* pCloneNode = nullptr;

	if (pNode != nullptr)
	{
		pCloneHead = pCloneNode = pNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	while (pNode != nullptr)
	{
		pCloneNode->m_pNext = pNode->m_pNext;
		pCloneNode = pCloneNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	return pCloneHead;
}

ComplexListNode* Clone(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSibilingNodes(pHead);
	return ReconnectNodes(pHead);
}