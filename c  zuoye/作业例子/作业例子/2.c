#define _CRT_SECURE_NO_WARNINGS 1

//int main()
//{
//	int data1 = 0;
//	int data2 = 0;
//	int data3 = 0;
//
//	printf("Please Enter 3 datas: ");
//
//	scanf("%d %d %d", &data1, &data2, &data3);
//	printf("before: %d, %d, %d\n", data1, data2, data3);
//	
//	if (data1 > data2){
//		if (data3 > data1){
//			printf("after: %d, %d, %d\n", data3, data1, data2);
//		}
//		else if(data3<data2){
//			printf("after: %d, %d, %d\n", data1, data2, data3);
//		}
//		else{
//			printf("after: %d, %d, %d\n", data1, data3, data2);
//		}
//	}
//	else{
//		// data1 <= data2
//		if (data3 > data2){
//			printf("after: %d, %d, %d\n", data3, data2, data1);
//		}
//		else if (data3 < data1){
//			printf("after: %d, %d, %d\n", data2, data1, data3);
//		}
//		else{
//			printf("after: %d, %d, %d\n", data2, data3, data1);
//		}
//	}
//
//	system("pause");
//	return 0;
//}

////2
//int main()
//{
//	int data;
//	printf("Please Enter: ");
//	scanf("%d", &data);
//
//	int a[32];
//	int i = 0;
//	for (; i < 32; i++ ){
//		a[i] = data % 2;
//		data /= 2;
//	}
//
//	printf("Å¼Êı£º");
//	i = 31;
//	for (; i >= 0;i-=2){
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	printf("ÆæÊı£º");
//	i = 30;
//	for (; i >= 0; i -= 2){
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//
//	system("pause");
//	return 0;
//}

//1
//int main()
//{
//	int a[] = {1,2,3,4,5,6,7,8,9};
//	int b[] = {11,22,33,44,55,66,77,88,99};
//
//	int len = sizeof(a) / sizeof(a[0]);
//	int i = 0;
//
//	//before
//	printf("before: \n");
//	for (; i < len;i++){
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	for (i=0; i < len; i++){
//		printf("%d ", b[i]);
//	}
//	printf("\n");
//
//	for (i = 0; i < len;i++){
//		a[i] = a[i] ^ b[i];
//		b[i] = a[i] ^ b[i];
//		a[i] = a[i] ^ b[i];
//		/*int tmp = a[i];
//		a[i] = b[i];
//		b[i] = tmp;*/
//	}
//	
//	//after
//	printf("after: \n");
//	for (i=0; i < len; i++){
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	for (i=0; i < len; i++){
//		printf("%d ", b[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
