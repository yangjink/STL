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
//	// operator[] ->���롢�޸�
//	// insert -> ���롢���ҡ����޸�
//	// erase ->ɾ��
//	pair<map<string, string>::iterator, bool> ret_pr;
//	map<string, string> dict;
//	dict["sort"] = "����";
//	dict["insert"] = "����";
//	dict["sort"] = "xxx";
//
//	//dict.insert(pair<string, string>("sort", "����"));
//	//dict.insert(pair<string, string>("insert", "����"));
//	//ret_pr = dict.insert(pair<string, string>("left", "���"));
//	//ret_pr = dict.insert(pair<string, string>("left", "ʣ��"));
//	////ret_pr.first->second = "ʣ��";
//	//dict["left"] = "ʣ��";
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
//		cout<<"û���ҵ�"<<endl;
//	}
//
//	PrintMap(dict);
//
//
//	string fruits[] = {"ƻ��","����","ƻ��","����","�㽶", "����","����","����","����","����","����","����","����","ƻ��", "ƻ��", "ƻ��","ƻ��"};
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
//	// 2.���ȼ�����
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
	string fruits[] = {"ƻ��","����","ƻ��","����","�㽶", "����","����","����","����","����","����","����","����","ƻ��", "ƻ��", "ƻ��","ƻ��"};
	// topk
	
	map<string, int> countMap;
	for (size_t i = 0; i < sizeof(fruits)/sizeof(fruits[0]); ++i)
	{
		countMap[fruits[i]]++;
	}

	PrintMap(countMap);

	// 1.make_heap
	// 2.���ȼ�����
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
	// 1.����
	// 2.�޸�
	// 3.��
	dict["����"];
	dict["����"] = "insert";
	dict["sort"] = "����";
	dict["����"] = "insert";
	cout<<dict["sort"]<<endl;
}

void TestMutilMap()
{
	typedef multimap<string, string> Dict;
	typedef multimap<string, string>::iterator DictIt;

	Dict dict;
	dict.insert(make_pair("1", "���"));
	dict.insert(make_pair("2", "���"));
	dict.insert(make_pair("2", "���"));
	dict.insert(make_pair("left", "���1"));
	dict.insert(make_pair("left", "ʣ��"));
	dict.insert(make_pair("left", "���2"));

	DictIt it = dict.find("left");
	while (it != dict.end() && it->first == "left")
	{
		cout<<it->second<<endl;
		++it;
	}
}

#include <set>

// 1.�ж�һ�������ڲ���һ����������
// 2.����
// 3.ȥ��

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