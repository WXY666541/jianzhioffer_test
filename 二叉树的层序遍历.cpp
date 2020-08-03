#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>
#include<queue>

/*
�������Ĳ��������
�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ
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
	//��ʼ��һ������Ͷ���
	std::vector<int> result;
	std::queue<TreeNode*> q1;

	//���Ƚ���������
	q1.push(root);

	while (!q1.empty())
	{
		//����������Ľ�����
		TreeNode* Node = q1.front();
		q1.pop();

		//���Ѿ����ӵ�Ԫ�ش�ŵ�������鵱��
		result.push_back(Node->val);

		//����һ������ʱ������Ӧ�������������
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
