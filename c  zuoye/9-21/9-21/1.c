#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 1;
	char x;
	char y;
	while (1)
	{
		
		//scanf("%c", &x); 
		x=getch();
		//getch();
		//fflush(stdin);
		if (x >64 && x < 91)
		{
			y = x + 32;
			printf("%c\n", y);
			
		}
		
		else if (x > 96 && x < 122)
		{
			y = x - 32;
			printf("%c\n", y);
				
		}
		else if (x > 47 && x < 59)
		{
			 ;
		}
		else
		{
			 printf("ÊäÈëÓÐÎó£¡\n");
		}
				
	}
	return 0;
}