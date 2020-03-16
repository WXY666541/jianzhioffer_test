#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
***************************************************
��ĿҪ�󣺲��������Ķ�����������任ΪԴ�������ľ���
�������������ÿ����㣬��������Ľ�����ӽ�㣬��
      ���������ӽ�㣬�����������з�Ҷ�ӽ�������
      ��֧�����󣬾͵õ������ľ���
***************************************************
*/
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
//�ݹ�ʵ��
void Mirror(TreeNode* pRoot) 
{
	if (pRoot == NULL)return;
	if (pRoot->left == NULL && pRoot->right == NULL) return;

	TreeNode* tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;

	if (pRoot->left != NULL)
	{
		Mirror(pRoot->left);
	}
	if (pRoot->right != NULL)
	{
		Mirror(pRoot->right);
	}
}
//ʹ��ջ���Ƚ��������ջ���ٳ�ջ�����������ӽ��
void Mirror(TreeNode* pRoot)
{
	if (pRoot == NULL)return;
	stack<TreeNode*> sk;
	sk.push(pRoot);
	while (sk.size())
	{
		TreeNode* tree = sk.top();
		sk.pop();

		if (tree->left != NULL || tree->right != NULL)
		{
			TreeNode* tmp = tree->left;
			tree->left = tree->right;
			tree->right = tmp;
		}
		if (tree->left)
		{
			sk.push(tree->left);
		}
	    if (tree->right)
		{
			sk.push(tree->right);
		}
	}
}

/*
*************************************************************************
��ĿҪ������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
���磬�����������4 X 4���� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
�����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
������
*************************************************************************
*/
vector<int> printMatrix(vector<vector<int> > matrix) 
{

}

/*
*************************************************************************
��ĿҪ���䶨��ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ
          ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
ע�⣺��֤�����в��ᵱջΪ�յ�ʱ�򣬶�ջ����pop()����min()����top()������
���������¶���һ������ջ����ջ�������ÿ��ѹ����ߵ�������ջ�������Сֵ
*************************************************************************
*/
class Solution {
public:
	stack<int> s1;
	stack<int> smin;
	void push(int value)
	{
		s1.push(value);
		if (smin.empty()) smin.push(value);
		//�����ǰԪ��С�ڸ���ջջ���������Сֵ������ջ
		else if (value <= smin.top())
		{
			smin.push(value);
		}

	}
	void pop() 
	{
		//ֻ�е�����ջ��Ԫ�����ʱ����ʾ��ջԪ��Ϊ��ǰ��СԪ�ء�����ͬʱ��ջ
		if (s1.top() == smin.top())
		{
			smin.pop();
		}
		s1.pop();
	}
	int top() 
	{
		return s1.top();
	}
	int min() 
	{
		return smin.top();
	}
};

/*
*************************************************************************
��ĿҪ�����������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ�������
�Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
��������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�

����������һ������ջ������ѹջ˳���Ƚ���һ������ջ�У�
      ������1,1��=4����ջ
	  ������2,2��=4����ջ
	  ������3,3��=4����ջ
	  ������4,4 ==4����ջ����ջһ��Ԫ�أ��򽫳�ջ˳��4,5,3,2��1������ƶ�һλ
	  ������5,3 !=5, ��ջ�����ѭ����ѹջ˳��������
	  ������5,5 ==5����ջ
	  ������3,3 ==3����ջ����
	  �������ջ��Ϊ�գ�˵���������в��Ǹ�ջ�ĵ���˳��
*************************************************************************
*/
bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
	//��������жϣ�������һ������Ϊ�ջ����������г��Ȳ�ͬ
	if (pushV.empty() || popV.empty || pushV.size() != popV.size())
		return false;
	stack<int> s;
	int j = 0;
	for(int i = 0; i < pushV.size(); i++)
	{  
		//��ѹջ˳��ѹ�븨��ջ��
		s.push(pushV[i]);
		//������ջ�ͳ�ջԪ����ͬʱ��������ջһ��Ԫ�أ���ջԪ�غ���
		while (!s.empty() && s.top() == popV[j])
		{
			s.pop();
			++j;
		}
	}
	//������ջΪ��ʱ��������
	if (s.empty()) return true;
	return false;

}