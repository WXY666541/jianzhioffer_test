#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>

/*
二叉树的子结构
输入两棵二叉树A，B，判断B是不是A的子结构。
（ps：我们约定空树不是任意一个树的子结构）
*/
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):
		val(x),left(NULL),right(NULL)
	{}
};

//在已经确定了起始位置的情况下去比较左右子树是否相等
bool IsSame(TreeNode* begin, TreeNode* begin_sub)
{
	//递归出口
	if (begin_sub == NULL)
	{
		return true;
	}
	if (begin == NULL)//意味着begin_sub != NULL
	{
		return false;
	}
	if (begin->val != begin_sub->val)
	{
		return false;
	}
	//走到这儿就表示当前结点是相等的
	return (IsSame(begin->left,begin_sub->left) && IsSame(begin->right,begin_sub->right));

}
bool HasSubtree(TreeNode* root1, TreeNode* root2)
{
	//特殊情况的判定
	if (root1 == NULL || root2 == NULL )
	{
		return false;
	}
	bool result = false;
	//找到了起始位置
	if (root1->val == root2->val)
	{
		//判定其左右子树是否相等
		result = IsSame(root1, root2);
	}
	//此种情况的出现要么是没有找到起始位置，要么是其左右子树不相等
	//就继续递归在root1的左子树结构中去寻找子结构
	if (result != true)
	{
		result = HasSubtree(root1->left, root2);
	}
	//左子树中没有找到，就继续递归在root1的右子树结构中去寻找子结构
	if (result != true)
	{
		result = HasSubtree(root1->right, root2);
	}
	return result;
}
