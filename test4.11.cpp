#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#if 0
/*
******************************
��ʾ��ֵ���ַ���
******************************
*/
bool scanUisgnedInterger(const char** str)
{
	//����ָ�봫�����ָ��ĵ�ַ
	const char* before = *str;//��before����strָ�����ʼλ��
	while (**str >= '0' && **str <= '9' && **str != '\0')
		++(*str);
	if (*str > before)//��ʾ��ָ���ƶ�����˼����str�д�������0~9������
		return true;
}

bool scanInteger(const char** str)
{
	if (**str == '+' || **str == '-')
		++(*str);
	return scanUisgnedInterger(str);
}

bool isNumberic(const char* str)
{
	if (str == nullptr)
		return false;

	bool numeric = scanInteger(&str);//��֤A

	if (*str == '.')
	{
		++str;
		numeric = scanUisgnedInterger(&str) || numeric;
	}
	if (*str == 'e' || *str == 'E')
	{
		++str;
		numeric = scanInteger(&str) && numeric;
	}

	//���������ַ������λ�ã����numericΪ���ʾA,B,C��ƥ��ɹ�
	if ((numeric && *str) == '\0')
		return true;
}
#endif
/*
******************************
��������˳��ʹ����λ��ż��ǰ��
******************************
*/
/*
��ʽһ��
void ReorderOddEvent(int* pData, unsigned int length)
{
	if (pData == nullptr || length <= 0)
		return;

	int* p1 = pData;
	int* p2 = pData + length - 1;

	while (p1 < p2)
	{
		//����ƶ�p1,ֱ����ָ��ż��
		while (p1 < p2 && (*p1 & 0x1) != 0)
			p1++;
		
		//��ǰ�ƶ�p2,ֱ����ָ������
		while (p1 < p2 && (*p2 & 0x1) == 0)
			p2--;

		if (p1 < p2)
		{
			int temp = *p1;
			*p1 = *p2;
			*p2 = temp;
		}
	}
}
*/
//��ʽ��
void Reorder(int* pData, unsigned int length,bool (*func)(int))
{
	if (pData == nullptr || length <= 0)
		return;

	int* p1 = pData;
	int* p2 = pData + length - 1;

	while (p1 < p2)
	{
		//����ƶ�p1,ֱ����ָ��ż��
		while (p1 < p2 && !func(*p1))
			p1++;

		//��ǰ�ƶ�p2,ֱ����ָ������
		while (p1 < p2 && func(*p2))
			p2--;

		if (p1 < p2)
		{
			int temp = *p1;
			*p1 = *p2;
			*p2 = temp;
		}
	}
}
bool isEven(int n)
{
	return (n & 0x01) == 0;
}
void ReorderOddEven(int* pData, unsigned int length)
{
	Reorder(pData, length, isEven);
}
// ====================���Դ���====================
void PrintArray(int numbers[], int length)
{
	if (length < 0)
		return;

	for (int i = 0; i < length; ++i)
		printf("%d\t", numbers[i]);

	printf("\n");
}

void Test(const char* testName, int numbers[], int length)
{
	if (testName != NULL)
		printf("%s begins:\n", testName);

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
	{
		copy[i] = numbers[i];
	}

	printf("Test for solution 1:\n");
	PrintArray(numbers, length);
	ReorderOddEven(numbers, length);
	PrintArray(numbers, length);

	printf("Test for solution 2:\n");
	PrintArray(copy, length);
	ReorderOddEven(copy, length);
	PrintArray(copy, length);

	delete[] copy;
}

void Test1()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7 };
	Test("Test1", numbers, sizeof(numbers) / sizeof(int));
}

void Test2()
{
	int numbers[] = { 2, 4, 6, 1, 3, 5, 7 };
	Test("Test2", numbers, sizeof(numbers) / sizeof(int));
}

void Test3()
{
	int numbers[] = { 1, 3, 5, 7, 2, 4, 6 };
	Test("Test3", numbers, sizeof(numbers) / sizeof(int));
}

void Test4()
{
	int numbers[] = { 1 };
	Test("Test4", numbers, sizeof(numbers) / sizeof(int));
}

void Test5()
{
	int numbers[] = { 2 };
	Test("Test5", numbers, sizeof(numbers) / sizeof(int));
}

void Test6()
{
	Test("Test6", NULL, 0);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}
