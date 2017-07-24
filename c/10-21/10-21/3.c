#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int x = 3;//
	int y = 0;
	int sum = 0;
	while (1)
	{
		if (x > 0)
		{
			x--;
			sum++;
			y++;
		}
		if (y == 2)
		{
			x++;
			y = 0;
		}
		if (x == 0)
		{
			break;
		}
	}
	printf("%d", sum);

	return 0;
}