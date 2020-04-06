#include<iostream>
#include<vector>
using namespace std;
#if 0
/*
******************************
旋转数组的最小数字
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
		//情况一
		if (p2 - p1 == 1)
		{
			indexmid = p2;
			break;
		}
		indexmid = (p1 + p2) / 2;

		//情况二
		if (numbers[p1] == numbers[p2] == numbers[indexmid])
		{
			return MinInOrder(numbers, p1, p2);
		}
		//缩小范围
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
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // 输入NULL
    Test(NULL, 0, 0);

    return 0;
}

/*
******************************
数字在排序数组中出现的次数
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
// ====================测试代码====================
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

// 查找的数字出现在数组的中间
void Test1()
{
    int data[] = { 1, 2, 3, 3, 3, 3, 4, 5 };
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的开头
void Test2()
{
    int data[] = { 3, 3, 3, 3, 4, 5 };
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3()
{
    int data[] = { 1, 2, 3, 3, 3, 3 };
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数字不存在
void Test4()
{
    int data[] = { 1, 3, 3, 3, 3, 4, 5 };
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5()
{
    int data[] = { 1, 3, 3, 3, 3, 4, 5 };
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6()
{
    int data[] = { 1, 3, 3, 3, 3, 4, 5 };
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7()
{
    int data[] = { 3, 3, 3, 3 };
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8()
{
    int data[] = { 3, 3, 3, 3 };
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9()
{
    int data[] = { 3 };
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10()
{
    int data[] = { 3 };
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// 鲁棒性测试，数组空指针
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
0~n-1中缺失的数字
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
    //缺失的是最后一个数字
    if (left == length)
        return length;

    return -1;
}
#endif
/*
******************************
数组中数值和下标相等的元素
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