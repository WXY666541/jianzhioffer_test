#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>

/*
**********************************
�˿����е�˳��
**********************************
*/
int compare(const void* arg1, const void* arg2)
{
	return *(int*)arg1 - *(int*)arg2;
}
bool IsConyinuous(int* numbers, int length)
{
	if (numbers == nullptr || length < 1)
		return false;

	qsort(numbers, length, sizeof(int), compare);

	int numberofzero = 0;
	int numberofgap = 0;

	//ͳ��������0�ĸ���
	for (int i = 0; i < length && numbers[i] == 0; i++)
		numberofzero++;

	//ͳ�������м����Ŀ
	int small = numberofzero;
	int big = small + 1;

	while (big < length)
	{
		//����������ȣ��ж��ӣ���������˳��
		if (numbers[small] == numbers[big])
			return false;

		numberofgap += numbers[big] - numbers[small] - 1;
		small = big;
		++big;
	}
	return (numberofgap > numberofzero) ? false : true;
}

/*
**********************************
��Ʊ���������
**********************************
*/
int MaxDiff(const int* numbers, unsigned length)
{
	if (numbers == nullptr || length < 2)
		return 0;

	int min = numbers[0];
	int maxDiff = numbers[1] - min;

	for (int i = 2; i < length; i++)
	{
		if (numbers[i - 1] < min)
			min = numbers[i - 1];

		int currentDiff = numbers[i] - min;
		if (currentDiff > maxDiff)
			maxDiff = currentDiff;
	}
	return maxDiff;
}