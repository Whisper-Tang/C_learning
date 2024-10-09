#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct LinkNode
{
	int data;
	struct LinkNode* next;

}LinkNode,*LinkList;

LinkList mergeList(LinkList* A, LinkList* B)
{
	LinkNode* a = *A, * ra = NULL;

	LinkNode* b = *B, *temp;

	while (a && b)
	{

		if (b->data < a->data)
		{
			temp = b->next;	//暂存b后续结点
			//插入a的前面
			if (ra)
			{
				ra->next = b;	//如果a存在前驱，则需要将前驱和b以及a连接起来
			}
				
			b->next = a;

			b = temp;	//b归位，
		}
		else if (b->data > a->data)
		{
			ra = a;
			a = a->next;
		}
		else if (b->data == a->data)
		{
			temp = b;	//暂存重复结点
			b = b->next;

			free(temp);	//删除重复结点
		}
			
	}
	if (b)//如果b还有剩余，则全大于a，且表名while循环是a=NULL结束的，则a的前驱ra必然存在
	{
		//如果还有剩余，则全大于a
		ra->next = b;
	}
	return *A;

}