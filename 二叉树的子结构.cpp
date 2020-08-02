#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>

/*
���������ӽṹ
�������ö�����A��B���ж�B�ǲ���A���ӽṹ��
��ps������Լ��������������һ�������ӽṹ��
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

//���Ѿ�ȷ������ʼλ�õ������ȥ�Ƚ����������Ƿ����
bool IsSame(TreeNode* begin, TreeNode* begin_sub)
{
	//�ݹ����
	if (begin_sub == NULL)
	{
		return true;
	}
	if (begin == NULL)//��ζ��begin_sub != NULL
	{
		return false;
	}
	if (begin->val != begin_sub->val)
	{
		return false;
	}
	//�ߵ�����ͱ�ʾ��ǰ�������ȵ�
	return (IsSame(begin->left,begin_sub->left) && IsSame(begin->right,begin_sub->right));

}
bool HasSubtree(TreeNode* root1, TreeNode* root2)
{
	//����������ж�
	if (root1 == NULL || root2 == NULL )
	{
		return false;
	}
	bool result = false;
	//�ҵ�����ʼλ��
	if (root1->val == root2->val)
	{
		//�ж������������Ƿ����
		result = IsSame(root1, root2);
	}
	//��������ĳ���Ҫô��û���ҵ���ʼλ�ã�Ҫô�����������������
	//�ͼ����ݹ���root1���������ṹ��ȥѰ���ӽṹ
	if (result != true)
	{
		result = HasSubtree(root1->left, root2);
	}
	//��������û���ҵ����ͼ����ݹ���root1���������ṹ��ȥѰ���ӽṹ
	if (result != true)
	{
		result = HasSubtree(root1->right, root2);
	}
	return result;
}
