#include <stdio.h>
int main()
{
	int x = 0,y = 0,z = 0;
	x=12;
	y=23;
	z=x;
	x=y;
	y=z;
	printf("%d   %d",x,y);
	return 0;
}
