#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
�����������ȣ�
����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ��
��������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
*/

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL)
	{}
};

//����һ�������Ż���ĵݹ�
int TreeDepth(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + max(TreeDepth(root->left),TreeDepth(root->right));
}

//������������һ��ݹ�
void TreeDepthHelper(TreeNode* root, int cur, int& max_size)
{
	//��������Ҷ�ӽ�㣬�ݹ��˳�������
	if (root == NULL)
	{
		if (cur > max_size)
		{
			max_size = cur;
		}
		return;
	}

	//���������ݹ����
	TreeDepthHelper(root->left, cur + 1, max_size);
	TreeDepthHelper(root->right, cur + 1, max_size);
}
int TreeDepth(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	//��ʼ��һ�����Ⱥ����ֵ
	int length = 0;
	int max_size = 0;

	//�ݹ���ü������ֵ
	TreeDepthHelper(root, length, max_size);
	return max_size;
}

//�����������ò�������ķ�ʽ
int TreeDepth(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	//��ʼ��һ�����У��û��������
	std::queue<TreeNode*> q1;
	q1.push(root);

	//��ʼ��һ���߶�
	int depth = 0;
	while (!q1.empty())
	{
		//��ʼ��һ��size���㵱ǰ������
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
