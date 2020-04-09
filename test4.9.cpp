#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#if 0
/*
******************************
pow函数的实现
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

	//递归乘法的过程
	double result = Powerresult(base, exponent >> 1);
	result *= result;

	//指数为奇数的情况
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
// ====================测试代码====================
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
	// 底数、指数都为正数
	printf("Test1 begins.\n");
	Test(2, 3, 8, false);

	// 底数为负数、指数为正数
	printf("Test2 begins.\n");
	Test(-2, 3, -8, false);

	// 指数为负数
	printf("Test3 begins.\n");
	Test(2, -3, 0.125, false);

	// 指数为0
	printf("Test4 begins.\n");
	Test(2, 0, 1, false);

	// 底数、指数都为0
	printf("Test5 begins.\n");
	Test(0, 0, 1, false);

	// 底数为0、指数为正数
	printf("Test6 begins.\n");
	Test(0, 4, 0, false);

	// 底数为0、指数为负数
	printf("Test7 begins.\n");
	Test(0, -4, 0, true);

	return 0;
}
#endif

/*
******************************
atoi函数的实现
******************************
*/
enum Status{kValid = 0,kInvaild};
int g_nStatus = kValid;
long long StrToIntCore(const char* digit, bool minus);

int StrToInt(const char* str)
{
	g_nStatus = kInvaild;
	long long num = 0;

	if (str != nullptr && *str != '\0')//空串判断
	{
		bool minus = false;//设置一个布尔值来保存符号
		//符号判断
		if (*str == '+')
			str++;
		else if (*str == '-')
		{
			str++;
			minus = true;
		}

		//其余字符串转换
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
			num = num * 10 + flag * (*digit - '0');//核心代码

			//溢出判断
			if ((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			digit++;
		}
		else//非法输入
		{
			num = 0;
			break;
		}
	}
	//输入为'\0'的合法情况
	if (*digit == '\0')
	{
		g_nStatus = kValid;
	}
	return num;
}
// ====================测试代码====================
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

	//有效的最大正整数, 0x7FFFFFFF
	Test("+2147483647");

	Test("-2147483647");

	Test("+2147483648");

	//有效的最小负整数, 0x80000000
	Test("-2147483648");

	Test("+2147483649");

	Test("-2147483649");

	Test("+");

	Test("-");

	return 0;
}
