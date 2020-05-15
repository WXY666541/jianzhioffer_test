#include<stdio.h>
#include<iostream>
#include<stdlib.h>

/*
**********************************
和为s的连续正数序列
**********************************
*/
void print(int samll, int big)
{
	for (int i = samll; i <= big; i++)
	{
		printf("%d", i);
	}
	printf("\n");
}
void FindContinuousSequence(int sum)
{
	if (sum < 3)
		return;

	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int cursum = small + big;

	while (small < middle)
	{
		if (sum == cursum)
			print(small,big);

		while (cursum > sum && small < middle)
		{
			cursum -= small;
			small++;

			if (cursum == sum)
				print(small, big);
		}
		big++;
		cursum += big;
	}
}
/*
**********************************
翻转字符串
**********************************
*/
void Reverse(char* pBegin, char* pEnd)
{
	if (pBegin == nullptr || pEnd == nullptr)
		return;

	while (pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++;
		pEnd--;
	}
}

char* ReverseSentence(char* pData)
{
	if (pData == nullptr)
		return nullptr;

	char* pBegin = pData;
	char* pEnd = pData;

	while (pEnd != '\0')
		pEnd++;
	pEnd--;

	//翻转整个句子
	Reverse(pBegin, pEnd);

	//翻转句子里面的每个单词
	pBegin = pEnd = pData;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')//表示一个单词翻转结束
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')//整个翻转过程
		{
			Reverse(pBegin, --pEnd);
			pBegin == ++pEnd;//翻转完整后更新pBegin指向
		}
		else
		{
			pEnd++;//让pEnd走向每个单词的末尾
		}
	}
	return pData;
}

/*
**********************************
左旋转字符串
**********************************
*/
char* LeftRotateString(char* pStr, int n)
{
	if (pStr != nullptr)
	{
		int nlength = static_cast<int>(strlen(pStr));
		if (nlength < 0 && n> 0 && n < nlength)
		{
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondStart = pStr + n;
			char* pSecondEnd = pStr + nlength - 1;

			//翻转字符串的前面n个字符
			Reverse(pFirstStart, pFirstEnd);
			//翻转字符串后面部分
			Reverse(pSecondStart, pSecondEnd);
			//翻转整个字符串
			Reverse(pFirstStart, pFirstEnd);
		}
	}
	return pStr;
}