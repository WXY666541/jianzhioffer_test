#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
using namespace std;

/*
******************************
判断树的子结构
******************************
*/
struct BinaryTreeNode
{
	double m_data;
	BinaryTreeNode* leftchild;
	BinaryTreeNode* rightchild;
};

bool Equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2) < 0.0000001)
		return true;
	else
		return false;
}

bool DoseTree1HaveTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot1 == nullptr)
		return false;
	if (pRoot2 == nullptr)
		return true;

	if (!Equal(pRoot1->m_data, pRoot2->m_data))
		return false;
	if (DoseTree1HaveTree(pRoot1->leftchild, pRoot2->leftchild) && DoseTree1HaveTree(pRoot1->rightchild, pRoot2->rightchild))
		return true;
}
bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool result = false;

	if (pRoot1 != nullptr && pRoot2 != nullptr)
	{
		if (Equal(pRoot1->m_data, pRoot2->m_data))
			result = DoseTree1HaveTree(pRoot1, pRoot2);

		if (!result)
			result = HasSubtree(pRoot1->leftchild, pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->rightchild, pRoot2);
	}
	return result;
}

/*
******************************
广度优先遍历二叉树
******************************
*/
void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
	if (!pTreeRoot)
		return;

	std::deque<BinaryTreeNode*> dequeTreeNode;

	dequeTreeNode.push_back(pTreeRoot);

	while (dequeTreeNode.size())
	{
		BinaryTreeNode* pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		printf("%d",pNode->m_data);

		if (pNode->leftchild)
			dequeTreeNode.push_back(pNode->leftchild);
		if (pNode->rightchild)
			dequeTreeNode.push_back(pNode->rightchild);
	}
}
/*
******************************
进阶版广度优先遍历二叉树
每一层打印一次
******************************
*/
void Print(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	std::queue<BinaryTreeNode*> nodes;
	nodes.push(pRoot);

	int nextLevel = 0;
	int toBeprint = 1;

	while (!nodes.empty())
	{
		BinaryTreeNode* pNode = nodes.front();
		printf("%d", pNode->m_data);

		if (pNode->leftchild != nullptr)
		{
			nodes.push(pNode->leftchild);
			++nextLevel;
		}
		if (pNode->rightchild != nullptr)
		{
			nodes.push(pNode->rightchild);
			++nextLevel;
		}

		nodes.pop();
		--toBeprint;

		if (toBeprint == 0)
		{
			printf("\n");
			toBeprint = nextLevel;
			nextLevel = 0;
		}
	}
}

/*
******************************
“之”字型打印二叉树
******************************
*/

void Print(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	std::stack<BinaryTreeNode*>levels[2];
	int current = 0;
	int next = 1;

	levels[current].push(pRoot);
	while (!levels[0].empty() || levels[1].empty())
	{
		BinaryTreeNode* pNode = levels[current].top();
		levels[current].pop();

		printf("%d", pNode->m_data);

		if (current == 0)
		{
			if (pNode->leftchild != nullptr)
				levels[next].push(pNode->leftchild);
			if (pNode->rightchild != nullptr)
				levels[next].push(pNode->rightchild);
		}
		else
		{
			if (pNode->rightchild != nullptr)
				levels[next].push(pNode->rightchild);
			if (pNode->leftchild != nullptr)
				levels[next].push(pNode->leftchild);	
		}

		if (levels[current].empty())
		{
			printf("\n");
			current = 1 - current;
			next = 1 - next;
		}
	}
}