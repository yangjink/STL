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
}Custom, *Customer;//模拟顾客属性  

typedef struct
{
	Customer front;//头  
	Customer rear;//尾  
}LinkQueue;//顾客队列化  

long TotalTime, TotalCustomer;//总时间,总客户量  
long OpenTime = 420, CloseTime = 1020;//银行开门时间和关门时间分别是420/60=7:00 1020/60=17:00 以24小时制计算  
LinkQueue q[4];//4个窗口  

//------函数列表------  

Bool InitQueue();
Bool EnQueue(int i, Customer c);
Bool DeQueue(int i, Customer c);
void OpenForDay();
void CompareTime(Custom c);
void Minimum(int *i);
void Bank_Simulation();
void Random(Customer c, long *StartTime);

//-------主函数------  

void main()
{
	Bank_Simulation();
}

void Bank_Simulation()
{
	Custom c;//定义一个顾客  
	long StartTime = 420;
	int i = 1;
	OpenForDay();
	Random(&c, &StartTime);
	printf("等待时间\t业务办理时间\t窗口号\t\t到达时间\t离开时间\n");
	while (c.Ltime<1020)  //银行没有下班
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

void Random(Customer c, long *StartTime)  //生成随机数
{
	srand((unsigned)time(NULL));
	do
	{
		c->OTime = rand() % 1020;  //插入事件
	} while (c->OTime<*StartTime);  //银行没有下班
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
	if (!t || q[i].front == q[i].rear)  //没有分配存储空间，且队头指针等于队尾指针
	{
		exit(OVERFLOW);  //存储分配失败
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
