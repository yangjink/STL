#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
//warrior սʿ master ��ʦ archer ������ adventurer ð�ռ�
enum career{ad,wa,ma,ar};
class Player
{
public:
	virtual bool attack(Player &p) = 0;
	virtual bool specialatt(Player &p) = 0;
	virtual void isLeveUp() = 0;
	bool Death();
	bool isDead();//�ж��Ƿ�����;
	bool useBM(short bm);//ʹ��ҩƿ
	bool useMM(short mm);//ʹ��ħƿ
	char showRole();
protected:
	int HP, HPmax, MP, MPmax, AP, DP, speed, EXP, LV;//����
	char name[10];
	career role;
	//��Ʒ��
	
protected:
	bool death;
};
bool Player::Death()
{
	return death;
}
bool Player::isDead()
{
	if (HP <= 0)
	{
		cout << name << "������...." << endl;
		system("pause");
		death = 0;
	}
}
bool Player::useBM(short bm = 100)
{
	if (1)//��������
	{
		HP = HP + bm;
		if (HP > HPmax)
		{
			HP = HPmax;
		}
		cout << name << "ʹ����" << bm << ",����ֵ������" << bm<<endl;
		//��������-1
		system("pause");
		return 1;
	}
	cout << "�Բ�����û�лظ�������ʹ���ˡ�" << endl;
	system("pause");
	return 0;//ʹ�ûظ�������ʧ��
}
bool Player::useMM(short mm = 80)
{
	if (1)//��������
	{
		MP = MP + mm;
	}
}