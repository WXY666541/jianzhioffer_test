#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>
#include<queue>

/*
判断一个数组序列是不是某二叉树的后序遍历结果
输入一个非空整数数组，判断该数组是不是某二叉搜索树
的后序遍历的结果。如果是则输出Yes,否则输出No。
假设输入的数组的任意两个数字都互不相同。
*/

//解析：根据BST树的最后一个元素是根结点，左半部分的值小于该值
//右半部分的值大于该值的特点，来进行递归的验证当前序列和其对应的子序列

bool VerifySquenceOfBSTcore(std::vector<int> arr, int start, int end)
{
	//递归条件的出口
	if (start >= end)
	{
		return true;
	}

	//根据后续遍历的特性，提取出来根结点的值
	int root = arr[end];
	int i = 0;

	//挨个遍历找到左右子树的临界点，验证前半部分序列值
	while (arr[i] < root && i < end)
	{
		i++;
	}
	//验证后半部分序列值
	for (int j = i; j < end; j++)
	{
		if (arr[j] < root)
		{
			return false;
		}
	}

	//如果上面两个条件都满足，走到这一步说明当前序列值正确，剔除根结点再递归验证其左右子树
	return VerifySquenceOfBSTcore(arr, 0, i - 1) && VerifySquenceOfBSTcore(arr, i, end-1);
}
bool VerifySquenceOfBST(std::vector<int> arr)
{
	if (arr.empty())
	{
		return false;
	}
	return VerifySquenceOfBSTcore( arr, 0, arr.size()-1);
}
