#include <stdio.h>
int main()
{
	int x = 0, y = 0;
	x = 12;
	y = 23;
	x = x + y;
	y = x - y;
	x = x - y;
	printf("x=%d   y=%d", x, y);
	return 0;
}
