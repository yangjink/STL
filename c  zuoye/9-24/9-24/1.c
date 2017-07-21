#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int  i = 0;
	int  j = 0;
	int  z = 0;
	int  num = 0;//给的行数
	scanf("%d", &num);
	for (i = 1; i <= num; i++)
	{
		for (j = num; j > i; j--)
		{
			printf(" ");
		}
		for (z = 1; z <= (2*i-1); z++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = (num-1); i >=1; i--)
	{
		for (j = num; j > i; j--)
		{
			printf(" ");
		}
		for (z = 1; z <= (2 * i - 1); z++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}