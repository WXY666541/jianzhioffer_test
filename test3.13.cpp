#include<iostream>
using namespace std;
/*
***************************************************************************
题目要求：输入一个链表，反转链表后，输出新链表的表头。
***************************************************************************
*/

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
//方式一：非递归的方式，定义一个pre结点和pnext结点
ListNode* ReverseList(ListNode* pHead) 
{
	if (pHead == NULL)return NULL;//特殊情况要加以考虑

	ListNode* pnode = pHead;//当前指针
	ListNode* prev = NULL;//当前结点的前一个结点
	ListNode* preverseHead = NULL;//反转链表的头指针

	while (pnode != NULL)
	{
		ListNode* pnext = pnode->next; //链断开之前一定要保存断开位置后边的结点
		if (pnext == NULL)//当pnext为空的时候
			preverseHead = pnode;//说明当前结点为尾结点

		//反转过程
		pnode->next = prev;//改变指针指向
		prev = pnode;//更新prev结点
		pnode = pnext;//更新pnode结点
	}
	return preverseHead;
}

//递归求法
ListNode* ReverseList(ListNode* pHead)
{
	//如果链表为空或者链表中只有一个元素
	if (pHead == NULL || pHead->next == NULL)return pHead;

	//先反转后面的链表，走到链表的末端结点
	ListNode* preverseHead = ReverseList(pHead->next);

	//再将当前节点设置为后面节点的后续节点
	pHead->next->next = pHead;
	pHead->next = NULL;

	return preverseHead;
}

/*
***************************************************************************
题目要求：输入两个单调递增的链表，输出两个链表合成后的链表，
          当然我们需要合成后的链表满足单调不减规则。
***************************************************************************
*/
/*方法一：用递归的方式。
  *首先，要考虑特殊情况，当pHead1为空或者pHaed2为空的情况
  *其次，再来思考递归过程，因为要求合成的链表也有序，所以存在一个比较的过程

*/
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;
	if (pHead1->val <= pHead2->val)
	{
		pHead1->next = Merge(pHead1->next, pHead2);
		return pHead1;
	}
	else
	{
		pHead2->next = Merge(pHead1, pHead2->next);
		return pHead2;
	}
}

/*方法二：用非递归的方式。
  *首先，要考虑特殊情况，当plist1为空或者plist2为空的情况和plist1和plist2都为空的情况
  *其次，再来思考循环过程，新开辟一个链表plist用于存放两个链表比较过后结点的值
  *最后，当plist1比较完成，但plist2还有结点的时候，再加入到plist后面即可，plist2同理
*/
ListNode* Merge1(ListNode* plist1, ListNode* plist2)
{
	if (plist1 == NULL && plist2 == NULL) return NULL;
	if (plist1 == NULL)return plist2;
	if (plist2 == NULL)return plist1;

	ListNode* plist = new ListNode(0);//新开辟一个链表
	ListNode* Head = plist;//链表的头结点

	while (plist1 != NULL && plist2 != NULL)
	{
		if (plist1->val < plist2->val)
		{
			Head->next = plist1;
			plist1 = plist1->next;
		}
		else
		{
			Head->next = plist2;
			plist2 = plist2->next;
		}
		Head = Head->next;
	}
	if (plist1 != NULL)
	{
		Head->next = plist1;
	}
	if (plist2 != NULL)
	{
		Head->next = plist2;
	}
	return plist->next;
}

/*
***************************************************************************
题目要求：输入两棵二叉树A，B，判断B是不是A的子结构。
        （ps：我们约定空树不是任意一个树的子结构）
分析：首先，得定义一个标志位result = false,特殊情况，proot1和proot2都为NULL
      的情况下，result = false;
	  如果找到了tree2这个树根结点对应的点，就以这个点为起点判断是否包含tree2
	  如果找不到，就去root的左孩子当做起点，判断是否包含tree2。右孩子同理

	  其次，就是判断过程函数。
	  如果tree2为空，说明tree2遍历完了，符合子结构条件，返回ture
	  如果tree1为空，说明tree1遍历完了，tree2还没遍历完，不符合子结构条件，返回false
	  如果其中一个结点对不上，返回flase
	  如果根结点匹配得上，就去分别去子节点里面去匹配
***************************************************************************
*/
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
bool doesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2)
{
	//如果tree2已经遍历完了都能对应上，返回true
	if (pRoot2 == NULL) return true;

	//如果tree2还没遍历完，tree1却遍历完了，返回false
	if (pRoot1 == NULL) return false;

	//如果其中一个点没有对上，返回false
	if (pRoot2->val != pRoot1->val)return false;

	//如果根结点对应上了，那么分别去子节点里面匹配
	return doesTree1HaveTree2(pRoot1->left, pRoot2->left) && (pRoot1->right, pRoot2->right);
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool result = false;

	//当tree1和tree2都不为NULL的时候才进行比较，否则直接返回false
	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		//如果找到了对应tree2的根结点的点
		if (pRoot1->val == pRoot1->val)
		{
			//以这个根结点为起点判断是否包含tree2
			result = doesTree1HaveTree2(pRoot1, pRoot2);
		}
	}
	//如果找不到，那么就再去root的左孩子当做起点，去判断
	if (!result)
	{
		result = HasSubtree(pRoot1->left, pRoot2);
	}
	//如果找不到，那么就再去root的右孩子当做起点，去判断
	if (!result)
	{
		result = HasSubtree(pRoot1->right, pRoot2);
	}
	return result;
}