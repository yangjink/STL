#define _CRT_SECURE_NO_WARNINGS 1
#define ROWS 3
#define COLS 3
int find(int a[ROWS][COLS],int k)
{
	int x = 0;
	int y = COLS - 1;
	while ((x < ROWS) && (y >= 0))
	{
	 if (a[x][y] == k)
	 return 1;
	 else if(a[x][y] < k)
	 {
	 x++;
	 }
	 else
	 {
	 y--;
	 }
	}
	return 0;
}
int main()
{
	int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printf("��������Ҫ���ҵ�����");
	int k = 0;
	scanf("%d", &k);
	int ret = find(a, k);
	if (ret == 1)
	{
	 printf("���������.\n");
	}
	else
	{
	 printf("������.\n");
	}
	system("pause");
	return 0;

}
