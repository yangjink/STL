//#pragma once
//
//#include <map>
//#include <set>
//#include <string>
//
////template<class K, class V>
////struct pair
////{
////	K first;
////	V second;
////
////	pair(const K& key, const V& value)
////		:first(key)
////		,second(value)
////	{}
////};
//
////template<class K, class V>
////pair<K, V> make_pair(const K& k, const V& v)
////{
////	return pair<K, V>(k, v);
////}
//
//void PrintMap(const map<string, string>& dict)
//{
//	map<string, string>::const_iterator dictIt = dict.begin();
//	while (dictIt != dict.end())
//	{
//		cout<<(*dictIt).first<<":"<<dictIt->second<<endl;
//		++dictIt;
//	}
//	cout<<endl;
//}
//
//void TestMap()
//{
//	// operator[] ->插入、修改
//	// insert -> 插入、查找、和修改
//	// erase ->删除
//	pair<map<string, string>::iterator, bool> ret_pr;
//	map<string, string> dict;
//	dict["sort"] = "排序";
//	dict["insert"] = "插入";
//	dict["sort"] = "xxx";
//
//	//dict.insert(pair<string, string>("sort", "排序"));
//	//dict.insert(pair<string, string>("insert", "插入"));
//	//ret_pr = dict.insert(pair<string, string>("left", "左边"));
//	//ret_pr = dict.insert(pair<string, string>("left", "剩余"));
//	////ret_pr.first->second = "剩余";
//	//dict["left"] = "剩余";
//
//
//	PrintMap(dict);
//
//	map<string, string>::iterator ret = dict.find("left1");
//	if (ret != dict.end())
//	{
//		dict.erase(ret);
//	}
//	else
//	{
//		cout<<"没有找到"<<endl;
//	}
//
//	PrintMap(dict);
//
//
//	string fruits[] = {"苹果","葡萄","苹果","葡萄","香蕉", "西瓜","西瓜","西瓜","西瓜","西瓜","西瓜","西瓜","西瓜","苹果", "苹果", "苹果","苹果"};
//	// topk
//	
//	map<string, int> countMap;
//	for (size_t i = 0; i < sizeof(fruits)/sizeof(fruits[0]); ++i)
//	{
//		/*map<string, int>::iterator ret = countMap.find(fruits[i]);
//		if (ret != countMap.end())
//		{
//			ret->second++;
//		}
//		else
//		{
//			countMap.insert(make_pair(fruits[i], 1));
//		}*/
//		
//
//	/*	pair<map<string, int>::iterator, bool> pr =
//			countMap.insert(make_pair(fruits[i], 1));
//		if (pr.second == false)
//			pr.first->second++;*/
//
//		/*V& operator[](const K& key)
//		{
//			return (*((this->insert(make_pair(k,mapped_type()))).first)).second;
//		}*/
//
//		countMap[fruits[i]]++;
//	}
//
//	// 1.make_heap
//	// 2.优先级队列
//	// 3.sort
//}


#pragma once

#include <map>
#include <set>
#include <string>

//template<class K, class V>
//struct pair
//{
//	K first;
//	V second;
//
//	pair(const K& key, const V& value)
//		:first(key)
//		,second(value)
//	{}
//};

//template<class K, class V>
//pair<K, V> make_pair(const K& k, const V& v)
//{
//	return pair<K, V>(k, v);
//}

void PrintMap(const map<string, int>& dict)
{
	map<string, int>::const_iterator dictIt = dict.begin();
	while (dictIt != dict.end())
	{
		cout<<(*dictIt).first<<":"<<dictIt->second<<endl;
		++dictIt;
	}
	cout<<endl;
}

#include <algorithm>
#include <vector>

class AA
{
public:
	explicit AA(int a = 10)
	{

	}
};

void TestMap()
{
	string fruits[] = {"苹果","葡萄","苹果","葡萄","香蕉", "西瓜","西瓜","西瓜","西瓜","西瓜","西瓜","西瓜","西瓜","苹果", "苹果", "苹果","苹果"};
	// topk
	
	map<string, int> countMap;
	for (size_t i = 0; i < sizeof(fruits)/sizeof(fruits[0]); ++i)
	{
		countMap[fruits[i]]++;
	}

	PrintMap(countMap);

	// 1.make_heap
	// 2.优先级队列
	// 3.sort

	vector<map<string, int>::iterator> v;
	map<string, int>::iterator countIt = countMap.begin();
	while (countIt != countMap.end())
	{
		v.push_back(countIt);
		++countIt;
	}

	struct Compare
	{
		bool operator()(map<string, int>::iterator l, map<string, int>::iterator r)
		{
			return l->second > r->second;
		}
	};

	sort(v.begin(), v.end(), Compare());


	map<string, string> dict;
	// 1.插入
	// 2.修改
	// 3.查
	dict["插入"];
	dict["插入"] = "insert";
	dict["sort"] = "排序";
	dict["插入"] = "insert";
	cout<<dict["sort"]<<endl;
}

void TestMutilMap()
{
	typedef multimap<string, string> Dict;
	typedef multimap<string, string>::iterator DictIt;

	Dict dict;
	dict.insert(make_pair("1", "左边"));
	dict.insert(make_pair("2", "左边"));
	dict.insert(make_pair("2", "左边"));
	dict.insert(make_pair("left", "左边1"));
	dict.insert(make_pair("left", "剩余"));
	dict.insert(make_pair("left", "左边2"));

	DictIt it = dict.find("left");
	while (it != dict.end() && it->first == "left")
	{
		cout<<it->second<<endl;
		++it;
	}
}

#include <set>

// 1.判断一个对象在不在一个集合里面
// 2.排序
// 3.去重

void TestSet()
{
	multiset<int> s1;
	s1.insert(4);
	s1.insert(9);
	s1.insert(2);
	s1.insert(1);
	s1.insert(0);
	s1.insert(0);
	s1.insert(0);
	s1.insert(0);


	multiset<int>::iterator it1 = s1.begin();
	while(it1 != s1.end())
	{
		cout<<*it1<<" ";
		++it1;
	}
	cout<<endl;
}