#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
using namespace std;


#if 0
/*
******************************
1~n整数中1出现的次数
******************************
*/
//方法1
int Numberof1(unsigned int n)
{
	int number = 0;
	while (n)
	{
		if (n % 10 == 1)
			number++;

		n = n / 10;
	}
	return number;
}
int NumberOf1Between1AndN1(unsigned int n)
{
	int number = 0;

	for (unsigned int i = 1; i <= n; i++)
		number += Numberof1(i);
	return number;
}
//方法二
int  PowerBase10(unsigned int n)
{
	int result = 1;
	for (unsigned int i = 0; i < n; i++)
		result *= 10;
	return result;
}
int NumberOf1(const char* strN)
{
	if (!strN || *strN < '0' || *strN >'9' || *strN == '\0')
		return 0;

	int first = *strN - '0';
	unsigned int nlength = static_cast<unsigned int>(strlen(strN));

	if (nlength == 1 && first == 0)
		return 0;
	if (nlength == 1 && first > 0)
		return 1;

	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = PowerBase10(nlength - 1);
	else if (first == 1)
		numFirstDigit = atoi(strN + 1) + 1;
	int numOtherDigits = first * (nlength - 1) * PowerBase10(nlength - 2);
	int numRecursive = NumberOf1(strN + 1);
	return numFirstDigit + numOtherDigits + numRecursive;

}
int NumberOf1Between1AndN2(unsigned int n)
{
	if (n <= 0)
		return 0;

	char strN[50];
	sprintf(strN, "%d", n);
	return NumberOf1(strN);
}
// ====================测试代码====================
void Test(const char* testName, int n, int expected)
{
	if (testName != NULL)
		printf("%s begins: \n", testName);

	if (NumberOf1Between1AndN1(n) == expected)
		printf("Solution1 passed.\n");
	else
		printf("Solution1 failed.\n");

	if (NumberOf1Between1AndN2(n) == expected)
		printf("Solution2 passed.\n");
	else
		printf("Solution2 failed.\n");

	printf("\n");
}

void Test()
{
	Test("Test1", 1, 1);
	Test("Test2", 5, 1);
	Test("Test3", 10, 2);
	Test("Test4", 55, 16);
	Test("Test5", 99, 20);
	Test("Test6", 10000, 4001);
	Test("Test7", 21345, 18821);
	Test("Test8", 0, 0);
}

int main()
{
	Test();

	return 0;
}
#endif

/*
******************************
数字序列中某一位的数字
******************************
*/
int countOfIntegers(int digits)
{
	if (digits = 1)
		return 10;
	int count = (int)std::pow(10, digits - 1);
	return 9 * count;
}
int beginNumber(int digits)
{
	if (digits == 1)
		return 0;
	return(int)std::pow(10, digits - 1);
}
int digitAtIndex(int index, int dights)
{
	int number = beginNumber(dights) + index / dights;
	int indexFromRight = dights - index % dights;
	for (int i = 0; i < indexFromRight; ++i)
		number /= 10;
	return number % 10;
}

int digitAtdex(int index)
{
	if (index < 0)
		return -1;
	int digits = 1;
	while (true)
	{
		int numbers = countOfIntegers(digits);
		if (index < numbers * digits)
			return digitAtIndex(index, digits);

		index -= digits * numbers;
		digits++;
	}
	return -1;
}
/*
******************************
把数组排成最小的数
******************************
*/

const int g_MaxNumberLength = 10;

char* g_strCount1 = new char[g_MaxNumberLength * 2] + 1;
char* g_strCount2 = new char[g_MaxNumberLength * 2] + 1;

int  compare(const void* strNumber1, const void* strNumber2)
{
	strcpy(g_strCount1, *(const char**)strNumber1);
	strcat(g_strCount1, *(const char**)strNumber2);

	strcpy(g_strCount2, *(const char**)strNumber2);
	strcat(g_strCount2, *(const char**)strNumber1);

	return strcmp(g_strCount1, g_strCount2);
}
void printMinnumber(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return;

	char** strNumbers = (char**)(new int[length]);
	for (int i = 0; i < length; i++)
	{
		strNumbers[i] = new char[g_MaxNumberLength + 1];
		sprintf(strNumbers[i], "%d", numbers[i]);
	}

	qsort(strNumbers, length, sizeof(char*), compare);
	for (int i = 0; i < length; i++)
		printf("%s", strNumbers[i]);
	printf("\n");

	for (int i = 0; i < length; i++)
		delete[] strNumbers[i];
	delete[] strNumbers;
}