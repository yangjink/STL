#pragma once 


#include <iostream>
#include <queue>
#include <assert.h>
using namespace std;

template <class T>
class QStack
{
public:
	void Push(const T& x)
	{
		if ((q1.size() == 0) && (q2.size() == 0))//两个队列都为空
		{
			q1.push(x);
		}
		else if (q1.size() == 0)//否则跟在不为空的队列
		{
			q2.push(x);
		}
		else
		{
			q1.push(x);
		}
	}
	void Pop()
	{
		if ((q1.size() == 0) && (q2.size() == 0))
		{
			cout << "数据为空"<<endl;
			return;
		}
		else if (q1.size() == 0)
		{
			Move(q2, q1);
		}
		else
		{
			Move(q1, q2);
		}
	}

	T& Top() 
	{
		if ((q1.size() == 0) && (q2.size() == 0))
		{
			assert(-1);
		}
		else if (q1.size() == 0)
		{
			return q2.back();
		}
		else
		{
			return q1.back();
		}
	}
	size_t Size()
	{
		return q1.size() + q2.size();
	}
	size_t Empty()
	{
		return q1.empty() && q2.empty();
	}
protected:
	void Move(queue<T>& q,queue<T>& nq)//null_queue
	{
		assert(q.size());
		int size = q.size();
		int tmp = 0;
		while (size > 1)
		{
			tmp = q.front();
			q.pop();
			nq.push(tmp);

			size--;
		}
		q.pop();
	}
protected:
	queue<T> q1;
	queue<T> q2;
};


int main()
{
	QStack<int> s1;

	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);


	s1.Pop();
	s1.Pop();
	s1.Push(5);
	cout << s1.Size() << endl;
	cout << s1.Top() << endl;
	
	s1.Pop();
	return 0;
}