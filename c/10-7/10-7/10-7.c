#define _CRT_SECURE_NO_WARNINGS 1
#include "sanziqi.h"
#include <stdio.h>
#include <stdlib.h>

void com_move(char board[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	srand((unsigned)time(NULL));
	while (1)
	{
		x = rand() % 3;
	}

}
void player_move(char board[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("«Î ‰»Î◊¯±Í£∫");
		scanf("%d%d", &x, &y);
		if (board[x][y] == ' ')
		{
			board[x][y] = 'X';
			return ;
		}
		else
		{
			printf(" ‰»Î¥ÌŒÛ");
		}
	}
	
}

char check_win(char board[ROWS][COLS])
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][1] != ' '))
		{
			return 'p';
		}
	}
}
void init_board(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void print_board(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	for (i = 0; i < ROWS; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		printf("---|---|---\n");
	}
}
void play_game(char board[ROWS][COLS])
{
	char ret;
	while (1)
	{
		player_move(board);
		if ((ret = check_win(board))=='p')
		{
			printf("wan jia sheng");
			break;
		}
		print_board(board, ROWS, COLS);
		com_move(board);
		if ((ret = check_win(board)) == 'p')
		{
			printf("wan shu");
			break;
		}
		print_board(board, ROWS, COLS);
	}
	
}