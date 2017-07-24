#define _CRT_SECURE_NO_WARNINGS 1
#include "mine_s.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void first_show(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)//第一次打开显示周边情况
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			put_show(mine, show, (x - 1 + i), (y - 1 + j));
		}
	}
}
void initiative(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)//假如周围没有雷自动打开
{
	int ret = 48;
	int i = 0;
	int j = 0;
	for (i = 0; i < 3 ; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (mine[x-1+i][y-1+i]!='1')
			put_show(mine, show, (x - 1+i),(y-1+j));
		}
	}
}
void first_mine(char mine[ROWS][COLS], int x, int y)//第一次踩中雷就把雷换个位置
{
		mine[x][y] = '0';
		while (1)
		{
			int a = 0;
			int b = 0;
			a = rand() % (ROWS - 1) + 1;
			b = rand() % (COLS - 1) + 1;

			if (mine[a][b] == '0')
			{
				mine[a][b] = '1';
				break;
			}
		}

}

int judge(char mine[ROWS][COLS],int x,int y)//判断周围雷数
{
	int count = 48;
	if (mine[x - 1][y - 1] == '1') count++;
	if (mine[x - 1][y] == '1') count++;
	if (mine[x - 1][y + 1] == '1') count++;
	if (mine[x][y - 1] == '1') count++;
	if (mine[x][y + 1] == '1') count++;
	if (mine[x + 1][y - 1] == '1') count++;
	if (mine[x + 1][y] == '1') count++;
	if (mine[x + 1][y + 1] == '1') count++;

	return count;
}
void put_show(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y)
{
	int ret = 0;
	ret = judge(mine,x,y);
	show[x][y] = ret;
}

void put_mine(char mine[ROWS][COLS])
{
	int count = MINE;
	int x = 0;
	int y = 0;
	srand((unsigned)time(NULL));
	while (count)
	{
		x = rand() % (ROWS-1) + 1;
		y = rand() % (COLS-1) + 1;

		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			 count--;
		}
	}
}
void play_game(char mine[ROWS][COLS], char show[ROWS][COLS])
{
	int win = MINE;
	put_mine(mine);
	while (win < ((ROWS - 1)*(COLS - 1)))
	{
		int x = 0;
		int y = 0;
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if ((win == MINE) && mine[x][y] == '1')
		{
			first_mine(mine, x, y);
		}
		first_show(mine,show,x,y);
		if (mine[x][y] == '1')
		{
			printf("踩雷了！！！\n");
			print(mine);
			return;
		}
		if (judge(mine,x,y) == 48)
		{
			initiative(mine, show, x, y);
		}
		
		put_show(mine,show, x, y);
		print(show);
		win++;
	}
	printf("恭喜你，你获胜了！！！！\n");
	print(mine);
}
void init_mine(char mine[ROWS][COLS])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			mine[i][j] = '0';
		}
	}
}
void init_show(char show[ROWS][COLS])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			show[i][j] = '*';
		}
	}
}
void print(char arr[ROWS][COLS])
{
	int i = 0;
	int j = 0;
	printf("  0|");
	for (i = 1; i < COLS; i++)
	{
		printf(" %d ", i);
		//printf("_\n");
	}printf("\n");
	printf("-----------------------------------\n");
	for (i = 1; i < ROWS ; i++)
	{
		printf(" %2d", i);
		printf("|");
		for (j = 1; j < COLS; j++)
		{
			printf(" %c ", arr[i][j]);
		}
		printf("\n");
	}
}
//简单判断周围方法
/*if (ret == judge(mine, x, y))
{
put_show(mine, show, x-1, y-1);
}if (ret == judge(mine, x, y))
{
put_show(mine, show, x - 1, y );
}if (ret == judge(mine, x, y))
{
put_show(mine, show, x - 1, y + 1);
}if (ret == judge(mine, x, y))
{
put_show(mine, show, x , y - 1);
}if (ret == judge(mine, x, y))
{
put_show(mine, show, x , y + 1);
}if (ret == judge(mine, x, y))
{
put_show(mine, show, x + 1, y - 1);
}if (ret == judge(mine, x, y))
{
put_show(mine, show, x + 1, y );
}if (ret == judge(mine, x, y))
{
put_show(mine, show, x + 1, y + 1);
}*/