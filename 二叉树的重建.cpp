#include<iostream>
#include<vector>
#include<string>
#include<stack> 
/*
���������ؽ�
����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ�
���ж������ظ������֡���������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}������
�������������ء�

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
	//�ݹ���ֹ������
	if (pre_start > pre_end || vin_start > vin_end)
	{
		return NULL;
	}

	//����һ�������
	TreeNode* root = new TreeNode(pre[pre_start]);

	//����������������Ҹ������±�
	for (int i = vin_start; i <= vin_end; i++)
	{
		//ֻ������������������Һ�ǰ�����Ԫ����ȵ�Ԫ��
		if (pre[pre_start] == vin[i])//ע�⣡����ǧ��Ҫ��root->val��ֵȥ�Ƚ�
		{
			//��סԪ�ظ����ļ���Ϊpre_start+1+i-vin_start-1
			root->left = ConstructBinaryTree(pre, pre_start + 1, pre_start + i - vin_start, vin, vin_start, i - 1);
			root->right = ConstructBinaryTree(pre, pre_start + i - vin_start + 1, pre_end, vin, i + 1, vin_end);
			break;
		}
	}
	return root;
}
TreeNode* reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin)
{
	//����������ж�
	if (pre.empty() || vin.empty() || pre.size() != vin.size())
	{
		return NULL;
	}
	//�ؽ����Ĺ���
	ConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size());
}
