#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
������ƴ�������С����:
����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ
����������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
*/
class Solution
{
	static bool cmp(int x, int y)
	{
		std::string sx = std::to_string(x);
		std::string sy = std::to_string(y);

		std::string A = sx + sy;
		std::string B = sy + sx;

		return A < B;
	}
public:
	std::string PrintMinNumber(std::vector<int> arr)
	{
		std::string result = "";
		if (arr.size() == 0)
		{
			return result;
		}

		//ʹ��sort�������������������������������
		sort(arr.begin(), arr.end(), cmp);

		//�������������е�Ԫ�أ�ʹ��to_string�ķ�ʽת���ַ�������ƴ�ӵ�����ַ�����
		for ( unsigned int i = 0; i < arr.size(); i++)
		{
			result += std::to_string(arr[i]);
		}
		return result;
	}

};

