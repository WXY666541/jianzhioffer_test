#include<stdio.h>
#include<iostream>
#include<stdlib.h>

#if 0
/*
**********************************
丑数问题
**********************************
*/
//方法一
bool IsUgly(int number)
{
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;
	return(number == 1) ? true : false;
}

int GetUglyNumber(int index)
{
	if (index < 0)
		return 0;

	int number = 0;
	int uglyFound = 0;
	while (uglyFound < index)
	{
		++number;
		if (IsUgly(number))
		{
			++uglyFound;
		}
	}
	return number;
}
//方法二
int MIN(int number1, int number2, int number3)
{
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;
	return min;
}
int GetUglyNumber(int index)
{
	if (index <= 0)
		return 0;

	int* pUglyNumber = new int[index];
	pUglyNumber[0] = 1;
	int nextUglyIndex = 1;

	int* pMultiply2 = pUglyNumber;
	int* pMultiply3 = pUglyNumber;
	int* pMultiply5 = pUglyNumber;

	while (nextUglyIndex < index)
	{
		int min = MIN(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		pUglyNumber[nextUglyIndex] = min;

		while (*pMultiply2 * 2 <= pUglyNumber[nextUglyIndex]);
		++pMultiply2;
		while (*pMultiply3 * 3 <= pUglyNumber[nextUglyIndex]);
		++pMultiply3;
		while (*pMultiply5 * 5 <= pUglyNumber[nextUglyIndex]);
		++pMultiply5;
		++nextUglyIndex;
	}
	int ugly = pUglyNumber[nextUglyIndex - 1];
	delete[] pUglyNumber;
	return ugly;
}
#endif

/*
**********************************
数组中的逆序对
**********************************
*/
int InversePairscore(int* data, int* copy, int start, int end)
{
	if (start = end)
	{
		copy[start] = data[start];
		return 0;
	}
	int length = (end - start) / 2;
	int left = InversePairscore(data, copy, start, start + length);
	int right = InversePairscore(data, copy, start + length, end);

	//i初始化为前半段的最后一个数字的下标
	int i = start + length;
	//jj初始化为后半段的最后一个数字的下标
	int j = end;
	int indexCopy = end;
	int count = 0;
	while (i >= start && j >= start + length + 1)
	{
		if (data[i] > data[j])
		{
			copy[indexCopy--] = data[i--];
			count += j - start- length;
		}
		else
		{
			copy[indexCopy--] = data[j--];
		}
	}
	for (; i >= start; i--)
		copy[indexCopy--] = data[i];
	for (; j >= start + length + 1; j--)
		copy[indexCopy--] = data[j];
	return count + left + right;
}
int InversePairs(int* data, int length)
{
	if (data == nullptr || length < 0)
		return 0;

	int* copy = new int[length];
	for (int i = 0; i < length; i++)
		copy[i] = data[i];

	int count = InversePairscore(data, copy,0,length-1);
	delete[] copy;
	return count;
}
/*
**********************************
二叉搜索树的第K大结点
**********************************
*/
struct BiaryTreeNode
{
	int m_data;
	BiaryTreeNode* leftchild;
	BiaryTreeNode* rightchild;
};
BiaryTreeNode* KthNodeCore(BiaryTreeNode* pRoot, unsigned int k)
{
	BiaryTreeNode* target = nullptr;

	if (pRoot->leftchild != nullptr)
		target = KthNodeCore(pRoot->leftchild, k);
	if (target == nullptr)
	{
		if (k == 1)
			target = pRoot;
		k--;
	}
	if (target == nullptr && target->leftchild != nullptr)
		target = KthNodeCore(pRoot->rightchild, k);
	return target;
}
BiaryTreeNode* KthNode(BiaryTreeNode* pRoot, unsigned int k)
{
	if (pRoot == nullptr || k == 0)
		return nullptr;
	return KthNodeCore(pRoot, k);
}
/*
**********************************
和为s的数字
**********************************
*/
bool FindNumberWithSum(int data[], int length, int sum, int* num1, int* num2)
{
	bool found = false;
	if (length < 1 || num1 == nullptr || num2 == nullptr)
		return found;

	int begin = 0;
	int end = length - 1;
	while (begin < end)
	{
		long long cursum = data[begin] + data[end];
		if (cursum == sum)
		{
			*num1 = data[begin];
			*num2 = data[end];
			found = true;
			break;
		}
		else if (cursum > sum)
			end--;
		else
			begin++;
	}
	return found;
}
