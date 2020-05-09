#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
using namespace std;


/*
******************************
�������ľ���
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
�ԳƵĶ�����
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
������������˫������
******************************
*/

BinaryTreeNode* ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
	//�������
	if (pNode == nullptr)
		return;
	//����һ����ǰ������ڲ��ϵı���
	BinaryTreeNode* pCurrent = pNode;

	//�ݹ�����������
	if (pCurrent->leftchild != nullptr)
		ConvertNode(pCurrent->leftchild, pLastNodeInList);

	//�Ѿ�ת���õ��������һ����㼴Ϊ����ֵ���ӵ���ǰ����������
	pCurrent->leftchild = *pLastNodeInList;
	if (pLastNodeInList != nullptr)
		(*pLastNodeInList)->rightchild = pCurrent;

	//��������
	*pLastNodeInList = pCurrent;

	//�ݹ�����������
	if (pCurrent->rightchild != nullptr)
		ConvertNode(pCurrent->rightchild, pLastNodeInList);
}

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
	BinaryTreeNode* pLastNodeInList = nullptr;//pLastNodeInListָ��˫�������β���
	ConvertNode(pRootOfTree, &pLastNodeInList);

	//������Ҫ����һ��ͷ���
	BinaryTreeNode* pHeadofList = pLastNodeInList;
	//�����������ߵ���������߽��
	while (pHeadofList != nullptr && pHeadofList->leftchild != nullptr)
		pHeadofList = pHeadofList->leftchild;

	return pHeadofList;
}

/*
******************************
���л�������
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
�����л�������
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