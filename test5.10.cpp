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
�ַ���������
******************************
*/
#if 0
void permutation(char* pstr, char* pBegin)
{
	//��ʾ�Ѿ���������������ַ���
	if (*pBegin == '\0')
	{
		printf("%s\n", pstr);
	}
	else
	{
		for (char* pch = pBegin; *pch != '\0'; pch++)
		{
			//����������ַ�������
			char temp = *pch;
			*pch = *pBegin;
			*pBegin = temp;

			permutation(pstr, pBegin + 1);

			//������п��ܵĵ�һλ��Ԫ��
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
// ====================���Դ���====================
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
���������������
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
		if (nCurSum <= 0)//����ǰ��������ĺ�
			nCurSum = pData[i];
		else
			nCurSum += pData[i];
		if (nCurSum > nGreateSum)//�������������ĺ�
			nGreateSum = nCurSum;
	}
	return nGreateSum;
}

// ====================���Դ���====================
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

// �������ֶ��Ǹ���
// -2, -8, -1, -5, -9
void Test2()
{
	int data[] = { -2, -8, -1, -5, -9 };
	Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// �������ֶ�������
// 2, 8, 1, 5, 9
void Test3()
{
	int data[] = { 2, 8, 1, 5, 9 };
	Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// ��Ч����
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
