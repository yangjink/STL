#pragma once

#include "Alloc.h"
#include "Construct.h"

template<class T, class alloc = Alloc>
class Vector
{
public:
	typedef SimpleAlloc<T, Alloc> DataAllocator;
	typedef T* Iterator;
	typedef const T* ConstIterator;
	typedef ReverseIterator<ConstIterator> ConstReverseIterator;
	typedef ReverseIterator<Iterator> ReverseIterator;
	
	Vector()
		:_start(NULL)
		,_finish(NULL)
		,_endOfStorage(NULL)
	{}

	~Vector()
	{
		Destory(_start, _finish);
		DataAllocator::Deallocate(_start, Capacity());
	}

	void PushBack(const T& x)
	{
		Expand();

		// T -> string
		Construct(_finish, x); // 拷贝构造
		++_finish;
	}

	void Resize(size_t n);
	void Reverse(size_t n);

	size_t Size()
	{
		return _finish-_start;
	}

	size_t Capacity()
	{
		return _endOfStorage - _start;
	}

	Iterator Begin()
	{
		return _start;
	}

	ReverseIterator RBegin()
	{
		return ReverseIterator(End());
	}

	ReverseIterator REnd()
	{
		return ReverseIterator(Begin());
	}

	Iterator End()
	{
		return _finish;
	}

	void Expand(size_t n = 0)
	{
		size_t size = Capacity();
		size_t newSize = 0;

		if (n == 0)
		{
			if (_finish == _endOfStorage)
			{
				newSize = (size == 0 ? 4 : size+size/2);
			}
			else
			{
				return;		
			}
		}
		else
		{
			if (n > Capacity())
			{
				newSize = n;
			}
			else
			{
				return;
			}
		}

		
		T* tmp = DataAllocator::Allocate(newSize);

		// 拷贝数据 -> 
		for (size_t i = 0; i < Size(); ++i)
		{
			Construct(tmp, _start[i]);
		}

		// 释放旧空间
		if(_start)
		{
			Destory(_start, _finish); // 析构
			DataAllocator::Deallocate(_start, Capacity());
		}

		// 更新
		_start = tmp;
		_finish = _start+size;
		_endOfStorage = _start + newSize;
	}

protected:
	Iterator _start;
	Iterator _finish;
	Iterator _endOfStorage;
};

void TestVector()
{
	Vector<int> v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);

	Vector<int>::ReverseIterator it = v1.RBegin();
	while(it != v1.REnd())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}
