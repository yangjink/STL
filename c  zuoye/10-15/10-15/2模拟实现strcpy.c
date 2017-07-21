#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdio.h>

char *Strcpy(char arr1[],const  char arr2[])
{
	int i = 0;
	while (1)
	{
		if (arr2[i] != '\0')
		{
			arr1[i] = arr2[i];
			i++;
		}
		else
		{
			arr1[i] = '\0';
			return;
		}

	}
}

int main()
{
	int i = 0;
	int j = 0;
	int z = 0;
	char arr3[] = { 0 };
	char arr1[] = {"sssaadfsdfsf"};
	char arr2[] = {"sdfasdddf"};
	Strcpy(arr1, arr2);
	printf("%s\n", arr3);
	return 0;
}