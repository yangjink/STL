#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void print(int num, int *p, int *s)
{
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (i % 2 == 0) p[i/2] = (num & 1);
		else  s[i/2] = (num & 1);
			num=num >> 1;
	}
}
int main()
{
	int a[16];
	int b[16];
	int num=7;
	int j;
	int i;
	print(num,a,b);
	printf("偶数位序列:");
	for (j = 15; j >= 0; j--)
	{
		printf("%d", b[j]);
	}
	printf("\n奇数位序列:");
	for (i = 15; i >= 0; i--)
	{
		printf("%d", a[i]);
	}
	return 0;
}