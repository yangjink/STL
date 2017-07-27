#pragma once  

namespace First
{
	enum State
	{
		EMPTY,//¿Õ
		EXIST,//´æÔÚ
		DELETE,//É¾³ý
	};

	template <class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		State _s;

		HashNode()
			:_s(EMPTY)
		{}
	};

	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};
	template<>
	struct HashFunc<string>
	{
		size_t operator()(const string& key)
		{
			return BKDRHash(key.c_str());
		}
		static size_t BKDRHash(const char* str)
		{
			unsigned int seed = 131;// 31 131 1313 13131 131313
			unsigned int hash = 0;
			while (*str)
			{
				hash = hash * seed + (*str++);
			}
			return(hash & 0x7FFFFFFF);
		}
	};
	template <class K, class V, class HashFunc = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;

	public:
		HashTable()
			:_size(0)
		{}

		HashTable(size_t n)
			:_size(0)
		{
			_tables.resize(n);
		}

		pair<Node*, bool> Insert(const pair<K, V>& kv)
		{
			_Check();
			size_t index = _HashFunc(kv.first);
			while (_tables[index]._s == EXIST)
			{
				if (_tables[index]._kv.first == kv.first)
					return make_pair(&_tables[index], false);
				index++;
				if (index == _tables.size())
				{
					index = 0;
				}
			}

			_tables[index]._kv = kv;
			_tables[index]._s = EXIST;
			++_size;
			return make_pair(&_tables[index], true);
		}

		V& operator[](const K& key)
		{
			pair<Node*, bool> ret = Insert(make_pair(key, V()));
			return ((ret.first)->_kv).second;
		}
		Node* Find(const K& key)
		{
			size_t index = _HashFunc(key);

			while (_tables[index]._s != EMPTY)
			{
				if (_tables[index]._kv.first == key)
				{
					if (_tables[index]._s == EXIST)
						return &_tables[index];
					else
						return NULL;
				}
				if (index == _tables.size())
					index = 0;
				++index;
			}
			return NULL;
		}
		bool Romove(const K& key)
		{
			Node* node = Find(key);
			if (node)
			{
				node->_s = DELETE;
				--size;
				return true;
			}
			else
			{
				return false;
			}
		}
		size_t GetSize()
		{
			return _size;
		}
	protected:

		size_t _HashFunc(const K& key)
		{
			HashFunc hf;
			return hf(key) % _tables.size();
			//return key % _tables.size();
		}


		void _Check()
		{
			const int _PrimeSize = 28;
			static const unsigned long _PrimeList[_PrimeSize] =
			{
				53ul, 97ul, 193ul, 389ul, 769ul,
				1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
				49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
				1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
				50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
				1610612741ul, 3221225473ul, 4294967291ul
			};
			static int num = 0;
			if (_tables.size() == 0)
			{
				_tables.resize(_PrimeList[num]);
			}
			else if (_size * 10 / _tables.size() == 7)
			{
				size_t newsize = _PrimeList[++num];
				_tables.resize(newsize);
				HashTable<K, V> newHT(newsize);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._s == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
				}
				_Swap(newHT);
			}
		}
		void _Swap(HashTable<K, V>& ht)
		{
			swap(_size, ht._size);
			_tables.swap(ht._tables);
		}
	protected:
		vector<Node> _tables;
		size_t _size;
	};

	int main()
	{
		int a[] = { 89, 18, 49, 58, 9 };
		HashTable<int, int, HashFunc<int>> ht;

		for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
		{
			ht.Insert(make_pair(a[i], i));
		}
		for (size_t i = 0; i < 777; ++i)
		{
			ht.Insert(make_pair(i, i));
		}
		ht.Insert(make_pair(10, 1));
		ht.Insert(make_pair(12, 1));
		ht.Insert(make_pair(13, 1));
		ht.Insert(make_pair(14, 1));
		ht.Insert(make_pair(15, 1));
		ht.Insert(make_pair(10, 1));
		ht.Insert(make_pair(10, 1));
		ht[10] = 3;

		HashTable<string, string> dict;
		//dict["left"] = "×ó±ß";
		dict.Insert(make_pair("aa", "bb"));
		dict["aa"] = "cc";
		dict["left"] = "×ó±ß";
		return 0;
	}
}

namespace Second
{
	template<class K,class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			,_next(NULL)
		{
		}
	};
	template <class K,class V,class HashFunc>
	class HashTable;

	template<class K,class V,class HashFunc,
	class ValueTypePtr,class ValueTypeRef>
	struct __HashIterator
	{
		typedef HashNode<K, V> Node;
		typedef pair<K, V> ValueType;
		typedef __HashIterator<K, V, HashFunc, ValueTypePtr, ValueTypeRef> Self;

		__HashIterator(Node* node, HashTable<K, V, HashFunc>* ht)
			:_node(node)
			, _ht(ht)
		{}
	};

	template<class K,class V,class HashFunc //== First::HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		typedef __HashIterator<K, V, HashFunc, pair<K, V>*, pair<K, V>&> Iterator;

		HashTable()
			:_size(0)
		{}
		pair<Node*, bool> Insert(const pair<K, V>& kv)
		{
			_Check();
			size_t index = _HashFunc(kv.first);
			

			++_size;
			return make_pair(&_tables[index], true);
		}
	protrcted:
		vector<Node*> _tables;
		size_t _size;
	};
}