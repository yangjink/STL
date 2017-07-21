#define _CRT_SECURE_NO_WARNINGS 1
//
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//
//	char strarr[255];
//	gets(strarr);
//	
//	string str(strarr);
//	
//	size_t begin = 0;
//	size_t end = 0;
//	size_t len = 0;
//	size_t cur = 0;
//	size_t newlen = 0;
//	for (size_t i = 0; i < str.size(); i++)
//	{
//		if (str[i]>'0' && str[i] < '9' || (str[i + 1] == '\0'))
//		{
//			end++;
//			newlen++;
//			if ( (str[i + 1] == '\0')||(str[i + 1] > 'A' && str[i + 1] < 'z'))
//			{
//				if (newlen > len)
//				{
//					len = newlen;
//					cur = begin;
//					begin = end;
//					newlen = 0;
//				}
//				else
//				{
//					begin = end;
//					newlen = 0;
//				}
//			}
//		}
//		else if (str[i] > 'A' && str[i] < 'z')
//		{
//			begin++;
//			end++;
//			/*if (str[i+1] > '0' && str[i+1] < '9')
//			{
//
//			}*/
//		}
//	}
//
//	while (len)
//	{
//		cout << str[cur++];
//		len--;
//	}
//
//
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int a[10];
//	int b[20];
//	char c[100];
//	gets(c);
//	for (int i = 0; i < 20; i++)
//	{
//		b[i] = i;
//	}
//	for (int j = 0; j < 10; j++)
//	{
//		a[j] = b[j];
//	}
//	make_heap(&a[0],&a[11]);
//	int count = 20;
//	for (int z = 10; z < 20; z++)
//	{
//		if (b[z] < a[0])
//		{
//			pop_heap(&a[0], &a[11]);
//			a[10] = b[z];
//			push_heap(&a[0], &a[11]);
//		}
//	}
//	sort_heap(&a[0], &a[10]);
//
//	return 0;
//}

#include <iostream>
using namespace std;

int main()
{
	char a[20];
	//scanf("%s", a);
	//gets(a);
	//a = getchar();
	while (b = getchar() != '/0');
	printf("%s ", a);
	return 0;
}