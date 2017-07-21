#pragma once
#include <time.h>

template <class T>
struct ComplexListNode
{
	ComplexListNode* _next;
	ComplexListNode* _random;

	T _data;

	ComplexListNode(const T& x)
		:_data(x)
		, _next(NULL)
		, _random(NULL)
	{}
};

template <class T>
class ComplexList
{
	typedef ComplexListNode<T> Node;
public:
	ComplexList()
		:_head(NULL)
	{
		srand((unsigned)time(NULL));
	}
	ComplexList( Node* head)
		:_head(head)
	{}
	/*ComplexList(const  ComplexList& l)
	{
		if (l == NULL)
			return;
	}*/
	ComplexList<T>& operator=(const ComplexList& l)
	{
		_head = l._head;
	}
	~ComplexList()
	{
		Node* cur = _head;
		while (cur)
		{
			Node* d1 = cur;
			cur = cur->_next;
			delete d1;
		}
		_head = NULL;
	}
	void PushFront(const T& x)
	{
		if (_head != NULL)
		{
			Node* tmp = new Node(x);
			tmp->_next = _head;
			int i = rand() % Size();
			Node* cur = _head;
			while (i)
			{
				cur = cur->_next;
				i--;
			}
			tmp->_random = cur;
			_head = tmp;
		}
		else
		{
			_head = new Node(x);
		}
	}
	size_t Size()
	{
		size_t count = 0;
		Node* cur = _head;
		while (cur)
		{
			count++;
			cur = cur->_next;
		}
		return count;
	}
	Node* ComplexListReplica()
	{
		_ReplicaNode(_head);
		_ConnectRandom(_head);
		return _PickComplexList(_head);
	}
protected:
	void _ReplicaNode(Node* head)
	{
		Node* cur = head;
		while (cur)
		{
			Node* Rcur = new Node(cur->_data);
			Rcur->_next = cur->_next;
			cur->_next = Rcur;

			cur = Rcur->_next;
		}
	}
	void _ConnectRandom(Node* head)
	{
		Node* cur = head;
		while (cur)
		{
			Node* Rcur = cur->_next;
			Node* tmp;
			if (cur->_random)
			{
				tmp = cur->_random;
				Rcur->_random = tmp->_next;
			}

			cur = Rcur->_next;
		}
	}
	Node* _PickComplexList(Node* head)
	{
		Node* cur = head;
		if (head == NULL)
		{
			return NULL;
		}
		Node* newhead = cur->_next;
		Node* next = newhead;
		while (next->_next)
		{
			cur->_next = next->_next;
			cur = cur->_next;

			next->_next = cur->_next;
			next = next->_next;
		}
		cur->_next = next->_next;
		return newhead;
	}
protected:
	Node* _head;
};


void Test1()
{
	ComplexList<int> l1;
	l1.PushFront(2);
	l1.PushFront(6);
	l1.PushFront(1);
	l1.PushFront(4);
	l1.PushFront(3);
	cout << l1.Size() << endl;
	ComplexList<int> l2 (l1.ComplexListReplica());



}