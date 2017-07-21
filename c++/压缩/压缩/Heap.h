#pragma once


template <class T>
struct Less
{
	bool operator()(const T& l, const T& r) const
	{
		return l->_w._count <= r->_w._count;
	}
};
template <class T>
struct Greater
{
	bool operator()(const T& l, const T& r) const
	{
		return l->_w._count >= r->_w._count;
	}
};
template <class T, class Compare = Less<T>>
//template <class T>
class Heap
{
public:
	Heap()
	{}
	Heap( T* a, size_t size)
	{
		_a.reserve(size);
		for (size_t i = 0; i < size; ++i)
		{
			_a.push_back(a[i]);
		}
		for (int i = (_a.size() - 2) / 2; i >= 0;--i)
		_AdjustDown(i);
	}
	size_t Size()
	{
		return _a.size();
	}
	void Push(const T& x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size() - 1);
	}
	void Pop()
	{
		assert(!_a.empty());
		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();
		_AdjustDown(0);
	}
	const T& Top() const
	{
		return _a[0];
	}
protected:
	void _AdjustDown(int root)
	{
		Compare comFunc;
		int parent = root;
		size_t child = root * 2 + 1;
		while (child < _a.size())
		{
			if (child + 1 < _a.size() && comFunc(_a[child + 1],_a[child]))
			{
				++child;
			}
			if (comFunc(_a[child] , _a[parent]))
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}
	void _AdjustUp(int child)
	{
		Compare comFunc;
		int parent = (child - 1) >> 1;
		while (child > 0)
		{
			if (comFunc(_a[child], _a[parent]))
			//if (_a[child] >= _a[parent])
			{
				swap(_a[child], _a[parent]);
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
			{
				break;
			}
		}
	}
protected:
	vector<T> _a;
};


//int main()
//{
//	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
//	Heap<int> h1(a,sizeof(a)/sizeof(a[0]));
//	return 0;
//}