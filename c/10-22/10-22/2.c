#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

static int judge(const char *str1,const char *str2)
{
	
	int len = 0;
	int i = 0;
	char *p;
	if (str1 == NULL || str2 == NULL)
	{
		printf("不是\n");
		return 0;
	}
	if (strlen(str1) != strlen(str2))
	{
		printf("不是\n");
		return 0;
	}
	p = malloc(2 * len + 1);
	len = strlen(str1);
	strcpy(p, str1);
	strcat(p, str1);
	for (i = 0; i < len; i++)
	{
		if (0 == strncmp(p + i, str2, len))
		{
			printf("是其旋转字符串\n");
			return 1;
		}
	}
	printf("不是\n");
	return 0;
}
int main()
{
	char str1[] = { "AABCD" };
	char str2[] = { "BCDAA" };
	judge(str1, str2);
	return 0;
}
