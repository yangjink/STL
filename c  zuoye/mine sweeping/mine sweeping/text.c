#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "mine_s.h"

void menu()
{
	printf("***************************************\n");
	printf("*********      1.����Ϸ      **********\n");
	printf("*********      0.�˳�        **********\n");
	printf("***************************************\n");

}

void game()
{
	int input = 0;
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	while (1)
	{
		menu();
		init_mine(mine);
		init_show(show);
		printf("��ѡ��");
		scanf("%d", &input);
		if (input == 1)
		{
			print(show); 
			play_game(mine,show);
			
		}
		else
		{
			break;
		}
	}
	
}

int main()
{
	game();
	return 0;
}