#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "HashTable.h"
//#include <iostream>
//#include <string>
//using namespace std;
//
//void Swap(string& s, int first, int last)
//{
//	while ((first != last) && (first != --last)) {
//		swap(s[first],s[last]);
//		++first;
//	}
//}
//int main(){
//
//	string s = { "I like beijing." };
//	int begin = 0;
//	int end = s.size();
//	reverse(s.begin(), s.end());
//	for (int i = 0; i<end; i++)
//	{
//		if (s[i] == ' '){
//			Swap(s, begin, i);
//			begin = i + 1;
//		}
//
//	}
//	cout << s << endl;
//	return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;
//
//
//int main()
//{
//	char st1[100];
//	char st2[100];
//	gets(st1);
//	gets(st2);
//	string s1(st1);
//	string s2(st2);
//
//	for (int i = 0; i<s2.size(); i++)
//	{
//		for (int j = 0; j<s1.size(); j++)
//		{
//			if (s1[j] == s2[i]){
//				s1.erase(j, 1);
//				j--;
//			}
//		}
//	}
//	cout << s1 << endl;
//	return 0;
//}
