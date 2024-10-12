#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIST_INIT_SIZE 100
//设顺序表va中的数据元素递增有序，试写一算法，将x插入到顺序表的适当位置
typedef struct
{
	int* elem;
	int length;
	int listsize;
}SqList;

bool InitSqList(SqList* L)
{
	(*L).elem = (int*)malloc(sizeof(int) * LIST_INIT_SIZE);
	if (!(*L).elem)
		return false;
	for (int i = 0; i < LIST_INIT_SIZE; i++)
	{
		(*L).elem[i] = 0;
	}
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
	return true;
}

bool InsertSqListSort(SqList* L,int x)
{
	//表不存在，未初始化，满表时，返回错误
	if (!L || !(*L).elem||(*L).length==(*L).listsize)
		return false;
	int i = 0;
	int len = (*L).length;

	//找到第一个大于x的elem的下标i
	for (i; i < len && (*L).elem[i] <= x; i++);

	//将i及其之后的元素后移，空出下标为i的位置
	for (len; len>i; len--)
	{
		(*L).elem[len] = (*L).elem[len - 1];	
	}

	//插入i，同时表长+1
	(*L).elem[i] = x;
	(*L).length++;

	return true;
}