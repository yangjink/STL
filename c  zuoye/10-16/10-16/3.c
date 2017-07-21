#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define EXCHANGE(X) \
	((X & (0x55555555)) << 1) | ((X & (0xAAAAAAAA)) >> 1)


int main()
{
	int x = 1;
	printf("%d\n", EXCHANGE(x));
	system("pause");
	return 0;
}