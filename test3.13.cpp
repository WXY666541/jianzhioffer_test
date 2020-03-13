#include<iostream>
using namespace std;
/*
***************************************************************************
��ĿҪ������һ��������ת��������������ı�ͷ��
***************************************************************************
*/

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
//��ʽһ���ǵݹ�ķ�ʽ������һ��pre����pnext���
ListNode* ReverseList(ListNode* pHead) 
{
	if (pHead == NULL)return NULL;//�������Ҫ���Կ���

	ListNode* pnode = pHead;//��ǰָ��
	ListNode* prev = NULL;//��ǰ����ǰһ�����
	ListNode* preverseHead = NULL;//��ת�����ͷָ��

	while (pnode != NULL)
	{
		ListNode* pnext = pnode->next; //���Ͽ�֮ǰһ��Ҫ����Ͽ�λ�ú�ߵĽ��
		if (pnext == NULL)//��pnextΪ�յ�ʱ��
			preverseHead = pnode;//˵����ǰ���Ϊβ���

		//��ת����
		pnode->next = prev;//�ı�ָ��ָ��
		prev = pnode;//����prev���
		pnode = pnext;//����pnode���
	}
	return preverseHead;
}

//�ݹ���
ListNode* ReverseList(ListNode* pHead)
{
	//�������Ϊ�ջ���������ֻ��һ��Ԫ��
	if (pHead == NULL || pHead->next == NULL)return pHead;

	//�ȷ�ת����������ߵ������ĩ�˽��
	ListNode* preverseHead = ReverseList(pHead->next);

	//�ٽ���ǰ�ڵ�����Ϊ����ڵ�ĺ����ڵ�
	pHead->next->next = pHead;
	pHead->next = NULL;

	return preverseHead;
}

/*
***************************************************************************
��ĿҪ�����������������������������������ϳɺ������
          ��Ȼ������Ҫ�ϳɺ���������㵥����������
***************************************************************************
*/
/*����һ���õݹ�ķ�ʽ��
  *���ȣ�Ҫ���������������pHead1Ϊ�ջ���pHaed2Ϊ�յ����
  *��Σ�����˼���ݹ���̣���ΪҪ��ϳɵ�����Ҳ�������Դ���һ���ȽϵĹ���

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

/*���������÷ǵݹ�ķ�ʽ��
  *���ȣ�Ҫ���������������plist1Ϊ�ջ���plist2Ϊ�յ������plist1��plist2��Ϊ�յ����
  *��Σ�����˼��ѭ�����̣��¿���һ������plist���ڴ����������ȽϹ������ֵ
  *��󣬵�plist1�Ƚ���ɣ���plist2���н���ʱ���ټ��뵽plist���漴�ɣ�plist2ͬ��
*/
ListNode* Merge1(ListNode* plist1, ListNode* plist2)
{
	if (plist1 == NULL && plist2 == NULL) return NULL;
	if (plist1 == NULL)return plist2;
	if (plist2 == NULL)return plist1;

	ListNode* plist = new ListNode(0);//�¿���һ������
	ListNode* Head = plist;//�����ͷ���

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
��ĿҪ���������ö�����A��B���ж�B�ǲ���A���ӽṹ��
        ��ps������Լ��������������һ�������ӽṹ��
���������ȣ��ö���һ����־λresult = false,���������proot1��proot2��ΪNULL
      ������£�result = false;
	  ����ҵ���tree2�����������Ӧ�ĵ㣬���������Ϊ����ж��Ƿ����tree2
	  ����Ҳ�������ȥroot�����ӵ�����㣬�ж��Ƿ����tree2���Һ���ͬ��

	  ��Σ������жϹ��̺�����
	  ���tree2Ϊ�գ�˵��tree2�������ˣ������ӽṹ����������ture
	  ���tree1Ϊ�գ�˵��tree1�������ˣ�tree2��û�����꣬�������ӽṹ����������false
	  �������һ�����Բ��ϣ�����flase
	  ��������ƥ����ϣ���ȥ�ֱ�ȥ�ӽڵ�����ȥƥ��
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
	//���tree2�Ѿ��������˶��ܶ�Ӧ�ϣ�����true
	if (pRoot2 == NULL) return true;

	//���tree2��û�����꣬tree1ȴ�������ˣ�����false
	if (pRoot1 == NULL) return false;

	//�������һ����û�ж��ϣ�����false
	if (pRoot2->val != pRoot1->val)return false;

	//���������Ӧ���ˣ���ô�ֱ�ȥ�ӽڵ�����ƥ��
	return doesTree1HaveTree2(pRoot1->left, pRoot2->left) && (pRoot1->right, pRoot2->right);
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool result = false;

	//��tree1��tree2����ΪNULL��ʱ��Ž��бȽϣ�����ֱ�ӷ���false
	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		//����ҵ��˶�Ӧtree2�ĸ����ĵ�
		if (pRoot1->val == pRoot1->val)
		{
			//����������Ϊ����ж��Ƿ����tree2
			result = doesTree1HaveTree2(pRoot1, pRoot2);
		}
	}
	//����Ҳ�������ô����ȥroot�����ӵ�����㣬ȥ�ж�
	if (!result)
	{
		result = HasSubtree(pRoot1->left, pRoot2);
	}
	//����Ҳ�������ô����ȥroot���Һ��ӵ�����㣬ȥ�ж�
	if (!result)
	{
		result = HasSubtree(pRoot1->right, pRoot2);
	}
	return result;
}