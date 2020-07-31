#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
��Ŀ����Ǯ�һ�
ͨ���ʣ�%60
����ֵ1,5,10,50,100���ֱ��Ӧ������a��b��c��d��e
����kԪǮ�����ٶ�����ֽ�������㣬�����������-1
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
��Ŀ���ַ�������ȡ����    85 %
���磺 + 1a2
�����12

���磺 - 1a2
����� - 12
*/

int strToInt(std::string str)
{
	if (str.size() == 0)
		return 0;

	int res = 0;//����ÿһ�εĽ��
	int temp = 0;//����ÿ���ַ�ת��������

	//ȥ����ͷ�Ŀո�
	int index = 0;
	while (str[index] == ' ')
		index++;
	bool flag = false;//��ʶ������trueΪ����
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
��Ŀ�������ص�
ͨ���ʣ�80%
�������꣺��0, 0������2, 3������1, 2������5, 4��
�ж�ǰ������Խ��߹��ɵľ����Ƿ���������㹹�ɵľ����ཻ
�ཻ�����1���������0

ֱ�������1   ����65 %
ֱ��ģ���жϳ�Ϊ0�������
�ڶ�������������ĺ�����ͬʱ���ڵ�һ�����εڶ�����ĺ�����Ϊ���ཻ
�ڶ�������������ĺ�����ͬʱС�ڵ�һ�����ε�һ����ĺ�����Ϊ���ཻ
�ڶ��������������������ͬʱ���ڵ�һ�����εڶ������������Ϊ���ཻ
�ڶ��������������������ͬʱС�ڵ�һ�����ε�һ�����������Ϊ���ཻ
�������1����
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
�����⣺���ţ�ÿһ�˵Ľ������� 85%
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



