#include "stdio.h"
#include "stdlib.h"

int a = 10;
int b = 20;
int (*f)(int a, int b) ; //函数指针，可以指向对应的函数


int* Sum(int* Num1, int* Num2)
{
	//一定要注意地址分配
	int *Sum_temp = (int *)malloc(sizeof(int));
	*Sum_temp = *Num1 + *Num2;
	return Sum_temp;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}

int main(void)
{


	// int r[2] = {0}, i , length;

	int *sum;
	sum = Sum(&a, &b);

	printf("**Start* \r\n");
	f = max;
	printf("Max:%d \r\n",f(a, b));

	f = min;
	printf("Min:%d \r\n",f(a, b));

	printf("%d %d %d\r\n", *sum, max(a,b), min(a, b));

//    printf("HHH %d \n", *twoSum(&a, &b));

	//twoSum(nums_Temp, 4, 9, length);

	// for (i = 0; i < ; i++)
	// 	scanf("%d", &r[i]);



	//twoSum(nums_Temp, 10, 9, b);

	//printf("\r\n Num : %d ",twoSum(nums_Temp, 4, 9, b));

	//printf("ss\r\n");
	//
	return 0;
}
