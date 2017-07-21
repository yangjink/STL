#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int Strlen(const char arr[])
{
	int count = 0;
	while (1)
	{
		if (arr[count] != '\0')
		{
			count++;
		}
		else
		{
			return count;
		}
	}
}
int main()
{
	int len = 0;
	char arr1[] = { "sdfskdfsdflkja" };
	len = Strlen(arr1);
	printf("%d\n", len);
	return 0;
}