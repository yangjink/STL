#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <assert.h>
//
//using namespace std;

//#include "Sort.h"


//void TestInsertionSort()
//{
//	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
//	Print(a,sizeof(a)/sizeof(a[0]));
//
//	InsertionSort(a, sizeof(a) / sizeof(a[0]));
//	Print(a, sizeof(a) / sizeof(a[0]));
//
//}
//void TestHeapSort()
//{
//	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
//	Print(a, sizeof(a) / sizeof(a[0]));
//
//	HeapSort(a, sizeof(a) / sizeof(a[0]));
//	Print(a, sizeof(a) / sizeof(a[0]));
//
//}
//void TestQuickSort()
//{
//	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
//	Print(a, sizeof(a) / sizeof(a[0]));
//
//	QuickSort(a, sizeof(a) / sizeof(a[0]));
//	Print(a, sizeof(a) / sizeof(a[0]));
//
//}
//struct test
//{
//	char a : 4;
//	char b : 2;
//	
//};
//int main()
//{
//	//TestInsertionSort();
//	//TestHeapSort();
//	//TestQuickSort();
//	test f;
//	f.a = 12;
//	f.b = 3;
//	
//	cout << (int)f.a << endl;
//	cout << (int)f.b<< endl;
//	
//}
//1111 1111 
//1111 1111 
//1111 1111 
//1111 1110
//
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/reader.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;

#include <fstream>
#include <string>
#include <assert.h>
#include <iostream>
#define psln(x) std::cout << #x " = " << (x) << std::endl

void testSimpleDoc() {
	using std::string;
	using std::ifstream;

	// read json content into string.
	string      stringFromStream;
	ifstream    in;
	in.open("test.json", ifstream::in);
	if (!in.is_open())
		return;
	string line;
	while (getline(in, line)) {
		stringFromStream.append(line + "\n");
	}
	in.close();

	// ---------------------------- read json --------------------
	// parse json from string.
	using rapidjson::Document;
	Document doc;
	doc.Parse<0>(stringFromStream.c_str());
	if (doc.HasParseError()) {
		rapidjson::ParseErrorCode code = doc.GetParseError();
		psln(code);
		return;
	}

	// use values in parse result.
	using rapidjson::Value;
	Value & v = doc["dictVersion"];
	if (v.IsInt()) {
		psln(v.GetInt());
	}

	Value & contents = doc["content"];
	if (contents.IsArray()) {
		for (size_t i = 0; i < contents.Size(); ++i) {
			Value & v = contents[i];
			assert(v.IsObject());
			if (v.HasMember("key") && v["key"].IsString()) {
				psln(v["key"].GetString());
			}
			if (v.HasMember("value") && v["value"].IsString()) {
				psln(v["value"].GetString());
			}
		}
	}
	// ---------------------------- write json --------------------
	psln("add a value into array");

	Value item(Type::kObjectType);
	item.AddMember("key", "word5", doc.GetAllocator());
	item.AddMember("value", "µ¥´Ê5", doc.GetAllocator());
	contents.PushBack(item, doc.GetAllocator());

	// convert dom to string.
	StringBuffer buffer;      // in rapidjson/stringbuffer.h
	Writer<StringBuffer> writer(buffer); // in rapidjson/writer.h
	doc.Accept(writer);

	psln(buffer.GetString());
}
