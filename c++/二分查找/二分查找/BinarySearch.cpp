#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <assert.h>
using namespace std;

//template<class T>
//int BinarySearch(const T* ptr,size_t  size,const T& x)
//{
//	assert(ptr);
//	int left = 0;
//	int right = size;//[)
//	while (left < right)
//	{
//		int mid = (left + right) / 2;
//		if (ptr[mid] > x)
//		{
//			right = mid ;
//		}
//		else if (ptr[mid] < x)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//
//	}
//	return -1;
//}
template<class T>
int BinarySearch(const T* ptr,size_t  size,const T& x)
{
	assert(ptr);
	int left = 0;
	int right = size - 1;//[]
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (ptr[mid] > x)
		{
			right = mid - 1;
		}
		else if (ptr[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}

	}
	return -1;
}

int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8};
	//cout << sizeof(arr) / sizeof(arr[0]) << endl;

	cout << BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 0) << endl;
	cout << BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 1) << endl;
	cout << BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 2) << endl;
	cout << BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 3) << endl;
	cout << BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 4) << endl;
	cout << BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 5) << endl;
	cout << BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 6) << endl;
	cout << BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 7) << endl;
	cout << BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 8) << endl;
	cout << BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 9) << endl;

	return 0;
template<typename T=T()>
		int();
		T();

		int i = t()
}