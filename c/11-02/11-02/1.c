#define _CRT_SECURE_NO_WARNINGS 1
 void Div(int a[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
	 int j = 0;
	 for (j = 0; j < sz - 1 - i; j++)
	 {
	 if (a[j]%2==0)
	 {
	 int temp = a[j];
	 a[j] = a[j + 1];
	 a[j + 1] = temp;
	 }
	 }
	}
}
int main()
{
	int a[] = { 11, 1, 2, 4, 6, 1, 6, 9, 4, 5 };
	int sz = sizeof(a) / sizeof(a[0]);
	Div(a, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
	 printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
