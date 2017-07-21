#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <windows.h>

#pragma warning(disable:4996)

int main()
{
	int ch = 0;
	int count = 0;
	while ((ch = getchar()) != EOF) {
		if (ch == '{') {
			count++;
		}
		else if (ch == '}') {
			if (count == 0) {
				printf("not match:(\n");
				Sleep(1000);
				return 0;
			}
			else {
				count--;
			}
		}
		else {
		}
	}

	if (count == 0) {
		printf("match :)!\n");
	}
	else {
		printf("not match:(\n");
	}
	//printf("Please Enter a and n: ");
	//int a = 0;
	//int n = 0;
	//scanf("%d %d", &a, &n);

	//int i = 0;
	//int Sn = 0;
	//int val = a;
	//for (; i < n; i++){
	//	Sn += val;
	//	val = val * 10 + a;
	//}

	//printf("%d\n", Sn);

	//int i = 100;
	//int bits = 0;
	//for (; i < 1000; i++){
	//	if (i < 10){//1
	//		bits = 1;
	//	}
	//	else if ( i>=10 && i < 100){
	//		bits = 2;
	//	}
	//	else{
	//		bits = 3;
	//	}
	//	//printf("%d, %d\n", i, bits);
	//	int tmp = i;
	//	int sum = 0;
	//	while (tmp){
	//		sum += pow(tmp%10, bits);
	//		tmp /= 10;
	//	}
	//	if (sum == i){
	//		printf("%d ", i);
	//	}
	//}
	//printf("\n");

	//int lines = 0;
	//printf("Please Enter lines: ");
	//scanf("%d", &lines);
	//int i = 0;
	//for (; i < lines; i++ ){
	//	int j = 0;
	//	for (; j < lines - i - 1; j++){
	//		printf(" ");
	//	}
	//	for (j = 0; j < 2 * i + 1;j++){
	//		printf("*");
	//	}
	//	printf("\n");
	//}

	//for (i = 0; i < lines - 1; i++){
	//	int j = 0;
	//	for (; j < i+1; j++){
	//		printf(" ");
	//	}
	//	for (j = 0; j < 2*(lines-1-i)-1;j++){
	//	//for (j = ; j >= 0;j--){
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	//int i = 1;
	//int count = 0;
	//for (; i < 100; i++){
	//	if ( i % 10 == 9 ){
	//		count++;
	//	}
	//	if ( i/10 == 9 ){
	//		count++;
	//	}
	//}
	//printf("1~100 9 nums: %d\n", count);
	//int i = 1;
	//double sum = 0.0;
	//int flag = 1;
	//for (; i <= 100; i++ ){
	//	sum += 1.0 / (i*flag);
	//	flag = -flag;
	//}
	//printf("%lf\n", sum);
	//printf("Please Enter: ");
	//int data = 0;
	//scanf("%d", &data);
	//int arr[10];
	//int count = 0;
	//while (data){
	//	arr[count++] = data % 10;
	//	//printf("%d ", arr[count-1]);
	//	data /= 10;
	//}
	//int i = count-1;
	//for (; i >= 0; i--){
	//	printf("%d ",arr[i]);
	//}
	//printf("\n");

	//printf("Please Enter 2 datas: ");
	//int a = 0;
	//int b = 0;
	//scanf("%d %d", &a, &b);

	//while (a*b != 0){
	//	if ( a > b ){
	//		a %= b;
	//	}
	//	else{
	//		b %= a;
	//	}
	//}
	//printf("%d\n", a == 0?b:a);

	//while (1){
	//	if (a > b){
	//		a = a - b;
	//	}
	//	else if ( a < b ){
	//		b = b - a;
	//	}
	//	else{
	//		printf("%d\n", b);
	//		break;
	//	}
	//}
	system("pause");
	return 0;
}
