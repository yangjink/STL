#define _CRT_SECURE_NO_WARNINGS 1
int pop(int a[], int num)
{
	int i = 0;
	while (1)
	{
		a[i] = num % 10;
		//printf("%d\n", x);
		num = num / 10;
		i++;
		if (num == 0) break;
	}