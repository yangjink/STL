#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>

#define max_name 10  
#define max_tele 12  
#define max_addr 30  
#define max_sex 10  
#define contact_max 1    
#define ADSIZE 5   

typedef struct Peo
{
	char name[max_name];
	char sex[max_sex];
	int age;
	char tele[max_tele];
	char addr[max_addr];

}Peo;

typedef struct Contact
{

	Peo *contact;
	int sz;
	int capacity;
}Con, *pcon;

void check(pcon con)
{
	if ((con->sz) >= (con->capacity))
	{
		con->contact = (Peo*)realloc(con->contact, (con->capacity + ADSIZE)*sizeof(Peo));
		if (con->contact == NULL)
		{
			printf("error");
			exit(1);
		}
		con->capacity = con->capacity + ADSIZE;
	}
}
void _add(pcon _con)
{
	check(_con);
	printf("�������֣�");
	scanf("%s", _con->contact[_con->sz].name);
	printf("�����Ա�");
	scanf("%s", _con->contact[_con->sz].sex);
	printf("�������䣺");
	scanf("%d", &_con->contact[_con->sz].age);
	printf("����绰��");
	scanf("%s", _con->contact[_con->sz].tele);
	printf("�����ַ: ");
	scanf("%s", _con->contact[_con->sz].addr);
	_con->sz++;
	printf("��ӳɹ�\n");
}

void _dis(const pcon _con)
{
	int i = 0;
	if (_con->sz <= 0)
	{
		printf("�绰��Ϊ��\n");
		return;
	}
	printf("%10s\t%5s\t%3s\t%12s\t%10s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (; i < _con->sz; i++)
	{
		printf("%10s\t%5s\t%3d\t%12s\t%10s\n",
			_con->contact[i].name,
			_con->contact[i].sex,
			_con->contact[i].age,
			_con->contact[i].tele,
			_con->contact[i].addr);
	}
}

void init_contact(pcon _con)
{
	_con->sz = 0;
	_con->contact = (Peo*)malloc(contact_max*sizeof(Peo));
	if (NULL == _con->contact)
	{
		printf("out of memory");
		exit(1);
	}
	memset(_con->contact, 0, contact_max*sizeof(Peo));
	_con->capacity = contact_max;

}

int find_entry(pcon _con, char *find_name) 
{
	int i = 0;
	for (; i < _con->sz; i++)
	{
		if (strcmp(find_name, _con->contact[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void _del(pcon _con)
{
	int pos = 0;
	int i = 0;
	char name[max_name];
	if (_con->sz <= 0)
	{
		printf("�绰��Ϊ��!\n");
		return;
	}
	printf("����Ҫɾ���˵����֣� ");
	scanf("%s", name);

	pos = find_entry(_con, name);
	if (pos == -1)
	{
		printf("������");
		return;
	}
	for (i = pos; i < _con->sz - 1; i++)
	{
		_con->contact[i] = _con->contact[i + 1];
	}

	_con->sz--;
	printf("ɾ���ɹ�\n");
}

void  view(pcon _con, int pos)
{
	if (pos == -1)
	{
		printf("û�������ϵ�ˣ�\n");
		return;
	}
	printf("%10s\t%5s\t%3s\t%12s\t%10s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	printf("%10s\t%5s\t%3d\t%12s\t%10s\n",
		_con->contact[pos].name,
		_con->contact[pos].sex,
		_con->contact[pos].age,
		_con->contact[pos].tele,
		_con->contact[pos].addr);
}
void _search(pcon _con)
{
	int pos = 0;
	char name[max_name];
	printf("�������֣�");
	scanf("%s", name);
	pos = find_entry(_con, name);
	view(_con, pos);
}


void _mod(pcon _con)
{

	int pos = 0;
	char name[max_name];

	printf("�༭��ϵ��\n");
	printf("�������֣�");
	scanf("%s", name);

	pos = find_entry(_con, name);
	if (pos == -1)
	{
		printf("�绰��û�������ϵ�ˣ�\n");
		return;
	}
	view(_con, pos);

	printf("�Ա�\t");
	scanf("%s", _con->contact[pos].sex);
	printf("���䣺\t");
	scanf("%d", &_con->contact[pos].age);
	printf("�绰��\t");
	scanf("%s", _con->contact[pos].tele);
	printf("��ַ: \t");
	scanf("%s", _con->contact[pos].addr);
	printf("�༭�ɹ���\n");
}
void _clr(pcon _con)
{
	_con->sz = 0;
	memset(_con->contact, 0, contact_max*sizeof(Peo));
}
void _sort(pcon _con)
{
	int i = 0;
	int j = 0;
	if (_con->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	for (i = 0; i < _con->sz; i++)
	{
		for (j = 0; j < _con->sz - 1 - i; j++)
		{
			if (strcmp(_con->contact[j].name, _con->contact[j + 1].name)>0)
			{
				Peo  tmp = _con->contact[j];
				_con->contact[j] = _con->contact[j + 1];
				_con->contact[j + 1] = tmp;
			}
		}
	}
	return;
}

enum op
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MOD,
	SHOW,
	SORT,
	CLR
};

void menu()
{
	printf("*******************************\n");
	printf("****  1.add      2.del     ****\n");
	printf("****  3.search   4. modify ****\n");
	printf("****  5.show      6.sort    ****\n");
	printf("****  7.clear    0.exit    ****\n");
	printf("*******************************\n");
}
int main()
{
	int input = 1;
	Con My_con;
	init_contact(&My_con);

	while (input)
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			_add(&My_con);
			break;
		case DEL:
			_del(&My_con);
			break;
		case SEARCH:
			_search(&My_con);
			break;
		case MOD:
			_mod(&My_con);
			break;
		case SHOW:
			_dis(&My_con);
			break;
		case SORT:
			_sort(&My_con);
			break;
		case CLR:
			_clr(&My_con);
			break;

		default:
			printf("ѡ�����");
			break;
		}
	}
	return 0;
}
