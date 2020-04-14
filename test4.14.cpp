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
��β��ͷ��ӡ����
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
ɾ������Ľڵ�
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

	//Ҫɾ���Ľ�㲻��β���
	if (pToBeDeleted->m_pNext != nullptr)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = nullptr;
	}

	//ֻ��һ�����
	else if (*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		pListHead = nullptr;
	}

	//Ҫɾ���Ľ����β���
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
ɾ��������ظ��ڵ�
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