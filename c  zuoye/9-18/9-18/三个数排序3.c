#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void sort(int x, int y, int z)
{
	int i = 0;
	if (x < y)
	{
		i = x;
		x = y;
		y = i;
	}
	if (x < z)
	{
		i = x;
		x = z;
		z = i;
	}
	if (y < z)
	{
		i = y;
		y = z;
		z = i;
	}
	printf("%d   %d   %d", x, y, z);
}
int main()
{
	
	sort(21, 45, 23);
	return 0;
}