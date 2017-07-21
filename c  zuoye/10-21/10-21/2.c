#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void str_revresal(char str[])
{
	int i = 0;
	int j = strlen(str);
	char x = NULL;
	for (i = 0; i <j; i++,j--)
	{
		x = str[i];
		str[i] = str[j-1];
		str[j-1] = x;
	}
	
}
int main()
{
	char str1 []= { "hello world!" };
	str_revresal(str1);
	printf("%s\n", str1);
	return 0;
}