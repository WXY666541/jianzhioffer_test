#include<iostream>
#include<vector>
#include<string>
#include<stack> 
/*
二叉树的重建
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结
果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重
建二叉树并返回。

*/
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL)
	{}
};

TreeNode* ConstructBinaryTree(std::vector<int> pre, int pre_start, int pre_end,
	std::vector<int> vin, int vin_start, int vin_end)
{
	//递归中止的条件
	if (pre_start > pre_end || vin_start > vin_end)
	{
		return NULL;
	}

	//创建一个根结点
	TreeNode* root = new TreeNode(pre[pre_start]);

	//在中序序列里面查找根结点的下标
	for (int i = vin_start; i <= vin_end; i++)
	{
		//只用在中序序列里面查找和前序的首元素相等的元素
		if (pre[pre_start] == vin[i])//注意！！！千万不要用root->val的值去比较
		{
			//记住元素个数的计算为pre_start+1+i-vin_start-1
			root->left = ConstructBinaryTree(pre, pre_start + 1, pre_start + i - vin_start, vin, vin_start, i - 1);
			root->right = ConstructBinaryTree(pre, pre_start + i - vin_start + 1, pre_end, vin, i + 1, vin_end);
			break;
		}
	}
	return root;
}
TreeNode* reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin)
{
	//特殊情况的判断
	if (pre.empty() || vin.empty() || pre.size() != vin.size())
	{
		return NULL;
	}
	//重建树的过程
	ConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size());
}
