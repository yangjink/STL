#pragma once


#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 10
#define DataType int
typedef struct SeqList
{
	DataType array[MAX_SIZE];
	size_t size;
}SeqList;

void InitSeqList(SeqList* seq);  //��ʼ��
void DestorySeqList(SeqList* seq);//����
//��ɾ�Ĳ�
void PushBack(SeqList *seq, DataType x);
void PopBack(SeqList *seq);

void PushFront(SeqList *seq, DataType x);
void PopFront(SeqList *seq);

void Insert(SeqList *seq, size_t pos, DataType x);
int Find(SeqList *seq, DataType x);
void Erase(SeqList *seq, size_t pos);
void Remove(SeqList *seq, DataType x);
void RemoveAll(SeqList *seq, DataType x);

void BubbleSort(SeqList *seq);
void Selectsort(SeqList *seq);
void InsertSort(SeqList *seq);
int BinarySerach(SeqList *seq, DataType x);//2��

void PrintSeqList(SeqList *seq);