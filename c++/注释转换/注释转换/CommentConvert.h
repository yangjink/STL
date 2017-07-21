#ifndef __COMMENT_CONVERT_H__
#define __COMMENT_CONVERT_H__

#include <stdio.h>
#include <stdlib.h>
#define INPUT_FILE "input.c"
#define OUTPUT_FILE "output.c"

typedef enum STATE
{
	NUL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE,
}State;
State state;
void DoNulState(FILE* pfRead,FILE* pfWrite);
void DoCState(FILE* pfRead, FILE* pfWrite);
void DoCppState(FILE* pfRead, FILE* pfWrite);


#endif