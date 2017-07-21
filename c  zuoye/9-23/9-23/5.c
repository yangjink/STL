#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int x = 0;
	int sum = 0;
	for (i = 1; i <= 100; i++)
	{
		j = i;
		while (1)
		{
			x = j % 10;
			
			j = j/ 10;
			if (x == 9)
			{
				sum++;
			}
			if (j == 0) break;
		}
	}
	printf("%d\n", sum);
	return 0;
}