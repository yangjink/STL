#define _CRT_SECURE_NO_WARNINGS 1
#include "CommentConvert.h"

void DOConvertWork(FILE* pfRead,FILE* pfWrite)
{
	state = NUL_STATE;
	while (state != END_STATE)
	{
		switch (state)
		{
			case NUL_STATE:
				DoNulState(pfRead,pfWrite);
				break;
			case C_STATE:
				DoCState(pfRead, pfWrite);
				break;
			case CPP_STATE:
				DoCppState(pfRead, pfWrite);
				break;
			case END_STATE:
			    break;
		}
	}
}

int  main()
{
	FILE* pfRead = NULL;
	FILE* pfWrite = NULL;

	pfRead = fopen(INPUT_FILE, "r");
	if (pfRead == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	pfWrite = fopen(OUTPUT_FILE, "w");
	if (pfWrite == NULL)
	{
		perror("open file for write");
		fclose(pfRead);
		exit(EXIT_FAILURE);
	}

	DOConvertWork(pfRead,pfWrite);


	fclose(pfRead);
	fclose(pfWrite);
	return 0;
}