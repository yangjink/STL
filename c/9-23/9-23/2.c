#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
	int i = 0;
	int j = 0;
	char arr1[8] = { "abcd123" };
	char password[] = {0};
	for (i = 0; i < 3; i++)
	{
		
		scanf("%s", password);
		if (strcmp(password, arr1) == 0)
		{
			break;
		}
		fflush(stdin);
	}
	if (i >= 3)
	{
		printf("µÇÂ½Ê§°Ü£¡");
	}
	else
	{
		printf("µÇÂ½³É¹¦");
	}
	return 0;
}