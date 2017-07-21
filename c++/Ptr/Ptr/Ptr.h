#include <iostream>
using namespace std;

template <class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr)
		:_ptr(ptr)
	{

	}
	~AutoPtr()
	{
		if (_ptr != NULL)
		{
			delete _ptr;
		}
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	T* GetPtr()
	{
		return _ptr;
	}
protected:
	T* _ptr;
};

int main()
{

}
