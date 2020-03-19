#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
/*
*********************************************************
��Ŀ���⣺�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ������
          �Ҵ�ӡҲ�в�������͹����������BFS
���������ö��У�ͷ�����ӣ��ٳ��ӣ�����ʱ�������������������

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
��Ŀ���⣺����һ���������飬�жϸ������ǲ���ĳ����������
          �ĺ�������Ľ��������������Yes,�������No��
          �������������������������ֶ�������ͬ��
�����������������ֽ�BST�������ĺ���������������Ϊ���һ��
      ֵΪ�����x��ȥ�����һ��Ԫ�ص�����T���㣬Tǰ��һ���
	  ����С��x������һ������д���x
˼·��1��ȷ��root
      2���������У���ȥroot��㣩���ҵ���һ������root��λ��
	  ��Ϊ�������Ŀ�ʼ
	  3��������������������С��root��ֵ����ֱ�ӷ���false
	  4���ֱ��ж����������������Ƿ�����BST�������ݹ鲽��1,��2��3��

*********************************************************
*/
//�ݹ�ʵ��
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
