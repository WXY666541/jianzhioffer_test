#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<assert.h>
using namespace std;

#if 0
/*
******************************
从尾到头打印链表
******************************
*/
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

void PrintListReversingly_Iteratively(ListNode* pHead)
{
	stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode->m_pNext != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_nKey);
		nodes.pop();
	}
}

void PrintListReversingly_Iteratively1(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->m_pNext != nullptr)
		{
			PrintListReversingly_Iteratively1(pHead->m_pNext);
		}
		printf("%d\t", pHead->m_nKey);
	}
}



/*
******************************
删除链表的节点
******************************
*/
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if (!pListHead || !pToBeDeleted)
		return;

	//要删除的结点不是尾结点
	if (pToBeDeleted->m_pNext != nullptr)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = nullptr;
	}

	//只有一个结点
	else if (*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		pListHead = nullptr;
	}

	//要删除的结点是尾结点
	else
	{
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

#endif
/*
******************************
删除链表的重复节点
******************************
*/

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};
void DeleteDuplication(ListNode** pHead)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;

	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->m_pNext;
		bool needDelete = false;
		if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
			needDelete = true;

		if (!needDelete)
		{
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else
		{
			int value = pNode->m_nValue;
			ListNode* ToBeDel = pNode;
			while (ToBeDel != nullptr && ToBeDel->m_nValue == value)
			{
				pNext = ToBeDel->m_pNext;

				delete ToBeDel;
				ToBeDel = nullptr;

				ToBeDel = pNext;
			}
			if (pPreNode == nullptr)
				*pHead = pNext;
			pPreNode->m_pNext = pNext;
			pNode = pNext;
		}
	}
}