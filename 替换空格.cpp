/*
***************************
�滻�ո�
***************************
*/

//��ԭ����Ļ����Ͽ���
string Replaceblank(string s)
{
	if (s.empty())
		return NULL;

	int count = 0;
	int length = s.size();
	for (int i = 0; i < length; i++)
	{
		if (s[i] == ' ')
			count++;
	}
	int newlength = length + 2 * count;

	while (newlength >= 0 && newlength > length)
	{
		if (s[length] == ' ')
		{
			s[newlength] = '0';
			s[newlength--] = '2';
			s[newlength--] = '%';
		}
		else
		{
			s[newlength] = s[length];
			newlength--;
		}
		length--;
	}
	return s;
}

//���¿���һ���ռ�
string Replaceblank(string s)
{
	string res = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			res += "%20";
			continue;
		}

		else
			res += s[i];
	}
	return res;
}
int main()
{
	string s = "he world ";
	cout << Replaceblank(s);
	return 0;
}

