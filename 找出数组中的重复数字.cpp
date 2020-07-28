/*
***************************
�ҳ������е��ظ�����
***************************
*/


//����һ��������
int FindNmber(vector<int>& arr)
{
	int i = 0;
	for (i; i < arr.size(); i++)
	{
		int num = arr[i];
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (num == arr[j])
				return num;
		}
	}
	return 0;
}

//��������ʹ�ù�ϣset����ռ䣬ʱO(N) ��O(N) �д���
int FindNnmber(vector<int>& arr)
{
	set<int> count;
	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (count.count(i) == 1)
			return i;
		else
			count.insert(i);
	}
	return 0;
}

//��������ʹ������ ʱO(Nlogn) ��O(1) ����ͨ�������е�
int FindNnmber(vector<int>& arr)
{
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i] == arr[i + 1])
			return arr[i];
	}
	return 0;
}

//�����ģ�ʹ��ԭ�ؽ���ʱO(N) ��O(1) ����ͨ�������е�
int FindNnmber(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		while (i != arr[i])
		{
			if (arr[i] == arr[arr[i]])
				return arr[i];
			else
				swap(arr[i], arr[arr[i]]);
		}
	}
	return 0;
}

int main()
{
	vector<int> a;
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(11);
	a.push_back(6);
	a.push_back(7);
	a.push_back(8);
	a.push_back(9);
	a.push_back(10);
	a.push_back(11);
	a.push_back(12);
	a.push_back(13);
	a.push_back(14);
	a.push_back(15);;
	cout << FindNmber(a) << endl;;
}
