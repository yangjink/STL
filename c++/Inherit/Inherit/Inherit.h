#include <iostream>
using namespace std;


class AA
{
public:
	int _aa;
};
class BB :virtual public AA
{
public:
	int _bb;
};
class CC :virtual public AA
{
public:
	int _cc;
};
class DD : public BB, public CC
{
public:
	int _dd;
};
int main()
{
	DD d;
	d._aa = 1;
	//d.CC::_aa = 2;
	d._bb = 3;
	d._cc = 4;
	d._dd = 5;
	BB b;
	b = d;
	return 0;
}