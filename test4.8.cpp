#include<iostream>
#include<vector>
using namespace std;
#if 0
/*
******************************
������ֻ����һ�ε���������
******************************
*/

unsigned int FindFirstBitIs1(int num);
bool IsBit1(int num, unsigned int indexBit);

void FindNumsAppearOnce(int data[], int length, int* num1, int* num2)
{
	if (data == nullptr || length < 2)
		return;

	int resultExclusiveOR = 0;//��������������������Ľ��
	for (int i = 0; i < length; i++)
	{
		resultExclusiveOR ^= data[i];
	}

	unsigned int indexof1 = FindFirstBitIs1(resultExclusiveOR);
	//�ҵ���������ƽ����1��λ��

	*num1 = *num2 = 0;
	for (int j = 0; j < length; j++)
	{
		//�����и�λ��Ϊ1������num1�����н��������������ʣ�µ�ֵ��Ϊ��������ֵ
		if (IsBit1(data[j], indexof1))
			* num1 ^= data[j];
		else
			*num2 ^= data[j];
	}
}

// �ҵ�num���ұ������һ����1��λ
unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while( ((num & 1) == 0) && (indexBit < 8*sizeof(int)))
	{
		num = num >> 1;
		indexBit++;
	}
	return indexBit;
}

// �ж�����num�ĵ�indexBitλ�ǲ���1
bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

// ====================���Դ���====================
void Test(const char* testName, int data[], int length, int expected1, int expected2)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	int result1, result2;
	FindNumsAppearOnce(data, length, &result1, &result2);

	if ((expected1 == result1 && expected2 == result2) ||
		(expected2 == result1 && expected1 == result2))
		printf("Passed.\n\n");
	else
		printf("Failed.\n\n");
}

void Test1()
{
	int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	Test("Test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test2()
{
	int data[] = { 4, 6 };
	Test("Test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test3()
{
	int data[] = { 4, 6, 1, 1, 1, 1 };
	Test("Test3", data, sizeof(data) / sizeof(int), 4, 6);
}

int main()
{
	Test1();
	Test2();
	Test3();

	return 0;
}


/*
******************************
������Ψһֻ����һ�ε�����
******************************
*/
int FindNumberAppearingOnce(int numbers[], int length)
{
	if (numbers == nullptr || length <= 0)
		throw new std::exception("Invalid input.");

	int bitSum[32] = { 0 };
	//���ѭ����Ҫ���ڱ��������е�ÿһ������
	for (int i = 0; i < length; i++)
	{
		//ͨ���ƶ�bitMask�������е�ÿһλ������������жϸ�λ�Ƿ�Ϊ1
		int bitMask = 1;

		//�ڲ�ѭ����Ҫ���ڱ����������е�ÿһλ
		for (int j = 32; j >= 0; j--)
		{
			int bit = numbers[i] & bitMask;
			if (bit & 1 != 0)
				bitSum[j] += 1;
		}
		bitMask << 1;
	}

	//�������ֻ����һ�����ֵ�ÿһλ
	int result = 0;
	for (int i = 0; i < 32; i++)
	{
		result = result << 1;//�ƶ�ÿһλ
		result += bitSum[i] % 3;//ÿһλ�ͱ�3�����Ľ����Ϊֻ����һ�����ֵĸ�λ
	}
	return result;
}
#endif
/*
******************************
���üӼ��˳����ӷ�
******************************
*/
int Add(int num1, int num2)
{
	int sum, carry;
	do
	{
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;
		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return num1;
}
// ====================���Դ���====================
void Test(int num1, int num2, int expected)
{
	int result = Add(num1, num2);
	if (result == expected)
		printf("%d + %d is %d. Passed\n", num1, num2, result);
	else
		printf("%d + %d is %d. Failed\n", num1, num2, result);
}

int main()
{
	Test(1, 2, 3);
	Test(111, 899, 1010);

	Test(-1, 2, 1);
	Test(1, -2, -1);

	Test(3, 0, 3);
	Test(0, -4, -4);

	Test(-2, -8, -10);
}