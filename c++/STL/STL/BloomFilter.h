#pragma once
#include "BitSet.h"

struct __HashFunc1
{
	size_t BKDRHash(const char *str)  
	{  
		register size_t hash = 0;  
		while (size_t ch = (size_t)*str++)  
		{         
			hash = hash * 131 + ch;      
		}  
		return hash;  
	}  

	size_t operator()(const string& s)
	{
		return BKDRHash(s.c_str());
	}
};

struct __HashFunc2
{
	size_t SDBMHash(const char *str)  
	{  
		register size_t hash = 0;  
		while (size_t ch = (size_t)*str++)  
		{  
			hash = 65599 * hash + ch;         
			//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
		}  
		return hash;  
	}  

	size_t operator()(const string& s)
	{
		return SDBMHash(s.c_str());
	}
};

struct __HashFunc3
{
	size_t RSHash(const char *str)  
	{  
		register size_t hash = 0;  
		size_t magic = 63689;     
		while (size_t ch = (size_t)*str++)  
		{  
			hash = hash * magic + ch;  
			magic *= 378551;  
		}  
		return hash;  
	}  

	size_t operator()(const string& s)
	{
		return RSHash(s.c_str());
	}
};

struct __HashFunc4
{
	size_t APHash(const char *str)  
	{  
		register size_t hash = 0;  
		size_t ch;  
		for (long i = 0; ch = (size_t)*str++; i++)  
		{  
			if ((i & 1) == 0)  
			{  
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));  
			}  
			else  
			{  
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));  
			}  
		}  
		return hash;  
	}  

	size_t operator()(const string& s)
	{
		return APHash(s.c_str());
	}
};

struct __HashFunc5
{
	size_t JSHash(const char *str)  
	{  
		if(!*str)        // 这是由本人添加，以保证空字符串返回哈希值0  
			return 0;  
		register size_t hash = 1315423911;  
		while (size_t ch = (size_t)*str++)  
		{  
			hash ^= ((hash << 5) + ch + (hash >> 2));  
		}  
		return hash;  
	}  

	size_t operator()(const string& s)
	{
		return JSHash(s.c_str());
	}
};

template<class K = string,
class HashFunc1 = __HashFunc1,
class HashFunc2 = __HashFunc2,
class HashFunc3 = __HashFunc3,
class HashFunc4 = __HashFunc4,
class HashFunc5 = __HashFunc5>
class BloomFilter
{
public:
	// n表示存储n个key
	BloomFilter(size_t n)
		:_bs(10*n)
		,_range(10*n)
	{}

	void Set(const K& key)
	{
		size_t hash1 = HashFunc1()(key);
		size_t hash2 = HashFunc2()(key);
		size_t hash3 = HashFunc3()(key);
		size_t hash4 = HashFunc4()(key);
		size_t hash5 = HashFunc5()(key);
		
		_bs.Set(hash1 % _range);
		_bs.Set(hash2 % _range);
		_bs.Set(hash3 % _range);
		_bs.Set(hash4 % _range);
		_bs.Set(hash5 % _range);
	}

	bool Test(const K& key)
	{
		size_t hash1 = HashFunc1()(key);
		if (_bs.Test(hash1%_range) == false)
			return false;

		size_t hash2 = HashFunc2()(key);
		if (_bs.Test(hash2%_range) == false)
			return false;

		size_t hash3 = HashFunc3()(key);
		if (_bs.Test(hash3%_range) == false)
			return false;

		size_t hash4 = HashFunc4()(key);
		if (_bs.Test(hash4%_range) == false)
			return false;

		size_t hash5 = HashFunc5()(key);
		if (_bs.Test(hash5%_range) == false)
			return false;

		return true; // 可能存在误判
	}

protected:
	BitSet _bs;
	size_t _range;
};


void TestBloomFilter()
{
	BloomFilter<> bf(100);
	string url1 = "http://www.cplusplus.com/1";
	string url2 = "http://www.cplusplus.com/2";
	string url3 = "http://www.cplusplus.com/3";
	string url4 = "http://www.cplusplus.com/4";
	string url5 = "http://www.cplusplus.com/5";
	string url6 = "http://www.cplusplus.com/6";

	bf.Set(url1);
	bf.Set(url2);
	bf.Set(url3);
	bf.Set(url4);
	bf.Set(url5);
	bf.Set("bitset");
	bf.Set("peter");
	bf.Set("pxxxxxxxxxx");

	cout<<"url1?"<<bf.Test(url1)<<endl;
	cout<<"url2?"<<bf.Test(url2)<<endl;
	cout<<"url3?"<<bf.Test(url3)<<endl;
	cout<<"url4?"<<bf.Test(url4)<<endl;
	cout<<"url5"<<bf.Test(url5)<<endl;
	cout<<"url6?"<<bf.Test(url6)<<endl;
	cout<<"peter?"<<bf.Test("peter")<<endl;
	cout<<"peter son?"<<bf.Test("peter son")<<endl;
}

//template<class K>
//class BloomFilter
//{
//public:
//	BloomFilter(size_t N)
//	{
//		_bs.resize(N*5*2);
//	}
//
//	void Set(const K& key)
//	{
//		_bs[hash1]++;
//	}
//
//	void Reset()
//	{
//		_bs[hash1]--;
//	}
//protected:
//	vector<unsigned short> _bs;
//};