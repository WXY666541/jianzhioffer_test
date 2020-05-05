#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
using namespace std;

/*
******************************
�����������ĺ����������
******************************
*/
bool VerifySequenceOfBST(int arr[], int length)
{
	if (arr == nullptr || length <= 0)
		return false;

	int root = arr[length - 1];

	//�ڶ������������������ڵ��ֵС�ڸ�����ֵ
	int i = 0;
	for (i; i < length; i++)
	{
		if (arr[i] > root)
			break;
	}

	//�ڶ�������������������ֵ���ڸ�����ֵ
	int j = i;
	for (j; j < length; j++)
	{
		if (arr[j] < root)
			return false;
	}

	//�ж��������ǲ��Ƕ���������
	bool left = true;
	if (i > 0)
		left = VerifySequenceOfBST(arr, i);

	//�ж��������ǲ��Ƕ���������
	bool right = true;
	if (i < length - 1)
		right = VerifySequenceOfBST(arr, length - 1 - i);

	return (left && right);
}


/*
******************************
�������к�Ϊĳһֵ��·��
******************************
*/
struct BinaryTreeNode
{
	double m_data;
	BinaryTreeNode* leftchild;
	BinaryTreeNode* rightchild;
};

void findPath(BinaryTreeNode* pRoot, int expectedSum,
	vector<int>& path, int currentSum)
{
	currentSum += pRoot->m_data;
	path.push_back(pRoot->m_data);

	//�����Ҷ�ӽ�㣬����·���Ͻ��ֵ�ĺ͵��������ֵ�����ӡ����·��
	bool isleaf = pRoot->leftchild == nullptr && pRoot->rightchild == nullptr;
	if (currentSum == expectedSum && isleaf)
	{
		cout << "A path is found";
		vector<int>::iterator it = path.begin();
		for (; it != path.end(); ++it)
			cout << *it << endl;
	}

	//�������Ҷ�ӽ�㣬����������ӽڵ�
	if (pRoot->leftchild != nullptr)
		findPath(pRoot->leftchild, expectedSum, path, currentSum);
	if (pRoot->rightchild!= nullptr)
		findPath(pRoot->rightchild, expectedSum, path, currentSum);

	//�ڷ��ظ��ڵ�֮ǰ����·����ɾ����ǰ���
	path.pop_back();
}
void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
	if (pRoot == nullptr)
		return;

	std::vector<int> path;
	int currentSum = 0;
	findPath(pRoot, expectedSum, path, currentSum);
}

/*
******************************
�����������
******************************
*/
int TreeDepth(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;

	int nleft = TreeDepth(pRoot->leftchild);
	int nright = TreeDepth(pRoot->rightchild);

	return (nleft > nright) ? (nleft + 1) : (nright + 1);
}

/*
******************************
�ж��Ƿ���ƽ�������
******************************
*/
bool isBalanced(BinaryTreeNode* pRoot, int* depth)
{
	if (pRoot == nullptr)
	{
		*depth = 0;
		return true;
	}
	
	int left, right;
	if(isBalanced(pRoot->leftchild,&left)
		&& isBalanced(pRoot->rightchild, &right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}
bool IsBalanced(BinaryTreeNode* pRoot)
{
	int depth = 0;
	return isBalanced(pRoot, &depth);
}