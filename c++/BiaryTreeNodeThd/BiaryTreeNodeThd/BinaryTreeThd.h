#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

enum PointerTag {THREAD,LINK};

template <class T>
struct BinaryTreeNodeThd
{
	T _data;
	BinaryTreeNodeThd<T>* _left;
	BinaryTreeNodeThd<T>* _right;
	PointerTag _leftTag;
	PointerTag _rightTag;

	BinaryTreeNodeThd(const T& x)
		:_data(x)
		, _left(NULL)
		, _right(NULL)
		, _leftTag(LINK)
		, _rightTag(LINK)
	{
	}
};

template <class T>
class BinaryTreeThd
{
	typedef BinaryTreeNodeThd<T> Node;

public:
	BinaryTreeThd(T* a,size_t size,const T& invalid)
	{
		assert(a);
		size_t index = 0;
		_root = _SetUpTree(a, size, index, invalid);
	}

	~BinaryTreeThd()
	{

	}

	void InOrderThreading()//创建线索化
	{
		Node* prev = NULL;
		_InOrderThreading(_root, prev);
	}
	void InOrderThd()//遍历中序线索化
	{
		Node* cur = _root;
		while (cur)
		{
			while (cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			
			while (cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout << cur->_data << " ";
			}
			cur = cur->_right;
		}
		cout << endl;
	}

	void PrevOrderThreading()
	{
		Node* prev = NULL;
		_PrevOrderThreading(_root, prev);
	}

	void PrevOrderThd()
	{
		Node* cur = _root;
		while (cur)
		{

			while (cur->_leftTag == LINK)
			{
				cout << cur->_data << " ";
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			while (cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout << cur->_data << " ";
			}
			if (cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}
			else
			{
				cur = cur->_right;
			}
		}
		cout << endl;
	}
protected:
	Node* _SetUpTree(const T* a, size_t size, size_t& index, const T& invalid)
	{
		Node* tmp = NULL;
		if (index < size && a[index] != invalid)
		{
			tmp = new Node(a[index]);
			tmp->_left = _SetUpTree(a, size, ++index, invalid);
			tmp->_right = _SetUpTree(a, size, ++index, invalid);
		}
		return tmp;
	}

	void _InOrderThreading(Node* cur, Node*& prev)
	{
		if (cur == NULL)
			return;
		_InOrderThreading(cur->_left, prev);

		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}

		if (prev && prev->_right == NULL)
		{
			prev->_right = cur;
			prev->_rightTag = THREAD;
		}
		prev = cur;
		_InOrderThreading(cur->_right, prev);
	}
	void _PrevOrderThreading(Node* cur, Node*& prev)
	{
		if (cur == NULL)
			return;

		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}

		if (prev && prev->_right == NULL)
		{
			prev->_right = cur;
			prev->_rightTag = THREAD;
		}
		prev = cur;
		
		if (cur->_leftTag == LINK)
		_PrevOrderThreading(cur->_left, prev);
		if (cur->_rightTag == LINK)
		_PrevOrderThreading(cur->_right, prev);
	}

protected:
	Node* _root;
};

void Test1()
{
	int array[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	//int array[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTreeThd<int> t1(array, sizeof(array) / sizeof(array[0]), '#');
	t1.InOrderThreading();
	t1.InOrderThd();
	
	BinaryTreeThd<int> t2(array, sizeof(array) / sizeof(array[0]), '#');
	t2.PrevOrderThreading();
	t2.PrevOrderThd();
}
int main()
{
	Test1();
	return 0;
}