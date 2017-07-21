#define _CRT_SECURE_NO_WARNINGS 1
#include "seqList.h"

void Text3(SeqList *seq)
{

}
void Text2(SeqList *seq)
{
	InitSeqList(seq);
	//PushFront(seq, 1);
	//PushFront(seq, 2);
	//PushFront(seq, 2);
	//PushFront(seq, 2);
	//PushFront(seq, 2);
	//PushFront(seq, 2);
	//PushFront(seq, 2);
	//PushFront(seq, 3);
	//PrintSeqList(seq);

	//PopFront(seq);
	//PrintSeqList(seq);
	//Insert(seq, 2, 4);
	//Insert(seq, 2, 2);
	//Insert(seq, 2, 5);
	//Insert(seq, 2, 4);
	//Insert(seq, 2, 4);
	//Insert(seq, 2, 4);
	//Insert(seq, 2, 3);
	//PrintSeqList(seq);
	//int x=Find(seq, 5);
	//printf("%d\n", x);
	////Remove(seq, 5);
	////RemoveAll(seq, 3);
	PushFront(seq, 2);
	PushFront(seq, 4);
	PushFront(seq, 9);
	PushFront(seq, 1);
	PushFront(seq, 2);
	PushFront(seq, 5);

	PrintSeqList(seq);
	//InsertSort(seq);
	Selectsort(seq);
	PrintSeqList(seq);

}

void Text1(SeqList *seq)
{
	InitSeqList(seq);
	PushBack(seq, 4);
	PushBack(seq, 3);
	PushBack(seq, 2);
	PushBack(seq, 1);
	PrintSeqList(seq);
	PopBack(seq);
	PopBack(seq);
	PopBack(seq);
	PopBack(seq);
	PopBack(seq);
	PrintSeqList(seq);
}
int main()
{
	SeqList Lq;
	//Text1(&Lq);
	Text2(&Lq);
	//Text3(&Lq);
	return 0;
}