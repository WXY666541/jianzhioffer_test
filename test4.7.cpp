#include<iostream>
#include<vector>
using namespace std;
#if 0
/*
******************************
剪绳子
******************************
*/
int maxproductAfterCutting(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	for (int i = 4; i <= length; i++)
	{
		max = 0;
		for (int j = 1; j < i / 2; j++)
		{
			int product = products[i] * products[i - j];
			if (max < product)
				max = product;

			products[i] = max;
		}
	}
	max = products[length];
	delete[] products;
	return max;
}

int maxproductAfterCutting1(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	//尽可能多的剪去长度为3的绳子段
	int timeOf3 = length / 3;

	//当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段
	//此时更好的方法就是把绳子剪成长度为2的两段
	if (length - timeOf3 * 3 == 1)
		timeOf3 -= 1;

	int timeOf2 = (length - timeOf3 * 3) / 2;
	return (int)(pow(3, timeOf3)) * (int)(pow(2, timeOf2));
}
#endif
