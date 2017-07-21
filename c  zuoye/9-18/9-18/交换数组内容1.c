#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void swap(int *p, int *s, int length)
{
	int tmp = 0;
	for (int i = 0; i < length; i++)
	{
		tmp = *(p + i);
		*(p + i) = *(s + i);
		*(s + i) = tmp;
	}
}

int main()
{
	int a1[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int a2[10] = { 2,3,4,5,6,7,8,9,10,11 };

	swap(a1, a2 ,10);

	return 0;
}