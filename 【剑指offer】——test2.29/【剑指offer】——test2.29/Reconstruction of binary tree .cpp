#include<iostream>
#include<vector>
using namespace std;

/*
     ��Ŀ������
	 ����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
	 ���������ǰ���������������Ľ���ж������ظ������֡�
	 ��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}��
	 ���ؽ������������ء�
*/

/*
    ��Ŀ������
	     �������ǿ�����ȷ��ǰ������Ľ���Ǹ����ң���һ�������е�һ��Ԫ�ؾ���root
	     ��������Ľṹ�������,����ǰ�����ѡ����root���Ϳɷֳ��������������Խ���������£�
	1������������
	2�����������뵽�������������������������������������
	3��ͨ��������������������Ԫ�ؼ��ϴ���ǰ��������п����������������ǰ������
	4������������ǰ�����еĵ�һ��Ԫ�طֱ��Ǹ��������Ҷ���
	5�����������������4�����п��Եݹ���������
*/


 //Definition for binary tree
 struct TreeNode {
    int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
		//�ж��ݹ���ֹ����
		if(pre.size() == 0 || in.size() == 0){
			return NULL;
		}

		//����Node�ڵ㲢������ڵ�
		int root = pre[0];
		TreeNode* node = new TreeNode(root);
		vector<int> :: iterator it;

		//1�������������ı�������
		vector<int> preLeft,preRight,inLeft,inRight;
			//(1)����ڵ���������������е�λ��
		vector<int>::iterator i;
		for(it = in.begin();it != in.end();it++){
			if(root == *it){
				i = it;
			}
		}
		  //(2)�������������������������
		int k = 0;
		for(it = in.begin(); it != in.end();it++){
			if(k == 0){
				inLeft.push_back(*it);
			}
			else if(k == 1){
				inRight.push_back(*it);
			}
			else{}
			if(it == i){
				k = 1;
			}
		}
		  //(3).������������ǰ��������
		k = 0;
		vector<int>::iterator ite;
		for(it = pre.begin()+1; it != pre.end(); it++){
			for(ite = inLeft.begin(); ite != inLeft.end(); ite++){
				if(*it == *ite){
					preLeft.push_back(*it);
					k = 1;
				}
			}
			if(k == 0){
				preRight.push_back(*it);
			}
			k = 0;
		}
		
		//���� ������������������ҽڵ�
		node->left = reConstructBinaryTree(preLeft,inLeft);
		node->right = reConstructBinaryTree(preRight,inRight);

		//���ؽڵ��ַ
		return node;
	}
};


