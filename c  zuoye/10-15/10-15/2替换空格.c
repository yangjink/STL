#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void Replace(char arr[])
{
	int count = 0;
	int len = 0;
	char arr_new[500];
	len = strlen(arr);
	while(1)
	{
		printf("%c\n", arr[count]);

		if (arr[count] == ' ')
		{
			len =len + 2;
			count++;
		}
		else if (arr[count] == '\0')
		{
			break;
		}
		else
		{
			count++;
		}
		
	}
	while ((len+1))
	{
		if (arr[count] == ' ')
		{

			count--;
			arr_new[len] = '0';
			arr_new[--len] = '2';
			arr_new[--len] = '%';
			len--;

		}
		else 
		{
			arr_new[len] = arr[count];
			len--;
			count--;
			
		}
	}
	printf("%s", arr_new);
	
}
int main()
{
	char arr[] = {"¡°we are happy.¡±"};
	Replace(arr);
	return 0;
}