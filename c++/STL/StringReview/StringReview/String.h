#include <iostream>
using namespace std;


class String
{
public:
	String(const char*str = "")
		:_size (strlen(str))
		, _capacity(_size + 10)
	{
		_str = new char[_capacity];
		strcpy(_str, str);
	}
	//s2(s1)
	/*String(const String& s)
	{
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}*/
	void Swap(  String& b)
	{
		swap(_str, b._str);
		swap(_size, b._size);
		swap(_capacity, b._capacity);
	}
	String(const String& s)
		:_str(NULL)
	{
		String tmp(s._str);
		Swap(tmp);
	}
	//s2 = s1
	/*String& operator=(const String& s)
	{
		if (this != &s)
		{
			String tmp(s._str);
			swap(_str, tmp._str);
			return *this;
		}
	}*/
	String& operator=( String s)
	{
		Swap(s);
		
		return *this;
	}
	~String()
	{
		//cout << "~"<<endl;
		delete[] _str;
	}
	char* GetString()
	{
		return _str;
	}
	size_t GetSize()
	{
		return _size;
	}
	size_t GetCapacity()
	{
		return _capacity;
	}
	void CapacityJudge()
	{
		if ((_size + 1) != _capacity)
		{
			return;
		}
		else
		{
			_str = (char*)realloc(_str, _capacity * 2);
			_capacity = _capacity * 2;
		}
	}
	void PushBack(char ch)
	{
		CapacityJudge();
		_str[_size] = ch;
		_size += 1;
		_str[_size ] = '\0';
	}
	void PopBack()
	{
		_size -= 1;
		_str[_size] = '\0';
	}
	
	void Insert(size_t pos, char ch)//从0开始计位置
	{
		CapacityJudge();
		int i = _size + 1;
		for (; i>=pos; i--)
		{
			_str[i] = _str[i - 1];
		}
		_str[pos] = ch;
		_size++;
	}
	void Erase(size_t pos)//从0开始计位置
	{
		int i = pos;
		for (; i < _size; i++)
		{
			_str[i] = _str[i + 1];
		}
		_size--;
	}
	bool operator>(const String& s)
	{
		char* str1 = _str;
		char* str2 = s._str;
		while (*str1 && *str2)
			{
				if (*str1 > *str2)
				{
					return true;
				}
				else if (*str1 < *str2)
				{
					return false;
				}
				else
				{
					++str1;
					++str2;
				}
			}
			if (*str2)
			{
				return false;
			}
			else
			{
				return true;
			}
			if (*str1)
			{
				return true;
			}
			else if(*str2)
			{
				return false;
			}
			else
			{
				return true;
			}
	}
	bool operator<(const String& s)
	{
		return !(*this > s);
	}
	bool operator<=(const String& s)
	{
		return (*this < s) || (*this == s);
	}
	bool operator>=(const String& s)
	{
		return (*this > s) || (*this == s);
	}
	bool operator==(const String& s)
	{
		if (_size == s._size)
		{
			for (int i = 0; i <= _size; i++)
			{
				if (_str[i] != s._str[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	String operator+(const String& s)
	{
		String tmp(_str);
		int i = _size;
		while (i<(_size+s._size-1))
		{
			tmp.Insert(i, s._str[i-_size]);
			i++;
		}
		return tmp;
	}
	String& operator+=(const String& s)
	{
		int i = _size;
		while (i<(_size + s._size - 1))
		{
			Insert(i, s._str[i - _size]);
		}
		return *this;
	}
	//size_t Find(const char* sub);
	char& operator[](size_t pos) 
		{
			return _str[pos];
		}
    //顺序勿动
private:
	size_t _size;
	size_t _capacity;
	char* _str;
};

