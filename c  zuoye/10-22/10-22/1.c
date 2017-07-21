#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

void reverse(char *left, char *right)
{
	char tmp;
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		*left++;
		*right--;
	}
}
void str_levo(char *arr, int x)
{
	assert(NULL != arr);
	int len = strlen(arr);
	reverse(arr,arr+x-1);
	reverse(arr + x,arr+len-1);
	reverse(arr, arr + len - 1);
}
int main()
{
	char str[] = { "AABDDDASDF" };
	str_levo(str, 3);
	printf("%s\n", str);
	return 0;
}
