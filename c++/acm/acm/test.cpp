#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//Give you two numbers A and B, if A is equal to B, you should print "YES", or print "NO".

//#include<stdio.h>
//
int main()
{/*
	double a;
	double b;
	while (cin>>a>>b)
	{
		if (a == b)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}*/

	int a = 1;

	printf("%d\n", (char)a);
	return 0;
}

//#include <stdio.h>
////给定一个日期，输出这个日期是该年的第几天。
//int main()
//{
//	int year;
//	int month;
//	int day;
//	int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//	int sum = 0;
//	int i = 0;
//	while (scanf("%d/%d/%d", &year, &month, &day) != EOF)
//	{
//		if (month > 2)
//		{
//			if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//			{
//				sum += 1;
//			}
//		}
//		
//		while (i<month)
//		{
//			sum += days[i];
//			i++;
//		}
//		sum += day;
//
//		printf("%d\n", sum);
//
//		i = 0;
//		sum = 0;
//	}
//
//	return 0;
//}

//根据输入的半径值，计算球的体积。
//int main()
//{
//	double r;
//	while (cin >> r)
//	{
//		printf("%.3lf\n", 3.1415927*r*r*r*4/3);
//	}
//	return 0;
//}
//

////输入三个字符后，按各字符的ASCII码从小到大的顺序输出这三个字符。
//int main()
//{
//	char a;
//	char b;
//	char c;
//	while (cin >> a >> b >> c)
//	{
//		if (a > b)
//		{
//			if (b > c)
//			{
//				cout << c << " " << b << " " << a<<endl;
//			}
//			else//b<c
//			{
//				if (a > c)
//				{
//					cout << b << " " << c << " " << a << endl;
//				}
//				else//a<c
//				{
//					cout << b << " " << a << " " << c << endl;
//				}
//			}
//		}
//		else//a<b
//		{
//			if (a > c)
//			{
//				cout << c << " " << a << " " << b << endl;
//			}
//			else//a < c
//			{
//				if (b > c)
//				{
//					cout << a << " " << c << " " << b << endl;
//				}
//				else//b < c
//				{
//					cout << a << " " << b << " " << c << endl;
//				}
//			}
//		}
//	}
//}

//int main()
//{
//	int a;
//	int b;
//	while (cin >> a >> b)
//	{
//		cout << a + b<<endl;
//	}
//	return 0;
//}