#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int arr[] = { 12, 12, 5, 3, 6, 5, 6, 9, 8, 8, 9 };
	int i = 0;
	int num = 0;
	num = arr[0];
	for (i = 1; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{        
		num = num ^ arr[i];
	}
	printf("%d", num);
	return 0;
}