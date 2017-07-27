#pragma once

// bit_set
#include "Vector.h"

class BitSet
{
public:
	BitSet(size_t range)
	{
		_a.resize((range>>5) + 1 , 0);
	}

	void Set(size_t num)
	{
		size_t index = num>>5;
		size_t pos = num%32;

		_a[index] |= (1<<pos); 
	}

	void Reset(size_t num)
	{
		size_t index = num >> 5;
		size_t pos = num%32;

		_a[index] &= ~(1<<pos);
	}

	bool Test(size_t num)
	{
		size_t index = num >> 5;
		size_t pos = num%32;
		return _a[index] & (1<<pos);
	}

protected:
	vector<int> _a; 
};


void TestBitSet()
{
	BitSet s1(-1);

	s1.Set(1);
	s1.Set(8);
	s1.Set(33);
}
