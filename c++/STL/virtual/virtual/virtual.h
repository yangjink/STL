#include <iostream>
using namespace std;


class AA
{
public:
	virtual void f1()
	{
		cout << "AA-f1()" << endl;
	}
public:
	int _a;
};
class BB : public AA
{
public:
	virtual void f1()
	{
		cout << "BB-f1()" << endl;
	}
	virtual void f2()
	{
		cout << "BB-f2()" << endl;
	}
public:
	int _b;
};
class CC : public AA
{
public:
	virtual void f1()
	{
		cout << "CC-f1()" << endl;
	}
	virtual void f2()
	{
		cout << "CC-f2()" << endl;
	}
public:
	int _c;
};
class DD : public BB, public CC
{
public:
	virtual void f1()
	{
		cout << "DD-f1()" << endl;
	}
	virtual void f3()
	{
		cout << "DD-f3()" << endl;
	}
public:
	int _d;
};
int main()
{
	DD d;
	AA* ptr = new AA;
	//ptr = &d;
	d.f1();
	ptr->f1();

	return 0;
}