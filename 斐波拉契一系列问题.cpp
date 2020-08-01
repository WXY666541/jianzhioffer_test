#include<iostream>
/*
쳲���������
����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0
��Ϊ0����1����1����
*/
//����һ���ݹ�Ĺ���
int Fibonacci(int n)
{
	if (n == 0 )
	{
		return 0;
	}
	if (n <= 2)
	{
		return 1;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
//����һ�������Ĺ���
int Fibonacci1(int n)
{
	if (n == 0)
		return 0;
	int first = 1;
	int second = 1;
	int third = 2;
	while (n > 2)
	{
		third = first + second;
		first = second;
		second = third;
		n--;
	}
	return third;
}
int main()
{
	std::cout << Fibonacci1(5) << std::endl;
	return 0;
}


/*
������̨�����⣺
һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
�����������һ��n����̨���ܹ��ж�������������
�����ͬ�㲻ͬ�Ľ������
*/
int jumpfloor(int n)
{
	int* dp = new int[n + 1];
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[n] = dp[n - 1] + dp[n - 2];
	}
	int number = dp[n];
	delete dp;
	return number;
}


/*
���󸲸ǣ�
���ǿ����� 2*1 ��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
������n�� 2*1 ��С�������ص��ظ���һ��2*n �Ĵ���Σ�
�ܹ��ж����ַ���������n=3ʱ�� 2*3 �ľ��ο���3�ָ��Ƿ�����
*/
int rectCover(int number)
{
	if (number < 2)
	{
		return number;
	}
	int* dp = new int[number + 1];
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= number; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int num = dp[number];
	delete dp;
	return num;
}
