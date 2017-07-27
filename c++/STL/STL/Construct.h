#pragma once

#include "TypeTraites.h"
#include "Iterator.h"

template<class T1, class T2>
inline void Construct(T1* p, const T2& x)
{
	new(p)T1(x);
}

template<class T>
inline void Destory(T* p)
{
	p->~T();
}

// Destory(Begin(), End()); // List<string>  List<int>
// Destory(_start, _finish); // Vector<string> List<int>

// O(N)
template <class ForwardIterator>
inline void __Destory(ForwardIterator first,
					  ForwardIterator last, __FalseType)
{
	while(first != last)
	{
		Destory(&(*first));
		++first;
	}

	cout<<"O(N)"<<endl;
}

// O(1)
template <class ForwardIterator>
inline void __Destory(ForwardIterator first,
					   ForwardIterator last, __TrueType)
{
	cout<<"O(1)"<<endl;
}

template <class ForwardIterator>
inline void Destory(ForwardIterator first, ForwardIterator last)
{
	__Destory(first, last, TypeTraits<IteratorTraits<ForwardIterator>::ValueType>::has_trivial_destructor());
}