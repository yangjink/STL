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
		s1.push(x);//ֱ�ӷ���s1��
	}
	void Pop()
	{
		if (s2.size() == 0)
		{
			int count = s1.size();
			int tmp = 0;
			while (count != 0)//���s2Ϊ�յĻ����ͽ�s1������ȫ���Ƶ�s2��
			{
				tmp = s1.top();
				s1.pop();
				s2.push(tmp);

				count--;
			}
		}

		if (s2.size() == 0)
		{
			return;//˵��û������
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
			cout << "����Ϊ��"<<endl;
			assert(-1);
		}

	}
	T& Back()
	{
		if (!s1.empty())//���s1��Ϊ�գ���s1��top�������һ���Ž���������
		{
			return s1.top();
		}
		else if (!s2.empty())//s1Ϊ�գ����ٽ�s2�������ٴη���s1���������һ���Ž�����Ҳ����β����
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
