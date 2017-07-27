#pragma once
#include <iostream>
using namespace std;


class Complex
{
	
public:
	
	Complex(float real = 0.0 , float imag = 0.0)
	:_imag(imag)
	, _real(real)
	{
	}
	bool operator<(const Complex& c)
	{
		if (_imag == 0)
		{
			if (_real < c._real)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			cout << "不能比较";
			return false;
		}
	}
	bool operator>(const Complex& c)
	{
		return !((*this == c) || (*this < c));
	}
	bool operator==(const Complex& c)
	{
		if ((_real == c._real) && (_imag == c._imag))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>=(const Complex& c)
	{
		return !(*this < c);
	}
	bool operator<=(const Complex& c)
	{
		return (*this < c) || (*this == c);
	}
	bool operator!=(const Complex& c)
	{
		return (*this == c);
	}
	Complex& operator++()
	{
		++_real;
		return *this;
	}
	Complex operator++(int)
	{
		Complex tmp(*this);
		++_real;
		return tmp;
	}
	Complex operator+(const Complex& c)
	{
		Complex tmp(*this);
		tmp._real = tmp._real + c._real;
		tmp._imag = tmp._imag + c._imag;
		return tmp;
	}
	Complex operator-(const Complex& c)
	{
		Complex tmp(*this);
		tmp._real = tmp._real - c._real;
		tmp._imag = tmp._imag - c._imag;
		return tmp;
	}
	Complex operator*(const Complex& c)
	{
		Complex tmp(*this);
		tmp._real = tmp._real * c._real - tmp._imag*c._imag;
		tmp._imag = tmp._real * c._imag + tmp._imag*c._real;
		return tmp;
	}
	Complex operator/(const Complex& c)
	{
		Complex tmp(*this);
		float a = tmp._real, b = tmp._imag, e = c._real, d = c._imag;
		tmp._real = (a*e + b*d) / (e*e + d*d);
		tmp._imag = (b*e - a*d) / (e*e + d*d);
		return tmp;
	}
	void print()
	{
		cout << _real << "+" << _imag << "i";
	}
private:
	float _imag;//虚部
	float _real;//实部
};