#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
using namespace std;

/*
******************************
二叉搜索树的后序遍历序列
******************************
*/
bool VerifySequenceOfBST(int arr[], int length)
{
	if (arr == nullptr || length <= 0)
		return false;

	int root = arr[length - 1];

	//在二叉搜索树中左子树节点的值小于根结点的值
	int i = 0;
	for (i; i < length; i++)
	{
		if (arr[i] > root)
			break;
	}

	//在二叉搜素树中右子树的值大于根结点的值
	int j = i;
	for (j; j < length; j++)
	{
		if (arr[j] < root)
			return false;
	}

	//判断左子树是不是二叉搜索树
	bool left = true;
	if (i > 0)
		left = VerifySequenceOfBST(arr, i);

	//判断右子树是不是二叉搜索树
	bool right = true;
	if (i < length - 1)
		right = VerifySequenceOfBST(arr, length - 1 - i);

	return (left && right);
}


/*
******************************
二叉树中和为某一值的路径
******************************
*/
struct BinaryTreeNode
{
	double m_data;
	BinaryTreeNode* leftchild;
	BinaryTreeNode* rightchild;
};

void findPath(BinaryTreeNode* pRoot, int expectedSum,
	vector<int>& path, int currentSum)
{
	currentSum += pRoot->m_data;
	path.push_back(pRoot->m_data);

	//如果是叶子结点，并且路径上结点值的和等于输入的值，则打印出该路径
	bool isleaf = pRoot->leftchild == nullptr && pRoot->rightchild == nullptr;
	if (currentSum == expectedSum && isleaf)
	{
		cout << "A path is found";
		vector<int>::iterator it = path.begin();
		for (; it != path.end(); ++it)
			cout << *it << endl;
	}

	//如果不是叶子结点，则遍历他的子节点
	if (pRoot->leftchild != nullptr)
		findPath(pRoot->leftchild, expectedSum, path, currentSum);
	if (pRoot->rightchild!= nullptr)
		findPath(pRoot->rightchild, expectedSum, path, currentSum);

	//在返回父节点之前，在路径上删除当前结点
	path.pop_back();
}
void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
	if (pRoot == nullptr)
		return;

	std::vector<int> path;
	int currentSum = 0;
	findPath(pRoot, expectedSum, path, currentSum);
}

/*
******************************
二叉树的深度
******************************
*/
int TreeDepth(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;

	int nleft = TreeDepth(pRoot->leftchild);
	int nright = TreeDepth(pRoot->rightchild);

	return (nleft > nright) ? (nleft + 1) : (nright + 1);
}

/*
******************************
判断是否是平衡二叉树
******************************
*/
bool isBalanced(BinaryTreeNode* pRoot, int* depth)
{
	if (pRoot == nullptr)
	{
		*depth = 0;
		return true;
	}
	
	int left, right;
	if(isBalanced(pRoot->leftchild,&left)
		&& isBalanced(pRoot->rightchild, &right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}
bool IsBalanced(BinaryTreeNode* pRoot)
{
	int depth = 0;
	return isBalanced(pRoot, &depth);
}