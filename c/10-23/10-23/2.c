#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>  
Find_Num(int arr[], int sz, int  *num1, int *num2)
{
	int i = 0;
	int ret = 0;
	int pos = 0;
	int temp = 0;
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	temp = ret;
	while (ret)
	{
		if (ret % 2 == 1)
		{
			break;
		}
		pos++; 
		ret /= 2;
	}
	//ret=1
	for (i = 0; i < sz; i++)
	{
		if ((arr[i] >> pos) & 1)
		{
			*num1 ^= arr[i];
		}
	}
	*num2 = temp^*num1;
}
int main()
{
	int num1 = 0;
	int num2 = 0;
	int arr[] = { 1,2,3,1};
	int sz = sizeof (arr) / sizeof(arr[0]);
	Find_Num(arr, sz, &num1, &num2);
	printf("%d,%d\n", num1, num2);
	return 0;
}