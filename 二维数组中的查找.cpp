/*
***************************
二维数组的查找
***************************
*/

//使用规律，选取右上角的值作为基准  正确的，可运行的
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

////采用二分查找的方法 正确的，可运行的
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
	int num = 1;//用来赋初始值的

	//开辟4个空间为0
	for (int i = 0; i < 4; i++)
	{
		arr.push_back(vector<int>());
	}
	//在4个空间的基础上每个空间中再开辟4个空间，并用num进行初始化
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
