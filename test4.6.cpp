#include<iostream>
#include<vector>
using namespace std;
#if 0
/*
******************************
��ת�������С����
******************************
*/
int MinInOrder(int* numbers, int p1, int p2)
{
    int result = numbers[p1];
    for (int i = p1 + 1; i <= p2; i++)
    {
        if (result > numbers[i])
            result = numbers[i];
    }
    return result;
}
int Min(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		throw new::std::exception("Invalid parameters");

	int p1 = 0;
	int p2 = length - 1;
	int indexmid = p1;
	while (numbers[p1] >= numbers[p2])
	{
		//���һ
		if (p2 - p1 == 1)
		{
			indexmid = p2;
			break;
		}
		indexmid = (p1 + p2) / 2;

		//�����
		if (numbers[p1] == numbers[p2] == numbers[indexmid])
		{
			return MinInOrder(numbers, p1, p2);
		}
		//��С��Χ
		if (numbers[indexmid] >= numbers[p1])
			p1 = indexmid;
		else if(numbers[indexmid] <= numbers[p2])
			p2 = indexmid;
	}
	return numbers[indexmid];
}

void Test(int* numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = Min(numbers, length);

        for (int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if (result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if (numbers == NULL)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}

int main()
{
    // �������룬��������������һ����ת
    int array1[] = { 3, 4, 5, 1, 2 };
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // ���ظ����֣������ظ������ָպõ���С������
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // ���ظ����֣����ظ������ֲ��ǵ�һ�����ֺ����һ������
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // ���ظ������֣������ظ������ָպ��ǵ�һ�����ֺ����һ������
    int array4[] = { 1, 0, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // �����������飬��ת0��Ԫ�أ�Ҳ���ǵ����������鱾��
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // ������ֻ��һ������
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // ����NULL
    Test(NULL, 0, 0);

    return 0;
}

/*
******************************
���������������г��ֵĴ���
******************************
*/
int GetFirstK(int* data, int length, int k, int start, int end)
{
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    int middleData = data[mid];

    if (middleData == k)
    {
        if ((mid > 0 && data[mid - 1] != k) || mid == 0)
            return mid;
        else
            end = mid - 1;
    }
    else if (middleData > k)
    {
        end = mid - 1;
    }
    else
    start = mid + 1;
    return GetFirstK(data, length, k, start, end);
}

int GetLastK(int* data, int length, int k, int start, int end)
{
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    int middleData = data[mid];
    if (middleData == k)
    {
        if ((mid < length-1 && data[mid + 1] != k) || mid == length-1)
            return mid;
        else
            start = mid + 1;
    }
    else if (middleData < k)
    {
        start = mid + 1;
    }
    else
      end = mid - 1;
    return GetLastK(data, length, k, start, end);
}
int GetNumberOfK(int* data, int length, int k)
{
    int count = 0;
    if (data != nullptr && length > 0)
    {
        int first = GetFirstK(data, length, k, 0, length - 1);
        int last = GetLastK(data, length, k, 0, length - 1);

        if (first > -1 && last > -1)
            count = last - first + 1;
    }
    return count;
}
// ====================���Դ���====================
void Test(const char* testName, int data[], int length, int k, int expected)
{
    if (testName != NULL)
        printf("%s begins: ", testName);

    int result = GetNumberOfK(data, length, k);
    if (result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// ���ҵ����ֳ�����������м�
void Test1()
{
    int data[] = { 1, 2, 3, 3, 3, 3, 4, 5 };
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ��������������Ŀ�ͷ
void Test2()
{
    int data[] = { 3, 3, 3, 3, 4, 5 };
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ��������������Ľ�β
void Test3()
{
    int data[] = { 1, 2, 3, 3, 3, 3 };
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ����ֲ�����
void Test4()
{
    int data[] = { 1, 3, 3, 3, 3, 4, 5 };
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// ���ҵ����ֱȵ�һ�����ֻ�С��������
void Test5()
{
    int data[] = { 1, 3, 3, 3, 3, 4, 5 };
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// ���ҵ����ֱ����һ�����ֻ��󣬲�����
void Test6()
{
    int data[] = { 1, 3, 3, 3, 3, 4, 5 };
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// �����е����ִ�ͷ��β���ǲ��ҵ�����
void Test7()
{
    int data[] = { 3, 3, 3, 3 };
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// �����е����ִ�ͷ��βֻ��һ���ظ������֣����ǲ��ҵ�����
void Test8()
{
    int data[] = { 3, 3, 3, 3 };
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// ������ֻ��һ�����֣��ǲ��ҵ�����
void Test9()
{
    int data[] = { 3 };
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// ������ֻ��һ�����֣����ǲ��ҵ�����
void Test10()
{
    int data[] = { 3 };
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// ³���Բ��ԣ������ָ��
void Test11()
{
    Test("Test11", NULL, 0, 0, 0);
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
    Test10();
    Test11();

    return 0;
}

/*
******************************
0~n-1��ȱʧ������
******************************
*/
int GetMissingNumbers(const int* numbers, int length)
{
    if (numbers == nullptr || length <= 0)
        return -1;

    int left = 0;
    int right = length - 1;
    
    while (left <= right)
    {
        int mid = (left + length) / 2;
        if (numbers[mid] != mid)
        {
            if (numbers[mid - 1] == mid - 1 || mid == 0)
                return mid;
            else
                right = mid - 1;
        }
        else
            left = mid + 1;
    }
    //ȱʧ�������һ������
    if (left == length)
        return length;

    return -1;
}
#endif
/*
******************************
��������ֵ���±���ȵ�Ԫ��
******************************
*/
int GetNumberSameAsIndex( int* numbers, int length)
{
    if (numbers == nullptr || length <= 0)
        return -1;

    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        int mid = (right - left ) / 2 + left;
        if (numbers[mid] = mid)
            return mid;
        if (numbers[mid] < mid)
            left = mid + 1;
        else
            right = mid + 1;
    }
    return -1;
}