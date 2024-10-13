#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIST_INIT_SIZE 100

typedef struct
{
	int* elem;
	int length;
	int listsize;
}SqList;


//顺序表AB去除最大共同前缀后剩余的表A*和B*，
//若A*和B*均为空表，则A=B；
//如果A*为空，B*不为空；或者两者都不为空表且A*首元小于B*首元，则A<B;
//否则A>B

//试写一个比较算法，比较AB大小，但不能破坏原表AB

int CompareA_B(SqList A, SqList B)
{
	int a = 0;
	int b = 0;

	//遍历找到第一个不相等的元素下标a,b
	for (a, b; A.elem[a] == B.elem[b] && a < A.length && b < B.length; a++, b++);

	//A*B*表长
	int remain_A = A.length - a;
	int remain_B = B.length - b;

	//A*B*均为空表，则A=B；输出0
	if (!remain_A && !remain_B)
		return 0;
	//A*空，B*非空 或 两者都不为空表且A*首元小于B*首元； 则A<B; 返回-1
	else if ((!remain_A && remain_B) || (remain_A && remain_B && A.elem[a] < B.elem[b]))
		return -1;
	//否则A>B，返回1
	else
		return 1;
	
}