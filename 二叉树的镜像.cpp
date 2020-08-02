#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>

/*
二叉树的镜像:
操作给定的二叉树，将其变换为源二叉树的镜像。
*/

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL)
	{}
};

void Mirror(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	TreeNode* temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
	Mirror(root->left);
	Mirror(root->right);
}

