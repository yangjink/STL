#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0; 
	int j = 0;
	char arr1[] = { "welocome to mewore" };
	char arr2[] = { "##################" };
	for (i = 0,j = (strlen(arr1) - 1); i<(strlen(arr1) / 2); i++,j--)
	{
		arr2[i] = arr1[i];
		arr2[j] = arr1[j];
	    printf("%s\n",arr2);	
	}
	return 0;
}