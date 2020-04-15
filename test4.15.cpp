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
寻找链表的倒数第k个结点
******************************
*/
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == nullptr || k == 0)//细节1、3
		return nullptr;

	ListNode* p1 = pListHead;
	ListNode* p2 = nullptr;

	for (unsigned int i = 0; i < k-1; i++)
	{
		if (p1->m_pNext != nullptr)//细节2
			p1 = p1->m_pNext;
		else
			return nullptr;
	}
	p2 = pListHead;
	while (p1->m_pNext != nullptr)
	{
		p1 = p1->m_pNext;
		p2 = p2->m_pNext;
	}
	return p2;
}
#endif
/*
******************************
链表中环的入口结点
******************************
*/
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

ListNode* MeetingNode(ListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;

	ListNode* pslow = pHead->m_pNext;
	if (pslow == nullptr)
		return nullptr;
	ListNode* pfast = pslow->m_pNext;
	while (pslow != nullptr && pfast != nullptr)
	{
		if (pslow == pfast)
			return pfast;

		pslow = pslow->m_pNext;
		pfast = pfast->m_pNext;
		if (pfast != nullptr)
			pfast = pfast->m_pNext;
	}
	return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetingNode = MeetingNode(pHead);
	if (meetingNode == nullptr)
		return nullptr;

	//得到环中的数量
	int count = 1;
	ListNode* pNode1 = meetingNode;
	while (pNode1 != meetingNode)
	{
		pNode1 = pNode1->m_pNext;
		count++;
	}

	//先移动p1,次数为环中的结点数目
	ListNode* p1 = pHead;
	for (int i = 0; i < count; i++)
	{
		p1 = p1->m_pNext;
	}

	//再移动p1和p2
	ListNode* p2 = pHead;
	while (p1 != p2)
	{
		p1 = p1->m_pNext;
		p2 = p2->m_pNext;
	}
	return p1;
}