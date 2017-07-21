#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h> 

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
	char arr[30] = { "student a am i" };
	int len = Strlen(arr)-1;
	char arr1[] = { 0 };
	int i = 0;
	int j = 0;//单词的长度
	int z = 0;
	char X;
	for (i = 0; i < len; i++)
	{
		X = arr[len];
		arr[len] = arr[i];
		arr[i] = X;
		len--;
	}
	printf("%s\n", arr);
	i = 0;
	while (1)
	{
		 j = 0;
		while (1)
		{
			
			if (arr[i] != ' ')
			{
				j++;
				i++;
			}
			else if (arr[i] == '\0')
			{
				break;
			}
			else
			{
				break;
			}
		}
		// i ma a
		
		if ((j != 1) && (j != ' '))
		{
			int x = i-2; int y = i + j - 3;
			for (; x < y; x++)
			{
				X = arr[y];
				arr[y] = arr[x];
				arr[x] = X;
				y--;
			}
		
		}
		if (arr[i] == '\0')
		{
			break;
		}
		i++;
	}
	printf("%s\n", arr);
	return 0;
}