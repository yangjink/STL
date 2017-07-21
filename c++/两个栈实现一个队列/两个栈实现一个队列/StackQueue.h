#pragma once

#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;


template <class T>
class SQueue
{
public:
	void Push(const T& x)
	{
		s1.push(x);//直接放入s1中
	}
	void Pop()
	{
		if (s2.size() == 0)
		{
			int count = s1.size();
			int tmp = 0;
			while (count != 0)//如果s2为空的话，就将s1的数据全部移到s2中
			{
				tmp = s1.top();
				s1.pop();
				s2.push(tmp);

				count--;
			}
		}

		if (s2.size() == 0)
		{
			return;//说明没有数据
		}
		s2.pop();
	}
	T& Front()
	{
		if (s2.size() != 0)
		{
			return s2.top();
		}
		else if (s1.size() != 0)
		{
			int count = s1.size();
			int tmp = 0;
			while (count != 0)
			{
				tmp = s1.top();
				s1.pop();
				s2.push(tmp);

				count--;
			}
			
			return s2.top();
		}
		else
		{
			cout << "队列为空"<<endl;
			assert(-1);
		}

	}
	T& Back()
	{
		if (!s1.empty())//如果s1不为空，则s1的top就是最后一个放进来的数据
		{
			return s1.top();
		}
		else if (!s2.empty())//s1为空，则再将s2的数据再次放入s1，这样最后一个放进来的也就是尾数据
		{
			int count = s2.size();
			int tmp = 0;
			while (count != 0)
			{
				tmp = s2.top();
				s2.pop();
				s1.push(tmp);

				count--;
			}
			return s1.top();
		}
		else
		{
			cout << "queue is empty!"<<endl;
			assert(-1);
		}
	}
	size_t Size()
	{
		return s1.size() + s2.size();
	}
	bool Empty() const
	{
		return s1.empty() || s2.empty();
	}
protected:
	stack<T> s1;
	stack<T> s2;
};


int main()
{
	SQueue<int> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	q1.Push(5);
	q1.Push(6);
	q1.Push(7);
	q1.Push(8);
	q1.Push(9);
	q1.Push(0);

	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
}
