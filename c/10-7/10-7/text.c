#define _CRT_SECURE_NO_WARNINGS 1
#include "sanziqi.h"
#include <stdio.h>
void menu()
{
	printf("*************************\n");
	printf("*****    1.play    ******\n");
	printf("*****    0.exit    ******\n");
	printf("*************************\n");

}
void game()
{
	int input = 1;
	char board[ROWS][COLS] = { 0 };
	init_board(board, ROWS, COLS);
	//print_board(board, ROWS, COLS);
	while (input)
	{
		menu();
		printf("«Î—°‘Ò:");
		scanf("%d", &input);
		play_game(board);

	}
}

int main()
{
	//game();
	int x = 0;
	int y = 0;
	srand((unsigned)time(NULL));
	while (1)
	{
		x = rand() % 3;
		printf("%d", x);
	}
	return 0;
}