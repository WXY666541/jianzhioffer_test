#include<iostream>
#include<vector>
#include<string>
#include<stack> 
/*
�ַ����滻����

��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ� % 20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���Ϊ
We % 20Are % 20Happy��
*/
void replaceSpace(char* src, int length) {
	if (src == NULL)
	{
		return;
	}
	char* str = src;
	//ͳ�ƿո�����
	int count = 0;
	while (*str != '\0')
	{
		if (*str == ' ')
		{
			count++;
		}
		str++;
	}

	//������ַ������ȵ�ĩβ�����ַ������ȵ�ĩβ
	char* oldstr = src + length;
	char* newstr = src + length + 2 * count;

	//�滻����
	while (oldstr < newstr)
	{
		//�����ո�����
		if (*oldstr == ' ')
		{
			*newstr-- = '0';
			*newstr-- = '2';
			*newstr-- = '%';
			oldstr--;
		}
		else//û�������ո�����
		{
			//ֱ�ӽ�ԭ�ַ���ֵ�ƶ�����
			*newstr = *oldstr;
			oldstr--;
			newstr--;
		}
	}
}
void show(std::string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		std::cout << str[i];
	}
	std::cout << std::endl;
}
int main()
{
	char str[30] = { "we are happy!" };
	replaceSpace(str, strlen(str));
	show(str);
}
