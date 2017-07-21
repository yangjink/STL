#define _CRT_SECURE_NO_WARNINGS 1
char* find(const char *str)
{
	char arr[256] = {0};
	const char *tmp = str;
	while(*str)
	{
	 arr[*str]++;
	 str++;
	}
	str = tmp;
	while(*str)
	{
	 if(arr[*str] == 1)
	 return *str;
	 str++;
	}
	return -1;
}
int main()
{
	char *p = "aaaabfqccrbdw";
	char ret = find(p);
	if(ret != -1)
	 printf("%c\n", ret);
	system("pause");
	return 0;
}
