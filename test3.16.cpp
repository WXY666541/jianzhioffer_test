#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
***************************************************
题目要求：操作给定的二叉树，将其变换为源二叉树的镜像。
分析：先序遍历每个结点，如果遍历的结点有子结点，就
      交换两个子结点，当交换完所有非叶子结点的左右
      分支结点过后，就得到了树的镜像
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
//递归实现
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
//使用栈，先将根结点入栈，再出栈交换其两个子结点
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
题目要求：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
分析：
*************************************************************************
*/
vector<int> printMatrix(vector<vector<int> > matrix) 
{

}

/*
*************************************************************************
题目要求：输定义栈的数据结构，请在该类型中实现一个能够得到栈
          中所含最小元素的min函数（时间复杂度应为O（1））。
注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。
分析：重新定义一个辅助栈，该栈保存的是每次压入或者弹出过后栈里面的最小值
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
		//如果当前元素小于辅助栈栈顶保存的最小值，则入栈
		else if (value <= smin.top())
		{
			smin.push(value);
		}

	}
	void pop() 
	{
		//只有当两个栈的元素相等时，表示出栈元素为当前最小元素。所以同时出栈
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
题目要求：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列
是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

分析：借用一个辅助栈，遍历压栈顺序，先将第一个放入栈中，
      这里是1,1！=4，入栈
	  这里是2,2！=4，入栈
	  这里是3,3！=4，入栈
	  这里是4,4 ==4，出栈，出栈一个元素，则将出栈顺序（4,5,3,2，1）向后移动一位
	  这里是5,3 !=5, 入栈。如此循环等压栈顺序遍历完成
	  这里是5,5 ==5，出栈
	  这里是3,3 ==3，出栈……
	  如果辅助栈不为空，说明弹出序列不是该栈的弹出顺序
*************************************************************************
*/
bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
	//特殊情况判断，当其中一个序列为空或者两个序列长度不同
	if (pushV.empty() || popV.empty || pushV.size() != popV.size())
		return false;
	stack<int> s;
	int j = 0;
	for(int i = 0; i < pushV.size(); i++)
	{  
		//将压栈顺序压入辅助栈中
		s.push(pushV[i]);
		//当辅助栈和出栈元素相同时，出辅助栈一个元素，出栈元素后移
		while (!s.empty() && s.top() == popV[j])
		{
			s.pop();
			++j;
		}
	}
	//当辅助栈为空时，返回真
	if (s.empty()) return true;
	return false;

}