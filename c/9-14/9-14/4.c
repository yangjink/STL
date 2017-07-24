#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int count_one_bits(unsigned int value)
{
	int count = 0; 
	while (value  != 0)
	{
		if (value % 2 == 1)
		{
			count++;
		}
		value = value >> 1;
	}
	return count;
}
int main()
{
	int x;
	int num;
	printf("请输入要判断的数字:\n");
	scanf("%d", &x);
	num = count_one_bits(x);
	printf("有%d个1",num);

	return 0;
}
