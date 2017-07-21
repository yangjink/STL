#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <assert.h>

class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;

		assert(IsInvalid());
	}

	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool IsInvalid()
	{
		if (_year >= 0
			&& _month > 0 && _month < 13
			&& _day > 0 && _day <= GetMonthDays(_year, _month))
		{
			return true;
		}

		return false;
	}

	bool IsLeapYear(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return true;
		}

		return false;
	}

	int GetMonthDays(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];

		if (month == 2 && IsLeapYear(year))
		{
			day += 1;
		}

		return day;
	}

	// 拷贝构造、赋值运算符的重载、析构
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			else if (_month > d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
			}
		}
		return false;
	}
	bool operator<(const Date& d)
	{
		return !(*this >d || *this == d);
	}
	bool operator==(const Date& d)
	{
		if (_year == d._year)
		{
			if (_month == d._month)
			{
				if (_day == d._day)
				{
					return true;
				}
			}
		}
		return false;
	}
	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;
	}
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	// ++d == d.operator++(&d)
	Date& operator++()	 // 前置
	{
		int days = GetMonthDays(_year, _month);
		if (_day < days)
		{
			++_day;
		}
		else if (_day == days)
		{
			if (_month == 12)
			{
				_day = 1;
				_month = 1;
				_year++;
			}
			else
			{
				_day = 1;
				_month++;
			}
		}
		else
		{
			assert(false);
		}

		return *this;
	}

	// d++
	Date operator++(int) //后置
	{
		Date tmp(*this);

		//++(*this); // operator++(this);
		operator++();

		return tmp;
	}

	Date operator--()//前置
	{
		//int days = GetMonthDays(_year, _month);
		if (_day >0)
		{
			--_day;
		}
		else 
		{
			if (_month > 0)
			{
				_month--;
				_day = GetMonthDays(_year, _month);
			}
			else
			{
				_year--;
				_month = 12;
				_day = 31;
			}
		}
		return *this;
	}
	Date operator--(int)//前置
	{
		Date tmp(*this);
		operator--();

		return tmp;
	}

	Date operator+(int day)
	{
		Date tmp(*this);
		while (day)
		{

			++ tmp;
			day--;
		}
		tmp.Display();
		return tmp;
	}
	Date operator-(int day)
	{
		Date tmp(*this);
		while (day)
		{

			--tmp;
			day--;
		}
		tmp.Display();
		return tmp;
	}
	Date operator+=(int day)
	{
		while(day)
		{
			++ *this;
			day--;
		}
		return *this;
	}
	Date operator-=(int day)
	{
		while (day)
		{
			-- *this;
			day--;
		}
		return *this;
	}

private:
	int _year;
	int _month;
	int _day;

};
int main()
{
	Date d1(2017, 12, 30);
	Date d2(2016, 12, 30);
	/*if (d2 <= d1)
	{
		cout << "ddd";
	}*/
	d2 += 999999999;
	d2.Display();
	return 0;
}