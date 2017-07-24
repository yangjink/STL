#include <stdio.h>
int main()
{
	int a[10] = {0,1,222,3,465,5,6,7,8,9};
	int i = 0;
	int max = a[0];

	for (i = 1; i < 9; i++)
	{
		if(a[i] >= max)
		{
			max = a[i];
		}
		
	}
	printf("%d\n", max);
	
	return 0;
}