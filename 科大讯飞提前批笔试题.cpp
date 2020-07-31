#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
题目：零钱兑换
通过率：%60
有面值1,5,10,50,100，分别对应变量：a、b、c、d、e
若有k元钱，最少多少张纸币能找零，若不能则输出-1
*/
bool fun(std::vector<int>& vec1, std::vector<int>& vec2)
{
	return !(vec2[2] <= vec1[0] ||
		vec2[0] >= vec1[2] ||
		vec2[3] <= vec1[1] ||
		vec2[1] >= vec1[3]);
}
int main()
{
	std::vector<int> rec1;
	std::vector<int> rec2;
	for (int i = 0; i < 4; i++)
	{
		int tmp = 0;
		std::cin >> tmp;
		rec1.push_back(tmp);
	}
	for (int i = 0; i < 4; i++)
	{
		int tmp = 0;
		std::cin >> tmp;
		rec2.push_back(tmp);
	}
	std::cout << fun(rec1, rec2) << std::endl;
}

/*
题目：字符串中提取整数    85 %
例如： + 1a2
输出：12

例如： - 1a2
输出： - 12
*/

int strToInt(std::string str)
{
	if (str.size() == 0)
		return 0;

	int res = 0;//保存每一次的结果
	int temp = 0;//保存每个字符转换成整数

	//去除开头的空格
	int index = 0;
	while (str[index] == ' ')
		index++;
	bool flag = false;//标识负数，true为负数
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
		{
			flag = true;
		}
		index++;
	}
	for (; index < str.size();index++)
	{
		if (isdigit(str[index]))
		{
			temp = str[index] - '0';
			if (res > INT_MAX / 10 || (res == INT_MAX / 10))
			{
				if (flag)
					return INT_MIN;
				else
					return INT_MAX;
			}
			res = res * 10 + temp;
		}
		else
		{
			continue;
		}
	}
	if (flag)
		res = 0 - res;
	return res;
}
int main()
{
	std::cout << strToInt("+1a2") << std::endl;
	std::cout << strToInt("42") << std::endl;
	std::cout << strToInt("    42") << std::endl;
	std::cout << strToInt("2618 while ") << std::endl;
	std::cout << strToInt("dwidh 42") << std::endl;
	std::cout << strToInt("21473648") << std::endl;
	std::cout << strToInt("-91283472332") << std::endl;
}

/*
题目：矩形重叠
通过率：80%
给定坐标：（0, 0），（2, 3），（1, 2），（5, 4）
判断前两个点对角线构成的矩形是否与后两个点构成的矩形相交
相交则输出1，否则输出0

直接输出：1   过了65 %
直接模拟判断出为0的情况：
第二个矩形两个点的横坐标同时大于第一个矩形第二个点的横坐标为不相交
第二个矩形两个点的横坐标同时小于第一个矩形第一个点的横坐标为不相交
第二个矩形两个点的纵坐标同时大于第一个矩形第二个点的纵坐标为不相交
第二个矩形两个点的纵坐标同时小于第一个矩形第一个点的纵坐标为不相交
否则输出1即可
*/

int Min(std::vector<int>& change, std::vector<int>& num, int total)
{
	int count = 0;
	for (int i = num.size() - 1; i >= 0; i--)
	{
		int temp = total / change[i];
		while (temp > 0)
		{
			if (num[i] > 0)
			{
				total -= change[i];
				count++;
				temp = total / change[i];
				num[i] -= 1;
			}
		}
	}
	if (total == 0)
		return count;
	else
		return -1;
}
int main()
{
	std::vector<int> change;
	change.push_back(1);
	change.push_back(5);
	change.push_back(10);
	change.push_back(50);
	change.push_back(100);

	std::vector<int> arr;
	for (int i = 0; i < 5; i++)
	{
		int tmp = 0;
		std::cin >> tmp;
		arr.push_back(tmp);
	}
	int total = 0;
	std::cin >> total;

	Min(change, arr, total);
	return 0;
}

/*
第四题：快排，每一趟的结果都输出 85%
*/
void show(std::vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
int Partition(std::vector<int>& arr, int low, int high)
{
	int i = low;
	int j = high;
	int flag = arr[low];
	while (i < j)
	{
		while ((arr[j] > flag) && (i < j))
			j--;
		while ((arr[i] <= flag) && (i < j))
			i++;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	arr[low] = arr[i];
	arr[i] = flag;
	return i;
}
void Qsort(std::vector<int>& arr, int low, int high)
{
	int pivot;
	if (low <= high)
	{
		pivot = Partition(arr, low, high);
		Qsort(arr, low, pivot - 1);
		Qsort(arr, pivot+1, high);
	}
	show(arr);
}


void QuickSort(std::vector<int> arr, int n)
{
	Qsort(arr, 0,n - 1);
}

int main()
{
	int num = 0;
	cin >> num;
	std::vector<int> arr;
	for (int i = 0; i < num; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	QuickSort(arr,arr.size());
}



