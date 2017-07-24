#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int sn = 0;
	int i = 0;
	int j = 0;
	int x = 0;
	int num = 0;
	int z = 0;
	printf("«Î ‰»Î1~9£∫\n");
	scanf("%d",&x); 
	for (i=1;i<=5;i++)
	{
		num = x;
		z = 1;
		for (j = 2; j <= i; j++)
		{
			
			z = 10 * z;
			num = num + x * z;
		}
		
		sn = sn + num;
	}
	printf("%d", sn);
	return 0;
}