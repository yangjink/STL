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
	printf("������Ҫ�жϵ�����:\n");
	scanf("%d", &x);
	num = count_one_bits(x);
	printf("��%d��1",num);

	return 0;
}
