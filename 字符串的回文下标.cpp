#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
�ַ����Ļ��ģ�
����һ������Сд��ĸ��ɵ��ַ������������ҳ�һ��λ�ã�
ɾ���Ǹ���ĸ֮���ַ�����ɻ��ġ�������ܻ���һ���Ϸ��Ľ⡣
����������ַ����Ѿ���һ�����Ĵ�����ô���-1��
*/
bool IsPalindrome(std::string s, int* start, int* end)
{
	//��ʼ��i��j��ֵ�ֱ�������ǰ���ı���
	int i = 0;
	int j = s.size()-1;

	bool result = true;
	while (i <= j)
	{
		//��ʾ���ǻ������У�����false
		if (s[i] != s[j])
		{
			result = false;
			break;
		}
		i++;
		j--;
	}

	//�ж��Ƿ��±��ֵ����ȥ
	if (start != nullptr) *start = i;
	if (end != nullptr) *end = j;
	return result;
}
int main()
{
	int num;
	std::cin >> num;

	//ѭ������num���ַ����������ж�
	while (num)
	{
		std::string s;
		std::cin >> s;

		//��ʼ���ַ�������ʼĩβλ��
		int start = 0;
		int end = s.size() - 1;

		//����ǻ�������ֱ�ӷ���-1
		if (IsPalindrome(s, &start, &end))
		{
			std::cout << -1 << std::endl;
		}
		else
		{
			//ɾ��end��ָ����ַ�
			s.erase(end,1);

			//�����ж��Ƿ��ǻ�������
			if (IsPalindrome(s, nullptr,nullptr))
			{
				//������ǻ������оͷ���end�±��ֵ
				std::cout << end << std::endl;
			}
			else
			{
				//������Ǿͷ��������start�±�
				std::cout << start << std::endl;
			}
		}
		num--;
	}
}
