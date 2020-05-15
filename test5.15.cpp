#include<stdio.h>
#include<iostream>
#include<stdlib.h>

/*
**********************************
��Ϊs��������������
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
��ת�ַ���
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

	//��ת��������
	Reverse(pBegin, pEnd);

	//��ת���������ÿ������
	pBegin = pEnd = pData;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')//��ʾһ�����ʷ�ת����
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')//������ת����
		{
			Reverse(pBegin, --pEnd);
			pBegin == ++pEnd;//��ת���������pBeginָ��
		}
		else
		{
			pEnd++;//��pEnd����ÿ�����ʵ�ĩβ
		}
	}
	return pData;
}

/*
**********************************
����ת�ַ���
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

			//��ת�ַ�����ǰ��n���ַ�
			Reverse(pFirstStart, pFirstEnd);
			//��ת�ַ������沿��
			Reverse(pSecondStart, pSecondEnd);
			//��ת�����ַ���
			Reverse(pFirstStart, pFirstEnd);
		}
	}
	return pStr;
}