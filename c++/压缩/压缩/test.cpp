#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

#include "HuffmanTree.h"
#include "compress.h"
#include "Heap.h"



//void Test2()
//{
//	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
//	Heap<int>  i;
//	int j = 10;
//	while (j)
//	{
//		i.Push(a[j]);
//		j--;
//	}
//	Heap<int> z(a, 10);
//}

int main()
{
	Test1();
	//Test2();
	return 0;
}