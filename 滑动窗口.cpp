#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
/*
�������ڣ�
С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100������
�����������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��û���,���͵õ���
һ������������Ϊ100������:18,19,20,21,22�����ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��
������������?
*/
std::vector<std::vector<int>> FindContinuousSequence(int sum)
{
	std::vector<std::vector<int>> result;

	//��ʼ�����е������߽�ֵ
	int low = 1;
	int high = 2;

	//ѭ������
	while (low < high)
	{
		int total = (low + high) * (high - low + 1) / 2;
		if (total == sum)
		{
			std::vector<int> list;
			for (int i = low; i <= high; i++)
			{
				list.push_back(i);
			}
			result.push_back(list);
			low++;
		}
		else if (total < sum)
		{
			high++;
		}
		else
		{
			low++;
		}
	}
	return result;
}
