#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void pop(int a[] , int num)
{
	int i = 0;
	while (1)
	{
		a[i] = num % 10;
		num = num / 10;
		i++;
		if (num == 0) break;
	}
	
}
int main()
{
	int a[4] = {0};
	int i = 0;
	int sum = 0;
	int j = 0;
	for (i = 0; i < 1000; i++)
	{
		pop(a, i);
		sum = 0;
		for (j = 0; j < 3; j++)
		{
			sum = sum + a[j]*a[j]*a[j];
		}
		if (i == sum)
		{
			printf("%d\n", i);
		}
		
	}
	
	return 0;
}

//int main()
//{
//	int i = 0;
//	int a[4];
//	int j = 0;
//	int sum = 0;
//	int num = 0;
//	for (i = 0; i < 1000; i++)
//	{
//		num = i;
//		sum = 0;
//		for (j = 0; j < 4; j++)
//		{
//			sum = sum + (num % 10)*(num % 10)*(num % 10);
//			num = num / 10;
//		}
//		if (sum == i)
//		{
//			printf("%d\n",i);
//		}
//	}
//	return 0;
//}