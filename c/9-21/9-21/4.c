#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	float a, b, c, d, e, x1, x2;
	printf("�밴˳������һԪ���η���ax^2+by+c=0������ϵ��a��b��c:");
	scanf("%f%f%f", &a, &b, &c);
	d = b*b - 4 * a*c;
	e = sqrt(-d);
	if (d<0)
		printf("\n�÷��̵Ľ�Ϊ��X1=-%f-%fi\nX2=-%f+%fi", b / (2.0*a), e / (2.0*a), b / (2.0*a), e / (2.0*a));
	else if(d > 0)
	{
		x1 = (-b - sqrt(d)) / (2.0*a);
		x2 = (-b + sqrt(d)) / (2.0*a);
		printf("\n�÷��̵Ľ�Ϊ��\nx1=%f\nx2=%f", x1, x2);
	}
	else
	{
		x1 = (-b - sqrt(d)) / (2.0*a);
		printf("\n�÷��̵Ľ�Ϊ��\nx1=x2=%f", x1 );
	}

	
	return 0;
}