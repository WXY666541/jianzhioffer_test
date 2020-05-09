#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
using namespace std;


/*
******************************
二叉树的镜像
******************************
*/
struct BinaryTreeNode
{
	double m_data;
	BinaryTreeNode* leftchild;
	BinaryTreeNode* rightchild;
};
void MirrorRecursively(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
		return;
	if (pNode->leftchild == nullptr && pNode->rightchild == nullptr)
		return;

	BinaryTreeNode* ptmp = pNode->leftchild;
	pNode->leftchild = pNode->rightchild;
	pNode->rightchild = ptmp;

	if (pNode->leftchild)
		MirrorRecursively(pNode->leftchild);
	if (pNode->rightchild)
		MirrorRecursively(pNode->rightchild);
}

/*
******************************
对称的二叉树
******************************
*/
bool isSymnetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;
	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;

	if (pRoot1->m_data != pRoot2->m_data)
		return false;

	return isSymnetrical(pRoot1->leftchild, pRoot2->rightchild)
		&& isSymnetrical(pRoot1->rightchild, pRoot2->leftchild);
}

bool IsSymnetrical(BinaryTreeNode* pRoot)
{
	return isSymnetrical(pRoot, pRoot);
}

/*
******************************
二叉搜索树与双向链表
******************************
*/

BinaryTreeNode* ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
	//特殊情况
	if (pNode == nullptr)
		return;
	//定义一个当前结点用于不断的遍历
	BinaryTreeNode* pCurrent = pNode;

	//递归链接右子树
	if (pCurrent->leftchild != nullptr)
		ConvertNode(pCurrent->leftchild, pLastNodeInList);

	//已经转换好的链表最后一个结点即为最大的值链接到当前结点的左子树
	pCurrent->leftchild = *pLastNodeInList;
	if (pLastNodeInList != nullptr)
		(*pLastNodeInList)->rightchild = pCurrent;

	//更新链表
	*pLastNodeInList = pCurrent;

	//递归链接右子树
	if (pCurrent->rightchild != nullptr)
		ConvertNode(pCurrent->rightchild, pLastNodeInList);
}

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
	BinaryTreeNode* pLastNodeInList = nullptr;//pLastNodeInList指向双向链表的尾结点
	ConvertNode(pRootOfTree, &pLastNodeInList);

	//我们需要返回一个头结点
	BinaryTreeNode* pHeadofList = pLastNodeInList;
	//首先让链表走到树的最左边结点
	while (pHeadofList != nullptr && pHeadofList->leftchild != nullptr)
		pHeadofList = pHeadofList->leftchild;

	return pHeadofList;
}

/*
******************************
序列化二叉树
******************************
*/
void Serialize(BinaryTreeNode* pRoot, ostream& stream)
{
	if (pRoot == nullptr)
	{
		stream << "$,";
		return;
	}

	stream << pRoot->m_data << ",";
	Serialize(pRoot->leftchild, stream);
	Serialize(pRoot->rightchild, stream);
}

/*
******************************
反序列化二叉树
******************************
*/


void Deserialize(BinaryTreeNode** pRoot, istream& stream)
{
	int number;
	if (ReadStream(stream, &number))
	{
		*pRoot = new BinaryTreeNode();
		(*pRoot)->m_data = number;
		(*pRoot)->leftchild = nullptr;
		(*pRoot)->rightchild = nullptr;

		Deserialize(&((*pRoot)->leftchild), stream);
		Deserialize(&((*pRoot)->rightchild), stream);
	}
}