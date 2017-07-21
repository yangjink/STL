#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkList.h"

void Test2()
{
	SListNode *p = BuyNode(4);
	PushFront(p, 2);
	Insert(p, Find(p, 4), 9);
	PrintSlist(p);
	//Erase(p, Find(p, 4));
	//Erase(p, Find(p, 9));
	//Erase(p, Find(p, 2));
	Remove(p, 2);
	PrintSlist(p);

	DestoryList(p);
}
void Test1()
{
	SListNode *p = BuyNode(2);
	InitSList(p);
	PushBack(p, 2);
	PushBack(p, 3);
	PushBack(p, 4);
	PushBack(p, 5);
	PrintSlist(p);
	PopBack(p);
	PrintSlist(p);
	PushFront(p, 2);
	PushFront(p, 2);
	PushFront(p, 4);
	PushFront(p, 2);
	PushFront(p, 3);
	PopFront(p);
	PrintSlist(p);
	Insert(p, Find(p,4), 9);
	PrintSlist(p);

	DestoryList(p);
}
int main()
{
	//Test1();
	Test2();
	return 0;
}