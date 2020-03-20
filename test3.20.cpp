#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
/**************************************************************
��Ŀ���⣺��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬
���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2��
��������������0��
***************************************************************/

//����һ��
/*
���������������������������ڣ���һ���������м��Ǹ���
�����磺1��2��2��2��3����2��2��2��3��4����2��3��4��4��4�ȵȣ�
���ԣ����ÿ���ʹ����������ʱ�临�Ӷ���O(NlogN)����������
*/
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	if (numbers.empty()) return 0;
	sort(numbers.begin(), numbers.end());
	int middle = numbers[numbers.size() / 2];

	int count = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] = middle) ++count;
	}
	return (count > numbers.size() / 2) ? middle : 0;
}

//��������
/*
������ع��ص�˼��
��һ��������Ϊ��һ��ʿ��������أ�count = 1;
������ͬԪ�أ�count++
������ͬ��Ԫ�أ���Ϊ���ˣ�ͬ���ھ���count--.������countΪ0�����ʱ
�����µ�iֵ��Ϊ�����ʿ����������ȥ���������������ϵı����п�������Ԫ��
�ټ�һ��ѭ������¼���ʿ���ĸ������Ƿ��������һ�뼴��
*/
int MoreThanHalfNum_Solution1(vector<int> numbers)
{
	if (numbers.empty()) return 0;
	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < numbers.size(); ++i)
	{
		if (times == 0)
		{
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result)
		{
			++times;
		}
		else//��ͬ
		{
			--times;
		}
	}
	times = 0;
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (numbers[i] == result) ++times;
	}
	return (times > numbers.size()/2) ? result : 0;
}

/**************************************************************
��Ŀ���⣺����n���������ҳ�������С��K������
��������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
���������ÿ����еĻ�ȡ�ָ���ᣩ��ĺ���partion
��������ĵ�k��������������ʹ�ñȵ�k������С���������ֶ�λ��
�������ߣ�����������ֶ�λ��������ұߡ�����֮��λ��������ߵ�
k�����־�����С��kλ��
***************************************************************/
void swap(int& fir, int& sec)
{
	int temp = fir;
	fir = sec;
	sec = temp;
}
int getPartution(vector<int>& input, int start,int end)
{
	if (input.empty() || start > end) return -1;
	int temp = input[end];
	int j = start - 1;
	for (int i = start; i < end; i++)
	{
		if (input[i] <= temp)
		{
			++j;
			if (i != j)swap(input[i], input[j]);
		}
	}
	swap(input[j + 1], input[end]);
	return (j + 1);
}
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	vector<int> result;
	if (input.empty() || k > input.size() || k <= 0) return result;

	int start = 0;
	int end = input.size() - 1;
	int index = getPartution(input, start, end);

	while (index != (k - 1))
	{
		if (index > (k - 1))
		{
			end = index - 1;
			index = getPartution(input, start, end);
		}
		else
		{
			start = index + 1;
			index = getPartution(input, start, end);
		}
	}
	for (int i = 0; i < k; i++)
	{
		result.push_back(input[i]);
	}
	return result;
}

