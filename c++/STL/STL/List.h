#pragma once
#include "Alloc.h"
#include "Construct.h"
#include "Iterator.h"

template<class T>
struct __ListNode
{
	T _data;
	__ListNode<T>* _next;
	__ListNode<T>* _prev;

	__ListNode(const T& x)
		:_data(x)
		,_next(NULL)
		,_prev(NULL)
	{}
};

template<class T, class Ref, class Ptr>
struct __ListIterator
{
	typedef __ListNode<T> Node;
	typedef __ListIterator<T, Ref, Ptr> Self;
	Node* _node;

	typedef T ValueType;
	typedef BidirectionalIteratorTag IteratorCategory;
	typedef Ptr Pointer;
	typedef Ref Reference;
	typedef ptrdiff_t DifferenceType;

	__ListIterator(Node* node)
		:_node(node)
	{}

	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	//operator--;
	Ref operator*()
	{
		return _node->_data;
	}
	//operator->;

	bool operator==(const Self& s)
	{
		return _node == s._node;
	}

	bool operator!=(const Self& s) const
	{
		return _node != s._node;
	}
};

template<class T, class alloc = Alloc>
class List
{
	typedef __ListNode<T> Node;
	typedef SimpleAlloc<Node, alloc> ListNodeAlloc;
public:
	typedef __ListIterator<T, T&, T*> Iterator;
	typedef __ListIterator<T, const T&, const T*> ConstIterator;
	typedef ReverseIterator<Iterator> ReverseIterator;

	List()
	{
		_head = BuyNode(T());
		_head->_next = _head;
		_head->_prev = _head;
	}

	~List()
	{
		Clear();

		DestoryNode(_head);
		_head = NULL;
	}

	void Clear()
	{
		Destory(Begin(), End()); // Îö¹¹º¯Êý

		Iterator it = Begin();
		while (it != End())
		{
			Node* del = it._node;
			++it;
			DestoryNode(del);
		}

		_head->_next = _head;
		_head->_prev =_head;
	}

	ReverseIterator RBegin()
	{
		return ReverseIterator(End());
	}

	ReverseIterator REnd()
	{
		return ReverseIterator(Begin());
	}


	Iterator Begin()
	{
		return _head->_next;
	}

	Iterator End()
	{
		return _head;
	}

	void PushBack(const T& x)
	{
		Node* tail = _head->_prev;

		Node* tmp = BuyNode(x);
		tail->_next = tmp;
		tmp->_prev = tail;

		tmp->_next = _head;
		_head->_prev = tmp;
	}

protected:
	Node* BuyNode(const T& x)
	{
		Node* node = ListNodeAlloc::Allocate();
		Construct(node, x);

		return node;
	}

	void DestoryNode(Node* ptr)
	{
		ListNodeAlloc::Deallocate(ptr);
	}
protected:
	Node* _head;
};

void TestList1()
{
	List<int> l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);

	List<int>::ReverseIterator rit = l1.RBegin();
	while (rit != l1.REnd())
	{
		cout<<*rit<<" ";
		++rit;
	}
	cout<<endl;
}

#include <string>
void TestList2()
{
	List<string> l2;
	l2.PushBack("1111");
	l2.PushBack("2222");
	l2.PushBack("3333");
	l2.PushBack("4444");

	List<string>::Iterator it = l2.Begin();
	while (it != l2.End())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}