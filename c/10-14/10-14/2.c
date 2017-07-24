#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <math.h>
unsigned int reverse_bit(unsigned int value)
{
	unsigned int num = 0;
	 int i = 0;
	 int bit = 0;
	for (i = 0; i < 32; i++)
	{
		bit = value & 1;
		num <<= 1;
		num = num | bit;
		value >>= 1;
	}
	return num;
}

int main()
{
	unsigned int a = 25;
	unsigned int b = 0;
	b = reverse_bit(a);
	printf("%u,%u\n", a, b);
	return 0;
}

//unsigned int reverse_bit(unsigned int value)
//{
//	unsigned int num = 0;
//	unsigned int i = 0;
//	unsigned bit = 0;
//	for (i = 31; i >=0; --i)
//	{
//		bit = value & 1;
//		num = num + bit * pow(2.0, (float)i);
//		value = value >> 1;
//		printf("%ld ", num);
//	}
//	return num;
//}