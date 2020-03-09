#include<iostream>
#include<vector>
using namespace std;

/*
     题目描述：
	 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
	 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
	 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
	 则重建二叉树并返回。
*/

/*
    题目分析：
	     首先我们可以明确，前序遍历的结果是根左右，在一个序列中第一个元素就是root
	     中序遍历的结构是左根右,根据前序遍历选出的root，就可分出左右子树，所以解题具体如下：
	1、先求出根结点
	2、将根结点带入到中序遍历序列中求出左右子树的中序遍历序列
	3、通过左右子树的中序序列元素集合带入前序遍历序列可以求出左右子树的前序序列
	4、左右子树的前序序列的第一个元素分别是根结点的左右儿子
	5、求出了左右子树的4种序列可以递归上述步骤
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
		//判定递归终止条件
		if(pre.size() == 0 || in.size() == 0){
			return NULL;
		}

		//定义Node节点并其求根节点
		int root = pre[0];
		TreeNode* node = new TreeNode(root);
		vector<int> :: iterator it;

		//1、求左右子树的遍历序列
		vector<int> preLeft,preRight,inLeft,inRight;
			//(1)求根节点在中序遍历序列中的位置
		vector<int>::iterator i;
		for(it = in.begin();it != in.end();it++){
			if(root == *it){
				i = it;
			}
		}
		  //(2)求左右子树的中序遍历子序列
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
		  //(3).求左右子树的前序子序列
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
		
		//根据 遍历序列求出跟的左右节点
		node->left = reConstructBinaryTree(preLeft,inLeft);
		node->right = reConstructBinaryTree(preRight,inRight);

		//返回节点地址
		return node;
	}
};


