#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef int DataType;

typedef struct SListNode
{
	DataType data;
	struct SListNode *next;
}SListNode;
SListNode *BuyNode(DataType x);
void PrintSlist(SListNode *pHead);
void InitSList(SListNode *&pHead);
void PushBack(SListNode *&pHead, DataType x);
void PopBack(SListNode *&pHead);
void PushFront(SListNode *&pHead, DataType x);
void PopFront(SListNode *&pHead);
//在pos前插入一个数据
void Insert(SListNode *&pHead, SListNode *pos, DataType x);
void Erase(SListNode *&pHead, SListNode *pos);
void Remove(SListNode *&pHead, DataType x);
SListNode *Find(SListNode *pHead, DataType x);
void DestoryList(SListNode *& pHead);