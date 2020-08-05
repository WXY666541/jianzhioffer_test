#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
求二叉树的深度：
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点
（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL)
	{}
};

//方法一：采用优化后的递归
int TreeDepth(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + max(TreeDepth(root->left),TreeDepth(root->right));
}

//方法二：采用一般递归
void TreeDepthHelper(TreeNode* root, int cur, int& max_size)
{
	//遍历到了叶子结点，递归退出的条件
	if (root == NULL)
	{
		if (cur > max_size)
		{
			max_size = cur;
		}
		return;
	}

	//左右子树递归遍历
	TreeDepthHelper(root->left, cur + 1, max_size);
	TreeDepthHelper(root->right, cur + 1, max_size);
}
int TreeDepth(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	//初始化一个长度和最大值
	int length = 0;
	int max_size = 0;

	//递归调用计算最大值
	TreeDepthHelper(root, length, max_size);
	return max_size;
}

//方法三：采用层序遍历的方式
int TreeDepth(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	//初始化一个队列，用户层序遍历
	std::queue<TreeNode*> q1;
	q1.push(root);

	//初始化一个高度
	int depth = 0;
	while (!q1.empty())
	{
		//初始化一个size计算当前层结点数
		int size = q1.size();
		depth++;
		for (int i = 0; i < size; i++)
		{
			TreeNode* Node = q1.front();
			q1.pop();

			if (Node->left)
			{
				q1.push(Node->left);
			}
			if (Node->right)
			{
				q1.push(Node->right);
			}
		}
	}
	return depth;
}
