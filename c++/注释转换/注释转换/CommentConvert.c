#define _CRT_SECURE_NO_WARNINGS 1
#include "CommentConvert.h"

void DoNulState(FILE* pfRead, FILE* pfWrite)
{
	int first = 0;
	int second = 0;
	first = fgetc(pfRead);
	if (first == '/')
	{
		second = fgetc(pfRead);
		if (second == '*')
		{
			fputc('/', pfWrite);
			fputc('/', pfWrite);
			state = C_STATE;
		}
		else if (second == '/')
		{
			fputc(first, pfWrite);
			fputc(second, pfWrite);
			state = CPP_STATE;
		}
		else
		{
		}
	}
	else if (first == EOF)
	{
		state = END_STATE;
	}
	else
	{
		fputc(first, pfWrite);
	}
}
void DoCState(FILE* pfRead, FILE* pfWrite)
{
	int first = 0;
	int second = 0;
	first=fgetc(pfRead);
	if (first == '*')
	{
		second = fgetc(pfRead);
		if (second == '/')
		{
			int third = 0;
			third = fgetc(pfRead);
			if (third == '\n')
			{
				fputc(third, pfWrite);
				state = NUL_STATE;
			}
			else
			{
				fputc('\n', pfWrite);
				fputc(third, pfWrite);
				state = NUL_STATE;
			}
		}
		else
		{
			fputc(first, pfWrite);
			ungetc(second,pfRead);
		}
	}
	else if (first == '/')//// 3.匹配问题  /*int i = 0;/*xxxxx*/
	{
		second = fgetc(pfRead);
		if (second == '*')
		{
			
		}
		else
		{
			fputc(second, pfWrite);
		}

	}
	else if (first == '\n')// 4.多行注释问题
	{
		fputc('\n', pfWrite);
		fputc('/', pfWrite);
		fputc('/', pfWrite);
	}
	else
	{
		fputc(first, pfWrite);
	}
}
void DoCppState(FILE* pfRead, FILE* pfWrite)
{
	int first = 0;
	first = fgetc(pfRead);
	if (first == '\n')
	{
		fputc(first, pfWrite);
		state = NUL_STATE;
	}
	else if (first == EOF)
	{
		state = END_STATE;
	}
	else
	{
		fputc(first, pfWrite);
	}
}