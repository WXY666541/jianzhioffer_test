#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>
#include<queue>

/*
二叉树的层序遍历：
从上往下打印出二叉树的每个节点，同层节点从左至右打印
*/
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL)
	{}
};

std::vector<int> Printf(TreeNode* root)
{
	if (root == NULL)
	{
		return std::vector<int>();
	}
	//初始化一个数组和队列
	std::vector<int> result;
	std::queue<TreeNode*> q1;

	//首先将根结点入队
	q1.push(root);

	while (!q1.empty())
	{
		//将队列里面的结点出队
		TreeNode* Node = q1.front();
		q1.pop();

		//将已经出队的元素存放到结果数组当中
		result.push_back(Node->val);

		//出队一个结点的时候把其对应的左右子树入队
		if (Node->left)
		{
			q1.push(Node->left);
		}
		if (Node->right)
		{
			q1.push(Node->right);
		}
		return result;
	}
}
