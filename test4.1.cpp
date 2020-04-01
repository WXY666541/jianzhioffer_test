#include<iostream>
#include<vector>
using namespace std;

#if 0
/*
****************************************************************************************
���ǹ����⣺
��������һЩ�ǹ� candies����������Ƿָ��źöӵ� n = num_people ��С���ѡ�����һ��С����
1 ���ǹ����ڶ���С���� 2 �ţ��������ƣ�ֱ�������һ��С���� n ���ǹ���Ȼ�������ٻص���
�����㣬����һ��С���� n + 1 ���ǹ����ڶ���С���� n + 2 �ţ��������ƣ�ֱ�������һ��С
���� 2 * n ���ǹ����ظ��������̣�ÿ�ζ�����һ�ζ����һ���ǹ�������������յ���ٴδӶ���
��㿪ʼ����ֱ�����Ƿ������е��ǹ���ע�⣬�����������е�ʣ���ǹ�������������ǰһ�η�������
���ࣩ����Щ�ǹ�Ҳ��ȫ��������ǰ��С���ѡ�����һ������Ϊ num_people��Ԫ��֮��Ϊ candies ��
���飬�Ա�ʾ�ǹ������շַ�������� ans[i] ��ʾ�� i ��С���ѷֵ����ǹ�������

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
��ֵ�����������Ϊ����Ӹ�ֵ���������
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
Ҫ�����ĸ����⣺
1������ֵ��������Ϊ�����͵�����  
2���Ѵ���Ĳ�����������Ϊ��������
3���ͷ�ԭ���ڴ�
4����ֹ�Ը�ֵ
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
//���캯��
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

//�������캯��
CMystring::CMystring(const CMystring& str)
{
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}
//��������غ���
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
//��������
CMystring::~CMystring()
{
	delete[] m_pData;
}
/*===================���Դ���======================*/
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
// ��ֵ���Լ�
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

// ������ֵ
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
��������Ѱ�������е��ظ�����
****************************************************************************************
*/
//���һ��
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
//������������������������޸�����
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
		if (count > (middle - start + 1))//5>4 ������1-4�����ٻ���
			end = middle;
		else
			start = middle;
	}
	return -1;
}
