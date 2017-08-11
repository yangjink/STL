#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
//warrior 战士 master 法师 archer 弓箭手 adventurer 冒险家
enum career{ad,wa,ma,ar};
class Player
{
public:
	virtual bool attack(Player &p) = 0;
	virtual bool specialatt(Player &p) = 0;
	virtual void isLeveUp() = 0;
	bool Death();
	bool isDead();//判断是否死亡;
	bool useBM(short bm);//使用药瓶
	bool useMM(short mm);//使用魔瓶
	char showRole();
protected:
	int HP, HPmax, MP, MPmax, AP, DP, speed, EXP, LV;//属性
	char name[10];
	career role;
	//物品栏
	
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
		cout << name << "已阵亡...." << endl;
		system("pause");
		death = 0;
	}
}
bool Player::useBM(short bm = 100)
{
	if (1)//背包还有
	{
		HP = HP + bm;
		if (HP > HPmax)
		{
			HP = HPmax;
		}
		cout << name << "使用了" << bm << ",生命值增加了" << bm<<endl;
		//包内数量-1
		system("pause");
		return 1;
	}
	cout << "对不起，您没有回复剂可以使用了。" << endl;
	system("pause");
	return 0;//使用回复剂操作失败
}
bool Player::useMM(short mm = 80)
{
	if (1)//背包还有
	{
		MP = MP + mm;
	}
}