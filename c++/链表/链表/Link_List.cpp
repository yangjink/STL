#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkList.h"


void DestoryList(SListNode *& pHead)
{
	if (pHead)
	{
		return;
	}
	else
	{
		SListNode *cur = pHead;
		SListNode *tmp;
		while (cur)
		{
			tmp = cur;
			cur = cur->next;
			free(tmp);
		}
	}
}
SListNode *BuyNode(DataType x)
{
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	if (node == NULL)
	{
		printf("ÉêÇëÊ§°Ü!\n");
		exit(-1);
	}
	node->data = x;
	node->next = NULL;

	return node;
}
void PrintSlist(SListNode *pHead)
{
	SListNode *cur = pHead;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void InitSList(SListNode*& pHead)
{
	SListNode *cur = pHead;
	while (cur)
	{
		cur->data = 0;
		cur = cur->next;
	}
	
}
void PushBack(SListNode*& pHead, DataType x)
{
	SListNode *next = BuyNode(x);
	SListNode *cur = pHead;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = next;
}
void PopBack(SListNode *&pHead)
{
	if (pHead == NULL)
	{
		printf("list is empty!");
		return;
	}
	SListNode *cur=pHead, *next=pHead->next;
	if (next)
	{
		while (next->next)
		{
			cur = cur->next;
			next = next->next;
		}
		cur->next = NULL;
		free(next);
	}
	else 
	{
		free(cur);
	}
	
}
void PushFront(SListNode *&pHead, DataType x)
{
	SListNode *cur = BuyNode(x);
	SListNode *newHead = pHead;
	cur->next = newHead;
	pHead = cur;
}
void PopFront(SListNode *&pHead)
{
	SListNode *cur = pHead;
	pHead = pHead->next;
	free(cur);
}
SListNode *Find(SListNode *pHead, DataType x)
{
	assert(pHead);
	SListNode *cur = pHead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void Insert(SListNode *&pHead, SListNode *pos, DataType x)
{
	assert(pos);
	assert(pHead);
	SListNode *cur = pHead;
	SListNode *next = pHead->next;
	while (next != pos && next)
	{
		cur = cur->next;
		next = next->next;
	}
	if (next == NULL && cur !=pHead)
	{
		printf("not find\n");
		return;
	}
	else if (next == NULL && cur == pHead)
	{
		PushFront(pHead, x);
	}
	else
	{
		SListNode *newHead = BuyNode(x);
		cur->next = newHead;
		newHead->next = next;
	}
}
void Erase(SListNode *&pHead, SListNode *pos)
{
	assert(pos);
	assert(pHead);
	SListNode *cur = pHead;
	SListNode *next = pHead->next;
	while (next != pos && next)
	{
		cur = cur->next;
		next = next->next;
	}
	if (next == NULL && cur != pHead)
	{
		printf("not find\n");
		return;
	}
	else if (next == NULL && cur == pHead)
	{
		free(cur);
		pHead = NULL;
	}
	else
	{
		cur->next = next->next;
		free(next);
	}
}
void Remove(SListNode *&pHead, DataType x)
{
	assert(pHead);
	SListNode *cur = pHead;
	SListNode *next = cur->next;
	if (cur->data == x)
	{
		PopFront(pHead);
		return;
	}
	while (next && (next->data != x))
	{
		cur = cur->next;
		next = next->next;
	}
	if (next == NULL )
	{
		printf("not found!\n");
	}
	else
	{
		cur->next = next->next;
		free(next);
	}
}


