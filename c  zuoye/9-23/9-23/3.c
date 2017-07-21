#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int num = 0;
	int i = 0;
	int x = 0;
	scanf("%d",&num);
	while (1)
	{
		x = num % 10;
		printf("%d\n", x);
		num = num / 10;
		if (num == 0) break;
	}
	
	return 0;
}