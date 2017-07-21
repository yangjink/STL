#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	float sum = 0.0;
	int i = 0;
	for (i = 1.0; i <=3; i=i+1)
	{
		if (i % 2 == 0)
		{
			sum = sum - (1.0 / i);
		}
		else
		{
			sum = sum + (1.0 / i);
		}
	}
	printf("%f",sum);
	return 0;
}