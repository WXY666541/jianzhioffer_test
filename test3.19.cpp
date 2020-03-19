#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
/*
*********************************************************
题目大意：从上往下打印出二叉树的每个节点，同层节点从左至
          右打印也叫层序遍历和广度优先搜索BFS
分析：利用队列，头结点入队，再出队，出队时依次左子树右子树入队

*********************************************************
*/
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
vector<int> PrintFromTopToBottom(TreeNode* root) 
{
	vector<int> res;
	if (root == NULL)return res;
	queue<struct TreeNode*> qu;
	qu.push(root);
	while (!qu.empty())
	{
		root =qu.front(); qu.pop();
		res.push_back(root->val);
		cout << root->val << endl;
		if (root->left != NULL)
		{
			qu.push(root->left);
		}
		if (root->right != NULL)
		{
			qu.push(root->right);
		}
	}
	return res;
}
/*
*********************************************************
题目大意：输入一个整数数组，判断该数组是不是某二叉搜索树
          的后序遍历的结果。如果是则输出Yes,否则输出No。
          假设输入的数组的任意两个数字都互不相同。
分析：二叉搜索树又叫BST树，它的后序遍历结果的特征为最后一个
      值为根结点x，去掉最后一个元素的序列T满足，T前面一半的
	  序列小于x，后面一般的序列大于x
思路：1、确定root
      2、遍历序列（除去root结点），找到第一个大于root的位置
	  即为右子树的开始
	  3、遍历右子树，若发现小于root的值，则直接返回false
	  4、分别判断左子树和右子树是否仍是BST树（即递归步骤1,、2、3）

*********************************************************
*/
//递归实现
bool ju(vector<int> a, int start, int end)
{
	if (start >= end)
		return true;
	int i = start;
	while (a[i] < a[end])
	{
		i++;
	}
	for (int j = i; j < end; j++)
	{
		if (a[j] < a[end])
		{
			return false;
		}
	}
	return ju(a, start, i - 1) && ju(a, i, end - 1);
}
bool VerifySquenceOfBST(vector<int> sequence) 
{
	if (sequence.size() == 0)
		return false;
	if (sequence.size() == 1)
		return true;
	return ju(sequence, 0, sequence.size() - 1);

}
