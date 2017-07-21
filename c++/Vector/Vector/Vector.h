#pragma once
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

template <class T>
class Vector
{
public:
	Vector()
		:_data(NULL)
		, _size(0)
		, _capacity(0)
	{}
	Vector(T* _data, size_t size)
		:_data(new T[sizeof(T)*size])
		, _size(size)
		, _capacity(size)
	{}
	Vector(const Vector& v)
		:_data(new T[sizeof T*v._size])
		, _size(v._size)
		, _capacity(v._size)
	{
		memcpy(_data, v._data, sizeof T*_size);
	}
	void Swap(Vector& v)
	{
		swap(_size, v._size);
		swap(_capacity, v._capacity);
		swap(_data, v._data);
	}
	Vector& operator=(Vector v)
	{
		this->Swap(v);

		return *this;
	}
	void PushBack(const T& x)
	{
		_CheckCapacity();
		_data[_size++] = x;
	}
	void PopBack()
	{
		assert(_size > 0);
		--_size;
	}
	void Insert(size_t pos, const T& x)
	{
		assert(pos <= _size);
		_CheckCapacity();

		int end = _size - 1;
		while (end >= (int)pos)
		{
			_data[end + 1] = _data[end];
			--end;
		}

		_data[pos] = x;
		++_size;
	}

	void Erase(size_t pos)
	{
		assert(pos < _size);

		size_t begin = pos;
		while (begin < _size - 1)
		{
			_data[begin] = _data[begin + 1];
		}

		--_size;
	}
	T& operator[](size_t pos)
	{
		assert(pos < _size);

		return _data[pos];
	}
	~Vector()
	{
		if (_data)
		{
			delete[] _data;
			_size = _capacity = 0;
			_data = NULL;
		}
	}
	void Print()
	{
		for (size_t i = 0; i < _size; ++i)
		{
			cout << _data[i] << " ";
		}
		cout << endl;
	}
private:
	void _CheckCapacity()
	{
		if (_size >= _capacity)
		{
			size_t newCapacity = _capacity * 2 + 3;
			T* tmp = new T[newCapacity];
			if (_data)
			{
				/*for (size_t i = 0; i < _size; i++)
				{
					tmp[i] = _data[i];
				}*/
				memcpy(tmp, _data, sizeof(T)*_size);
				delete[] _data;
			}
			_data = tmp;
			
			_capacity = newCapacity;
		}
	}

protected:
	T* _data;
	size_t _size;
	size_t _capacity;
};
int main()
{
	Vector<int> aa;
	aa.PushBack(1);
	aa.PushBack(2);
	aa.PushBack(3);
	aa.PopBack();
	aa.Insert(2,6);
	aa.Erase(2);
	aa.Print();
	Vector<double> dd;
	dd.PushBack(1.11);
	dd.PushBack(2.22);
	dd.PushBack(3.33);
	dd[1] = 3;
	dd.Print();
	Vector<string> ss;
	ss.PushBack("a");
	ss.PushBack("b");
	ss.PushBack("c");
	ss.Print();

	string a("abcde");
	return 0;
}