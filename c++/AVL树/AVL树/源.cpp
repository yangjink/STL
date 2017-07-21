#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>  
#include<stdlib.h>  
#include<time.h>  

#define TURE 1  
#define ERROR 0  
#define OVERFLOW -2  

typedef int Bool;
typedef struct Node
{
	long OTime;
	long Ltime;
	struct Node *next;
}Custom, *Customer;//ģ��˿�����  

typedef struct
{
	Customer front;//ͷ  
	Customer rear;//β  
}LinkQueue;//�˿Ͷ��л�  

long TotalTime, TotalCustomer;//��ʱ��,�ܿͻ���  
long OpenTime = 420, CloseTime = 1020;//���п���ʱ��͹���ʱ��ֱ���420/60=7:00 1020/60=17:00 ��24Сʱ�Ƽ���  
LinkQueue q[4];//4������  

//------�����б�------  

Bool InitQueue();
Bool EnQueue(int i, Customer c);
Bool DeQueue(int i, Customer c);
void OpenForDay();
void CompareTime(Custom c);
void Minimum(int *i);
void Bank_Simulation();
void Random(Customer c, long *StartTime);

//-------������------  

void main()
{
	Bank_Simulation();
}

void Bank_Simulation()
{
	Custom c;//����һ���˿�  
	long StartTime = 420;
	int i = 1;
	OpenForDay();
	Random(&c, &StartTime);
	printf("�ȴ�ʱ��\tҵ�����ʱ��\t���ں�\t\t����ʱ��\t�뿪ʱ��\n");
	while (c.Ltime<1020)  //����û���°�
	{
		CompareTime(c);
		Minimum(&i);
		EnQueue(i, &c);
		StartTime = c.OTime;
		printf("%d\t\t", i);
		printf("%d:%d\t\t", c.OTime / 60, c.OTime % 60);
		printf("%d:%d\n", c.Ltime / 60, c.Ltime % 60);
		getchar();
		Random(&c, &StartTime);
	}
	printf("The TotalTime=%-5.2f\n", (float)TotalTime);
	printf("The AnverageTime=%-5.2f\n", (float)TotalTime / TotalCustomer);
	printf("The Customernum=%d\n", TotalCustomer);
}

void OpenForDay()
{
	TotalTime = 0;
	TotalCustomer = 0;
	InitQueue();
}

void Random(Customer c, long *StartTime)  //���������
{
	srand((unsigned)time(NULL));
	do
	{
		c->OTime = rand() % 1020;  //�����¼�
	} while (c->OTime<*StartTime);  //����û���°�
}

Bool InitQueue()
{
	int i = 1;
	for (; i <= 4; i++)
	{
		q[i].rear = q[i].front = (Customer)malloc(sizeof(Custom));
		if (!q[i].front)
		{
			exit(OVERFLOW);
		}
		q[i].front->next = NULL;
	}
	return TURE;
}

void CompareTime(Custom c)
{
	int i;
	Custom t;
	Customer s;
	for (i = 1; i <= 4; i++)
	{
		s = q[i].front->next;
		while (s&&q[i].front != q[i].rear)
		{
			if (c.OTime >= s->Ltime)
			{
				DeQueue(i, &t);
				s = q[i].front->next;
			}
			else
			{
				s = s->next;
			}
		}
	}
}

Bool EnQueue(int i, Customer c)
{
	long DTime, WTime = 0;
	Customer t = (Customer)malloc(sizeof(Custom));
	if (!t)
	{
		exit(OVERFLOW);
	}
	if (q[i].front == q[i].rear)
	{
		WTime = 0;
	}
	else
	{
		WTime = q[i].rear->Ltime - q[i].rear->OTime;
	}
	srand((unsigned)time(NULL));
	do
	{
		DTime = rand() % 30;

	} while (DTime<10);
	c->Ltime = c->OTime + WTime + DTime;
	printf("%ld\t\t%ld\t\t", WTime, DTime);
	t->OTime = c->OTime;
	t->Ltime = c->Ltime;
	TotalTime += c->Ltime - c->OTime;
	t->next = NULL;
	q[i].rear->next = t;
	q[i].rear = t;
	TotalCustomer++;
	return TURE;
}

Bool DeQueue(int i, Customer c)
{
	Customer t = (Customer)malloc(sizeof(Custom));
	if (!t || q[i].front == q[i].rear)  //û�з���洢�ռ䣬�Ҷ�ͷָ����ڶ�βָ��
	{
		exit(OVERFLOW);  //�洢����ʧ��
	}
	t = q[i].front->next;
	c->OTime = t->OTime;
	c->Ltime = t->Ltime;
	q[i].front->next = t->next;
	if (q[i].rear == t)
	{
		q[i].rear = q[i].front;
	}
	free(t);
	return TURE;
}

void Minimum(int *i)
{
	int min, j, k, a[4];
	Customer s;
	for (j = 0; j<4; j++)
	{
		k = 0;
		s = q[j + 1].front;
		if (q[j + 1].front == q[j + 1].rear)
		{
			a[j] = 0;
		}
		else
		{
			while (s != q[j + 1].rear)
			{
				s = s->next;
				a[j] = ++k;
			}
		}
	}
	min = a[0];
	*i = 1;
	for (j = 0; j<4; j++)
	{
		if (min>a[j])
		{
			min = a[j];
			*i = j + 1;
		}
	}
}
