#define _CRT_SECURE_NO_WARNINGS 1


#include "Complex.h"

int main()
{
	Complex b2(12,21);
	Complex b1(10, 10);
	Complex b3 = b1 + b2;
	b3.print();
	getchar();
	return 0;
}