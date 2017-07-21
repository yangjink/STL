#pragma once
#include <string>
#include <iostream>
using namespace std;


template <class T>

struct ListNode
{
	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	ListNode(const T& x = T())
		:_data(x)
		, _next(NULL)
		, _prev(NULL)
	{
	}
};

template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	List()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}
	//List<int> a(b);
	List(const List<T>&  l)
	{
		_head = new Node();
		_head->_next = _head;
		_head->_prev = _head;
		Node* cur = l._head->_next;
		while (cur != l._head)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	//a = b
	/*List<T>& operator=(const List<T>& l)
	{
		if (this != &l)
		{
			Clear();
			Node* cur = l._head->_next;
			while (cur != l._head)
			{
				PushBack(cur->_data);
				cur = cur->_next;
			}
		}
		return *this;
	}*/
	List<T>& operator=( List<T> l)
	{
		swap(_head, l._head);
		return *this;
	}

	void Clear()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			Node* tmp = cur->_next;
			cur->_next = cur->_prev = NULL;
			delete cur;
			cur = tmp;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		Clear();
		delete _head;
		_head->_next = NULL;
		_head->_prev = NULL;
	}
	void PushBack(const T& x)
	{
		Node* tail = _head->_prev;
		Node* tmp = new Node(x);

		tmp->_prev = tail;
		tmp->_next = _head;

		tail->_next = tmp;
		_head->_prev = tmp;
	}
	void PopBack()
	{
		Node* tail = _head->_prev;
		Node* tmp = tail->_prev;
		if (tail != tmp)
		{
			_head->_prev = tmp;
			tmp->_next = _head;
			delete tail;
		}
		else
		{
			return;
		}
		
	}
	void PushFront(const T& x)
	{
		Node* tail = _head->_next;
		Node* tmp = new Node(x);
		tmp->_prev = _head;
		tmp->_next = tail;
		_head->_next = tmp;
		tail->_prev = tmp;
	}
	void PopFront()
	{
		Node* tmp = _head->_next;
		Node* next = tmp->_next;
		if (next != tmp)
		{
			_head->_next = next;
			next->_prev = _head;
			delete tmp;
		}
		else
		{
			return;
		}
		
	}
	
	Node* Find(const T& x)
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			if (cur->_data == x)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return NULL;
	}
	//pos Ç°²åÈë
	void Insert(Node* pos, const T& x)
	{
		if (pos)
		{
			Node* prev = pos->_prev;
			//Node* next = pos->_next;
			Node* tmp = new Node(x);

			prev->_next = tmp;
			tmp->_prev = prev;
			tmp->_next = pos;
			pos->_prev = tmp;
		}
		
	}
	void Erase(Node* pos)
	{
		if (pos || pos == _head)
		{
			Node* next = pos->_next;
			Node* prev = pos->_prev;
			next->_prev = prev;
			prev->_next = next;
		}
		
	}
	void Print()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}
protected:
	Node* _head;
};


void Test1()
{
	List<int> aa;
	aa.PushBack(1);
	aa.PushBack(2);
	aa.PushBack(3);
	aa.PushBack(4);
	aa.PopBack();
	aa.PopBack();
	aa.PopBack();
	aa.PopBack();
	aa.PopBack();
	aa.PushFront(2);
	aa.PopFront();
	aa.PopFront();
	aa.PushFront(2);
	aa.Insert(aa.Find(5), 3);
	aa.Insert(aa.Find(2), 3);
	aa.Erase(aa.Find(6));
	aa.Erase(aa.Find(2));
	aa.Print();
	
	//cout<<aa.Find(2)->_data;
}
void Test2()
{
	List<string> ss;
	ss.PushBack("s");
	ss.PushFront("d");
	ss.PushFront("a");
	ss.Print();

	List<string> aa;
	aa = ss;

	aa.Print();

}

int main()
{
	//Test1();
	Test2();
	return 0;
}
