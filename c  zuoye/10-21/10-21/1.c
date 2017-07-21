#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

char *Strstr(const char *arr1, const char *arr2)
{
	assert(NULL != arr1);
	assert(NULL != arr2);
	//static char arr3[] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < strlen(arr1); i++)
	{
		if (arr1[i] == arr2[j])
		{
			j++;
			if (j == strlen(arr2))
			{
				break;
			}
		}
		else
		{
			j = 0;
		}
	}
	if (i == strlen(arr1))
	{
		return NULL;
	}
	else
	{
		return &arr1[i - 1];
	}
}

int main()
{
	char arr3[] = { "wossaaldkf23jj" };
	char arr4[] = { "aa" };
	//Strstr(arr1, arr2);
	printf("%s", Strstr(arr3, arr4));
	return 0;
}
