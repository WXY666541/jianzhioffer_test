#include<iostream>
#include<vector>
using namespace std;

#if 0
/*
****************************************************************************************
分糖果问题：
我们买了一些糖果 candies，打算把它们分给排好队的 n = num_people 个小朋友。给第一个小朋友
1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。然后，我们再回到队
伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗，依此类推，直到给最后一个小
朋友 2 * n 颗糖果。重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍
起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖
果多），这些糖果也会全部发给当前的小朋友。返回一个长度为 num_people、元素之和为 candies 的
数组，以表示糖果的最终分发情况（即 ans[i] 表示第 i 个小朋友分到的糖果数）。

****************************************************************************************
*/
vector<int> distributeCandies(int candies, int num_people)
{
	vector<int> a(num_people, 0);
	int i = 0;
	while (candies > 0)
	{
		a[i % num_people] += (i + 1 < candies ? i + 1 : candies);
		candies -= (i + 1 < candies ? i + 1 : candies);
		i++;
	}
	return a;
}

/*
****************************************************************************************
赋值运算符函数：为其添加赋值运算符函数
class CMystring
{
public:
	CMystring(char* pData = nullptr);
	CMystring(const CMystring& str);
	~CMystring();
private:
	char* m_pData;
};
****************************************************************************************
*/
/*
要考虑四个问题：
1、返回值类型申明为该类型的引用  
2、把传入的参数类型申明为常量引用
3、释放原有内存
4、防止自赋值
*/
class CMystring
{
public:
	CMystring(const char* pData = nullptr);
	CMystring(const CMystring& str);
	~CMystring();
	CMystring& operator = (const CMystring& str);
	void print();
private:
	char* m_pData;
};
//构造函数
CMystring::CMystring(const char* pData)
{
	if (pData == nullptr)
	{
		pData = new char[1];
		//pData[0] = '\0';
	}
	else
	{
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

//拷贝构造函数
CMystring::CMystring(const CMystring& str)
{
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}
//运算符重载函数
CMystring& CMystring::operator = (const CMystring& str)
{
	if (this == &str)
		return *this;

	delete[] m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}
//析构函数
CMystring::~CMystring()
{
	delete[] m_pData;
}
/*===================测试代码======================*/
void CMystring::print()
{
	printf("%s", m_pData);
}
void Test1()
{
	printf("Test1 begins:\n");

	const char* text = "Hello world";

	CMystring str1(text);
	CMystring str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.print();
	printf(".\n");
}
// 赋值给自己
void Test2()
{
	printf("Test2 begins:\n");

	const char* text = "Hello world";

	CMystring str1(text);
	str1 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str1.print();
	printf(".\n");
}

// 连续赋值
void Test3()
{
	printf("Test3 begins:\n");

	const char* text = "Hello world";

	CMystring str1(text);
	CMystring str2, str3;
	str3 = str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.print();
	printf(".\n");

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str3.print();
	printf(".\n");
}

int main()
{
	Test1();
	return 0;
}
#endif

/*
****************************************************************************************
问题三：寻找数组中的重复数字
****************************************************************************************
*/
//情况一：
bool duplicate(int number[], int length, int* duplicate)
{
	if (number == nullptr || length <= 0)
	{
		return false;
	}
	for (int i = 0; i < length; i++)
	{
		if (number[i]<0 || number[i]>length - 1)
		{
			return false;
		}
	}
	for (int i = 0; i < length; i++)
	{
		while (i != number[i])
		{
			if (number[i] == number[number[i]])
			{
				*duplicate = number[i];
				return true;
			}
			int tmp = number[i];
			number[i] = number[tmp];
			number[tmp] = tmp;
		}
	}
	return false;
}
//情况二：有限制条件——不修改数组
int getcount(int* number, int length, int start, int end)
{
	if (number == nullptr)
		return 0;
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (number[i] >= start && number[i] <= end)
		{
			count++;
		}
	}
	return count;
}
int getduplicate(int* number, int length)
{
	if (number == nullptr || length <= 0)
		return -1;
	int end = length - 1;//7
	int start = 1;//1
	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;//4
		int count = getcount(number, length, start, middle);
		if (end == start)
		{
			if (count > 1)
				return start;
			break;
		}
		if (count > (middle - start + 1))//5>4 所以在1-4里面再划分
			end = middle;
		else
			start = middle;
	}
	return -1;
}
