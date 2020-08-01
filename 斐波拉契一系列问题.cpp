#include<iostream>
/*
斐波拉契数列
现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0
项为0，第1项是1）。
*/
//方法一：递归的过程
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
//方法一：迭代的过程
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
青蛙跳台阶问题：
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先
后次序不同算不同的结果）。
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
矩阵覆盖：
我们可以用 2*1 的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个 2*1 的小矩形无重叠地覆盖一个2*n 的大矩形，
总共有多少种方法？比如n=3时， 2*3 的矩形块有3种覆盖方法：
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
