#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
int cmp(const void * p1, const void * p2)
{
	int x = *(int *)p1;
	int y = *(int *)p2;
	return x>y ? 1 : x<y ? -1 : 0;

}

void swap(void*a, void*b, int sz)
{
	int i = 0;
	for (i = 0; i<sz; i++)
	{
		char tmp = *((char *)a + i);
		*((char *)a + i) = *((char *)b + i);
		*((char *)b + i) = tmp;
	}



}

void bubble_sort(void*_arr, int num, int sz, int(*com)(const void*a, const void*b))
{
	int i = 0;
	int j = 0;
	char *arr = (char *)_arr;
	assert(arr);
	assert(com);
	assert(num>0);


	for (i = 0; i<num - 1; i++)
	{
		for (j = 0; j<num - i - 1; j++)
		{
			if (cmp(arr + j*sz, arr + (j + 1)*sz)>0)
			{
				swap(arr + j*sz, arr + (j + 1)*sz, sz);
			}

		}

	}

}
int main()
{
	int arr1[] = { 1, 3, 5, 7, 2, 4, 6, 9 };
	float arr2[] = { 1.2, 4.3, 2.1, 0.8, 7.3 };

	int i;
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);


	bubble_sort(arr1, sz1, sizeof(int), cmp);
	bubble_sort(arr2, sz2, sizeof(float), cmp);


	for (i = 0; i<sz1; i++)
	{
		printf("%d,", arr1[i]);
	}
	printf("\n");

	for (i = 0; i<sz2; i++)
	{
		printf("%f,", arr2[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
