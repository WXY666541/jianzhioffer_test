/*
***************************
��ά����Ĳ���
***************************
*/

//ʹ�ù��ɣ�ѡȡ���Ͻǵ�ֵ��Ϊ��׼  ��ȷ�ģ������е�
bool FindNumIn2DArray(vector<vector<int>>& arr, int target)
{
	if (arr.size() == 0)
		return false;

	int m = arr.size();
	int n = arr[1].size();

	int row = 0;
	int clo = n - 1;

	while (row < m && clo > 0)
	{
		if (arr[row][clo] > target)
			clo -= 1;
		else if (arr[row][clo] < target)
			row += 1;
		else
			return true;
	}
	return false;
}

////���ö��ֲ��ҵķ��� ��ȷ�ģ������е�
bool findNumberIn2DArray(vector<vector<int>>& arr, int target) {

	if (arr.size() == 0)
		return false;
	for (int i = 0; i < arr.size(); i++)
	{
		int high = arr[i].size() - 1;
		int low = 0;
		while (low <= high)
		{
			int mid = (high - low + 1) / 2 + low;
			if (arr[i][mid] > target)
				high = mid - 1;
			else if (arr[i][mid] < target)
				low = mid + 1;
			else
				return true;
		}
	}
	return false;
}
int main()
{
	vector<vector<int>> arr;
	int num = 1;//��������ʼֵ��

	//����4���ռ�Ϊ0
	for (int i = 0; i < 4; i++)
	{
		arr.push_back(vector<int>());
	}
	//��4���ռ�Ļ�����ÿ���ռ����ٿ���4���ռ䣬����num���г�ʼ��
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			arr[i].push_back(num);
			num++;
		}
	}

	if (FindNumIn2DArray(arr, 12))
	{
		cout << "find success" << endl;
	}
	else
		cout << "faild" << endl;
}
