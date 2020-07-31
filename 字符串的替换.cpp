#include<iostream>
#include<vector>
#include<string>
#include<stack> 
/*
字符串替换问题

请实现一个函数，将一个字符串中的每个空格替换成“ % 20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为
We % 20Are % 20Happy。
*/
void replaceSpace(char* src, int length) {
	if (src == NULL)
	{
		return;
	}
	char* str = src;
	//统计空格数量
	int count = 0;
	while (*str != '\0')
	{
		if (*str == ' ')
		{
			count++;
		}
		str++;
	}

	//定义旧字符串长度的末尾和新字符串长度的末尾
	char* oldstr = src + length;
	char* newstr = src + length + 2 * count;

	//替换过程
	while (oldstr < newstr)
	{
		//遇到空格的情况
		if (*oldstr == ' ')
		{
			*newstr-- = '0';
			*newstr-- = '2';
			*newstr-- = '%';
			oldstr--;
		}
		else//没有遇到空格的情况
		{
			//直接将原字符赋值移动即可
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
