#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
using namespace std;

struct BinaryTreeNode
{
	double m_data;
	BinaryTreeNode* leftchild;
	BinaryTreeNode* rightchild;
};

/*
******************************
字符串的排列
******************************
*/
#if 0
void permutation(char* pstr, char* pBegin)
{
	//表示已经遍历完毕了整个字符串
	if (*pBegin == '\0')
	{
		printf("%s\n", pstr);
	}
	else
	{
		for (char* pch = pBegin; *pch != '\0'; pch++)
		{
			//求后面所有字符的排列
			char temp = *pch;
			*pch = *pBegin;
			*pBegin = temp;

			permutation(pstr, pBegin + 1);

			//求出所有可能的第一位置元素
			temp = *pch;
			*pch = *pBegin;
			*pBegin = temp;
		}
	}
}
void Permutation(char* pstr)
{
	if (pstr == nullptr)
		return;
	permutation(pstr, pstr);
}
// ====================测试代码====================
void Test(char* pStr)
{
	if (pStr == NULL)
		printf("Test for NULL begins:\n");
	else
		printf("Test for %s begins:\n", pStr);

	Permutation(pStr);

	printf("\n");
}

int main()
{
	Test(NULL);

	char string1[] = "";
	Test(string1);

	char string2[] = "a";
	Test(string2);

	char string3[] = "ab";
	Test(string3);

	char string4[] = "abc";
	Test(string4);

	return 0;
}
#endif

/*
******************************
连续子数组的最大和
******************************
*/

bool g_InvalidInput = false;

int FindGreatSumofSubArray(int* pData, int nlength)
{
	if ((pData == nullptr) || (nlength < 0))
	{
		g_InvalidInput = true;
		return 0;
	}
	g_InvalidInput = false;

	int nCurSum = 0;
	int nGreateSum = 0x80000000;
	for (int i = 0; i < nlength; i++)
	{
		if (nCurSum <= 0)//抛弃前面子数组的和
			nCurSum = pData[i];
		else
			nCurSum += pData[i];
		if (nCurSum > nGreateSum)//更新最大子数组的和
			nGreateSum = nCurSum;
	}
	return nGreateSum;
}

// ====================测试代码====================
void Test(const char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
	if (testName != NULL)
		printf("%s begins: \n", testName);

	int result = FindGreatSumofSubArray(pData, nLength);
	if (result == expected && expectedFlag == g_InvalidInput)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
	int data[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
	int data[] = { -2, -8, -1, -5, -9 };
	Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
	int data[] = { 2, 8, 1, 5, 9 };
	Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
void Test4()
{
	Test("Test4", NULL, 0, 0, true);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}
