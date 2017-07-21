#define _CRT_SECURE_NO_WARNINGS 1
#include "seqList.h"
//排序
int BinarySerach(SeqList *seq, DataType x)//2分
{
	int end = seq->size;
	int begin = 1;
	while (begin < end){
		int mid = begin + (end - begin) >> 1;
		if (seq->array[mid] < x)
		{
			begin = mid + 1;
		}
		else if (seq->array[mid]>x)
		{
			end = mid;
		}
		else
		{
			return mid;
		}
	}
}

void InsertSort(SeqList *seq)
{
	assert(seq);
	
	int i = 0;
	while (i <seq->size-1){
		int end = i;
		int tmp = seq->array[end + 1];
		while (end >= 0 && (seq->array[end] > tmp))
		{
			seq->array[end + 1] = seq->array[end];
			end--;
		}
		seq->array[end + 1] = tmp;
		i++;
	}
}

void Selectsort(SeqList *seq)
{
	int min = 0;
	for (int j = 0; j < seq->size; j++)
	{
		for (int i = j + 1; i < seq->size; i++)
		{
			if (seq->array[i] < seq->array[min])
			{
				min = i;
			}
		}
		int x = seq->array[j];
		seq->array[j] = seq->array[min];
		seq->array[min] = x;
	}
}

void BubbleSort(SeqList *seq)
{
	assert(seq);
	for (int i = 0; i < seq->size; i++)
	{
		for (int j = i; j < seq->size; j++)
		{
			if (seq->array[i] > seq->array[j])
			{
				int x = seq->array[i];
				seq->array[i] = seq->array[j];
				seq->array[j] = x;
			}
		}
	}
}


void RemoveAll(SeqList *seq, DataType x)
{
	int count = 0;
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] == x)
		{
			count++;
			seq->array[i] = seq->array[i + count];
			seq->size--;
			i--;
		}
		else{
			seq->array[i] = seq->array[i + count];
		}
		
	}
}

void Remove(SeqList *seq, DataType x)
{
	assert(seq);
	size_t pos = Find(seq, x);
	if (pos == -1)
	{
		printf("NO Found\n");
		return;
	}
	else
	{
		Erase(seq, pos);
	}
}
void Erase(SeqList *seq, size_t pos)
{
	assert(seq);
	assert(pos >= 0 && pos <= seq->size);
	seq->array[pos - 1] = 0;
}

int Find(SeqList *seq, DataType x)
{
	assert(seq);
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] == x)
		{
			return i+1;
		}
	}
	return -1;
}

void Insert(SeqList *seq, size_t pos, DataType x)//插入到其前面
{
	assert(seq);
	assert(pos >= 0 && pos <= seq->size);
	for (int i = seq->size; i >= pos; i--)
	{
		seq->array[i] = seq->array[i-1];
	}
	seq->array[pos-1] = x;
	seq->size++;

}

void PushFront(SeqList *seq, DataType x)//头插
{
	assert(seq);
	if (seq->size >= MAX_SIZE)
	{
		printf("SeqList is full");
		return;
	}
	else{
		int i = seq->size;
		while (i)
		{
			seq->array[i] = seq->array[i-1];
			i--;
		}
		seq->array[0] = x;
		seq->size++;
	}
}
void PopFront(SeqList *seq)
{
	assert(seq);
	if (seq->size == 0)
	{
		printf(" Seqlist is empty!");
		return;
	}
	else{
		int i = 0;
		while (i < (seq->size - 1))
		{
			seq->array[i] = seq->array[i+1];
			i++;
		}
		seq->size--;
	}
}

void PushBack(SeqList *seq, DataType x)//尾插
{
	assert(seq);
	if (seq->size >= MAX_SIZE)
	{
		printf("SeqList is full");
		return;
	}
	else{
		seq->array[seq->size++] = x;
	}
}

void PopBack(SeqList *seq)
{
	assert(seq);
	if (seq->size == 0)
	{
		printf(" Seqlist is empty!");
		return;
	}
	else{
		seq->size--;
	}
}

void InitSeqList(SeqList* seq)
{
	assert(seq);
	int len = 0;
	seq->size = 0;
	for (len = 0; len < MAX_SIZE; len++)
	{
		seq->array[len] = 0;
	}
}

void PrintSeqList(SeqList *seq)
{
	int i = 0;
	for (; i < seq->size; i++)
	{
		printf(" %d  ", seq->array[i]);
	}
	printf("\n");
}


