#pragma once 
#include <map>
#include <string>

template <class K,class V>
void PrintMap(const map<K,V> printmap)
{
	map<K, V>::const_iterator it = printmap.begin();
	while (it != printmap.end())
	{
		cout << it->first << " " << (*it).second << endl;
		it++;
	}
}
void Test1()
{
	string fruits[] = { "ƻ��", "�㽶", "ƻ��", "ƻ��", "����", "����", "����", "ƻ��", "����", "ƻ��", "����", "����", "����", "����", "����", "�㽶", "����"};

	map<string, int> statisticsMap;

	for (int i = 0; i < sizeof(fruits) / sizeof(fruits[0]); i++)
	{
		//map<string, int>::iterator it = statisticsMap.find(fruits[i]);
		//
		//if (it != statisticsMap.end())
		//{
		//	it->second++;
		//}
		//else
		//{
		//	/*statisticsMap.insert(pair<string,int>(fruits[i],1));*/
		//	statisticsMap.insert(make_pair(fruits[i], 1));
		//}

		pair<map<string,int>::iterator, bool> Pair = statisticsMap.insert(make_pair(fruits[i],1));
		if (Pair.second == false)
		{
			(*Pair.first).second++;
		}
		//statisticsMap[fruits[i]]++;
		//(*((this->insert(make_pair(k, mapped_type()))).first)).second
	}
	PrintMap(statisticsMap);
}