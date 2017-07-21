#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int  Fibonacci(int n)
{
	int x = 1;
	int y = 1;
	int i = 0;
	if (n == 1 || n == 2)
	{
		return 1;
	}
	for (i = 3; i < n; i++)
	{
		if (i % 2 == 1)
		{
			x = x + y;
		}
		else
		{
			y = x + y;
		}
	}
	return x + y;

}
int main()
{
	int n = 0;
	printf("请输入：");
	scanf("%d", &n);
	printf("第%d斐波那契数为：%d", n, Fibonacci(n));
	return 0;
}