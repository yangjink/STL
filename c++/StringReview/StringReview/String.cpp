#define _CRT_SECURE_NO_WARNINGS 1

#include "String.h"

int main()
{
	String s1("hello");
	cout << s1.GetString() << endl;
	cout << s1.GetSize() << endl;
	cout << s1.GetCapacity() << endl;
	String s2(s1);
	//s2._str;
	cout << s2.GetString()<< endl;
	cout << s2.GetSize() << endl;
	cout << s2.GetCapacity() << endl;
	String s3;
	s3 = s1;
	cout << s3.GetString() << endl;
	cout << s3.GetSize() << endl;
	cout << s3.GetCapacity() << endl;
	s3.PushBack('s');
	s3.PopBack();
	s3.Insert(2, 'w');
	s3 = (s1 + s2);
	cout << s3.GetString() << endl;
	cout << (s2 > s3)<<endl;
	cout << (s2 < s3) << endl;

	
	return 0;
}