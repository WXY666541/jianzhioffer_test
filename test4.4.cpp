#include<iostream>
#include<vector>
using namespace std;
#if 0
/*
******************************
��ά�����еĲ���
******************************
*/
bool Find(int* arr, int rows, int columns, int numbers)
{
	bool found = false;

	if (arr != nullptr && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && column > 0)
		{
			if (numbers = arr[rows * column + row])
			{
				found = true;
				break;
			}
			else if (numbers < arr[rows * column + row])
				column--;
			else
				row++;
		}
	}
	return found;
}
// ====================���Դ���====================
void Test(const char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
    if (testName != NULL)
        printf("%s begins: ", testName);

    bool result = Find(matrix, rows, columns, number);
    if (result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�����������
void Test1()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������
void Test2()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С������
void Test3()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������������
void Test4()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С�����ֻ�С
void Test5()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ������������������ֻ���
void Test6()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// ³���Բ��ԣ������ָ��
void Test7()
{
    Test("Test7", NULL, 0, 0, 16, false);
}


int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
	return 0;
}
#endif

/*
******************************
�滻�ո�
******************************
*/
void RepalceBlank(char string[], int length)
{
    if (string == nullptr || length <= 0)
        return;
    int originalLength = 0;
    int originalBlank = 0;
    int i = 0;
    while (string[i] != '\0')
    {
        originalLength++;
        if (string[i] == ' ')
            originalBlank++;
        i++;
    }

    int newlength = originalLength + originalBlank * 2;
    if (newlength > length)//ע�⣺originalLength��Ϊʵ�ʵ��ַ������ȣ�lengthΪ������ַ�������,����Ҫ�Ŀռ䶼�����˿϶����˳���
        return;

    int p2 = newlength;
    int p1 = originalLength;//ע�⣺originalLength��Ϊʵ�ʵ��ַ������ȣ�lengthΪ������ַ�������

    //����p2���ƶ�һ��������p1�����ƶ�һ��
    while (p2 > p1&& p1 >= 0)
    {
        if (string[p1] == ' ')
        {
            string[p2--] = '0';
            string[p2--] = '2';
            string[p2--] = '%';
        }
        else
        {
            string[p2--] = string[p1];
        }
        p1--;
    }
}
void Test(const char* testName, char string[], int length, const char expected[])
{
    if (testName != NULL)
        printf("%s begins: ", testName);

    RepalceBlank(string, length);

    if (expected == NULL && string == NULL)
        printf("passed.\n");
    else if (expected == NULL && string != NULL)
        printf("failed.\n");
    else if (strcmp(string, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// �ո��ھ����м�
void Test1()
{
    const int length = 100;

    char string[length] = "hello world";
    Test("Test1", string, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
    const int length = 100;

    char string[length] = " helloworld";
    Test("Test2", string, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
    const int length = 100;

    char string[length] = "helloworld ";
    Test("Test3", string, length, "helloworld%20");
}

// �����������ո�
void Test4()
{
    const int length = 100;

    char string[length] = "hello  world";
    Test("Test4", string, length, "hello%20%20world");
}

// ����NULL
void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
    const int length = 100;

    char string[length] = "";
    Test("Test6", string, length, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
    const int length = 100;

    char string[length] = " ";
    Test("Test7", string, length, "%20");
}

// ������ַ���û�пո�
void Test8()
{
    const int length = 100;

    char string[length] = "helloworld";
    Test("Test8", string, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
void Test9()
{
    const int length = 100;

    char string[length] = "   ";
    Test("Test9", string, length, "%20%20%20");
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}
