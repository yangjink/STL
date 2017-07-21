#pragma once

#include <iostream>
using namespace std;

template <class T>
class SymmetricMatrix
{
public:
	SymmetricMatrix(T* a, size_t n)
		_a(a),
		_n(n)
	{
			_a = new T[_n*(_n + 1) / 2];
	}
	~SymmetricMatrix()
	{
		delete[] _a;
	}
	T& Access(size_t i, size_t j);
	void Display();
protected:
	T* _a;
	size_t _n;
};


template <class T>
struct Triple
{

};


void TestSymmetricMatrix()
{
	int a[5][5] = 
	{
		{0,1,2,3,4},
		{1,0,1,2,3},
		{2,1,0,1,2},
		{3,2,1,0,1},
		{4,3,2,1,0},
	}
}