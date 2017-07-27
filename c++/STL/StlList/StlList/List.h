#pragma once

#include <iostream>
using namespace std;


template <class T>
struct __ListNode
{
	__ListNode<T>* _prev;
	__ListNode<T>* _next;
	T _data;

	__ListNode(const T& x = T())//T()??
		:_data(x)
		, _prev(NULL)
		, _next(NULL)
	{

	}
};

template <class T,class Ref, class Ptr>
struct __ListIterator
{
	typedef __ListNode<T> Node;
	typedef __ListIterator<T, Ref, Ptr> Self;
	Node* _node;

	__ListIterator(Node* node)
		:_node(node)
	{
	}
	Ref operator*()
	{
		return _node->_data;
	}
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}
	 
};

template<class T>
class List
{
	typedef __ListNode<T> Node;
public:
	typedef __ListIterator<T, T&, T*> Iterator;//????
	List()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}
	void PushBack(const T& x)
	{
		Node* tmp = new Node(x);
		Node* tail = _head->_prev;

		tail->_next = tmp;
		tmp->_prev = tail;
		_head->_prev = tmp;
		tmp->_next = _head;
	}
	
	Iterator Begin()
	{
		return Iterator(_head->_next);
	}
	Iterator End()
	{
		return Iterator(_head->_prev);
	}

protected:
	Node* _head;
};

void Test()
{
	List<int> l;
	l.PushBack(0);
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);

	List<int>::Iterator it = l.Begin();
	while (it != l.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}