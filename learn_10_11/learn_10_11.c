#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//已知两个链表A和B分别表示两个集合，其元素递增排列。
// 请设计一个算法，用于求出A与B的交集，并存放在A链表中。

typedef struct SqNode
{
	int data;
	struct SqNode* next;
}SqNode, *LinkList;

bool AUB(LinkList* A, LinkList* B)
{
	SqNode* a = *A, * b = *B;
	//若有一个是空集,则返会空表A	//注释[1]
	if (!a)
		return true;
	if (!b)
	{
		while(a)
		{
			SqNode* temp = a;
			a = a->next;
			free(temp);
		}
		return true;
	}

	//若AB均非空
	SqNode* ra = NULL;
	while (a && b)
	{
		if (a->data == b->data)
		{
			ra = a;
			a = a->next;
		}
		else if (a->data > b->data)
		{
			b = b->next;
		}
		else if (a->data < b->data)
		{
			//如果a有前驱则前驱跳过a，指向下一个结点	//注释[2]
			if (ra)
				ra->next = a->next;

			//取下a并删除
			SqNode* temp = a;
			a = a->next;
			free(temp);			
		}			
	}

	//如果a还有剩余链表，则删除	//注释[3]
	while (a)
	{
		SqNode* temp = a;
		a = a->next;
		free(temp);
	}

	return true;


}

//注释[1]
//题目要求交集存储在A中，一个链表为NULL时，交集为空集，所以在A中存储空集

//注释[2]
//AB链表均无头结点，当a指向第一个结点且需要删除时，ra将一直保持NULL状态，所以可以
//取下a并删除 
//SqNode* temp = a;
//a = a->next;
//free(temp);
//当a不是指向第一个结点时，ra会指向前驱，此时这段代码会正确处理保证不会断链
//如果a有前驱则前驱跳过a，指向下一个结点
//if (ra)
//ra->next = a->next;

//注释[3]
//while (a && b)可能因为B链表处理完而A未处理完而跳出循环
//此时A中剩余未检测的元素均在a指针之后（包括a），且这些元素均不可能数据AB交集