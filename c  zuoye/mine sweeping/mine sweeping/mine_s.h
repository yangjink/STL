#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __SL_GAME_H__
#define __SL_GAME_H__

#define ROWS 11
#define COLS 11
#define MINE 10   //·ÅÖÃµÄÀ×Êý

void init_mine(char mine[ROWS][COLS]);
void init_show(char show[ROWS][COLS]);
void print(char board[ROWS][COLS]);
void play_game(char mine[ROWS][COLS], char show[ROWS][COLS]);
void put_show(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
int judge(char mine[ROWS][COLS], int x, int y);
void first_mine(char mine[ROWS][COLS], int x, int y);
void initiative(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
void first_show(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);


#endif 