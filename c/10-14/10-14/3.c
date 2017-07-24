#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//double Ave(double a, double b)
//{
//	double ave=0;
//	ave = a - b;
//	ave = ave /2;
//	ave = a - ave;
//
//	return ave;
//}
//
//int main()
//{
//	double a = 0;
//	double b = 0;
//	double ave = 0;
//	scanf("%lf%lf", &a, &b);
//	ave = Ave(a, b);
//	printf("%lf   %lf    %lf",a,b,ave);
//	return 0;
//}
int Ave(int a, int b)
{
	int ave = 0;
	ave = ((a&b) + ((a^b) >> 1));
	return ave;
}
int main()
{
	int a = 0;
	int b = 0;
	int ave = 0;
	scanf("%d%d", &a, &b);
	ave = Ave(a, b);
	printf("%d  %d  %d", a, b, ave);
	return 0;
}