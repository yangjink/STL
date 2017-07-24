#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int gcm(int x, int y)//最大公约数 greatest common measure GCM 
{
	int i = 0;
	int z = 0;
	int gcm = 0;
	if (x > y) z = y;
	else z = x;
	for (i = 1; i <= z; i++)
	{
		if (x%i == 0 && y%i == 0)
		{
			gcm = i;
		}
	}
	return gcm;
}
int main()
{
	
	printf("%d", gcm(23, 69));
	return 0;
}