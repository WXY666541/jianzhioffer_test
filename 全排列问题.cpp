#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>
#include<queue>

/*
ȫ�������⣺
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c
�������г����������ַ��� abc,acb,bac,bca,cab �� cba ��
*/
//��������Ŀ�괮���������֣���һ���������ĸ��ַ���ͷ
//�ڶ����־��ǣ�ʣ�µ�������

//��������
void swap(std::string& str, int i, int j)
{
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

//ȥ�غ���
bool IsExist(std::vector<std::string>& result, std::string& str)
{
	auto it = result.begin();
	for (; it != result.end(); ++it)
	{
		if (*it == str)
		{
			return true;
		}
	}
	return false;
}

//������ȱ�������
void Permutation(std::string& str, int start, std::vector<std::string>& result)
{
	if (start == str.length() - 1)
	{
		if (!IsExist(result, str))
		{
			result.push_back(str);
		}
		return;
	}

	for (int i = start; i < str.length(); i++)
	{
		swap(str, start, i);
		Permutation(str, start + 1, result);
		swap(str, start, i);
	}
}


std::vector<std::string> Permutation(std::string str)
{
	std::vector<std::string> result;
	if (str.length() > 0)
	{
		Permutation(str, 0, result);//�ݹ���ã�������ȱ���ʽ����
		sort(result.begin(), result.end());
	}
	return result;
}

