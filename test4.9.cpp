#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#if 0
/*
******************************
pow������ʵ��
******************************
*/

bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001)
		&& (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}
double Powerresult(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	//�ݹ�˷��Ĺ���
	double result = Powerresult(base, exponent >> 1);
	result *= result;

	//ָ��Ϊ���������
	if ((exponent & 0x1) == 1)
		result *= base;

	return result;
}
bool g_InvalidInput = false;

double Power(double base, int exponent)
{
	g_InvalidInput = false;

	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)(exponent);
	if(exponent < 0)
		absExponent = (unsigned int)(-exponent);

	double result = Powerresult(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;
	return result;
}		
// ====================���Դ���====================
void Test(double base, int exponent, double expectedResult, bool expectedFlag)
{
	double result = Power(base, exponent);
	if (abs(result - expectedResult) < 0.00000001
		&& g_InvalidInput == expectedFlag)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main()
{
	// ������ָ����Ϊ����
	printf("Test1 begins.\n");
	Test(2, 3, 8, false);

	// ����Ϊ������ָ��Ϊ����
	printf("Test2 begins.\n");
	Test(-2, 3, -8, false);

	// ָ��Ϊ����
	printf("Test3 begins.\n");
	Test(2, -3, 0.125, false);

	// ָ��Ϊ0
	printf("Test4 begins.\n");
	Test(2, 0, 1, false);

	// ������ָ����Ϊ0
	printf("Test5 begins.\n");
	Test(0, 0, 1, false);

	// ����Ϊ0��ָ��Ϊ����
	printf("Test6 begins.\n");
	Test(0, 4, 0, false);

	// ����Ϊ0��ָ��Ϊ����
	printf("Test7 begins.\n");
	Test(0, -4, 0, true);

	return 0;
}
#endif

/*
******************************
atoi������ʵ��
******************************
*/
enum Status{kValid = 0,kInvaild};
int g_nStatus = kValid;
long long StrToIntCore(const char* digit, bool minus);

int StrToInt(const char* str)
{
	g_nStatus = kInvaild;
	long long num = 0;

	if (str != nullptr && *str != '\0')//�մ��ж�
	{
		bool minus = false;//����һ������ֵ���������
		//�����ж�
		if (*str == '+')
			str++;
		else if (*str == '-')
		{
			str++;
			minus = true;
		}

		//�����ַ���ת��
		if (*str != '\0')
		{
			num = StrToIntCore(str, minus);
		}
	}
	return (int)num;
}
long long StrToIntCore(const char* digit, bool minus)
{
	long long num = 0;

	while (*digit != '\0')
	{
		if (*digit >= '0' && *digit <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');//���Ĵ���

			//����ж�
			if ((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			digit++;
		}
		else//�Ƿ�����
		{
			num = 0;
			break;
		}
	}
	//����Ϊ'\0'�ĺϷ����
	if (*digit == '\0')
	{
		g_nStatus = kValid;
	}
	return num;
}
// ====================���Դ���====================
void Test(const char* string)
{
	int result = StrToInt(string);
	if (result == 0 && g_nStatus == kInvaild)
		printf("the input %s is invalid.\n", string);
	else
		printf("number for %s is: %d.\n", string, result);
}

int main()
{
	Test(NULL);

	Test("");

	Test("123");

	Test("+123");

	Test("-123");

	Test("1a33");

	Test("+0");

	Test("-0");

	//��Ч�����������, 0x7FFFFFFF
	Test("+2147483647");

	Test("-2147483647");

	Test("+2147483648");

	//��Ч����С������, 0x80000000
	Test("-2147483648");

	Test("+2147483649");

	Test("-2147483649");

	Test("+");

	Test("-");

	return 0;
}
