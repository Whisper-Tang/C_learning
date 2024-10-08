#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//对单链表进行简单选择排序
typedef struct SqNode
{
	int data;
	struct SqNode* next;
}SqNode,*LinkList;

//假设单链表无头结点；
LinkList* SortLinkList(LinkList* L)
{
	SqNode* h = L;//待排序队列的第一个结点
	SqNode* premin, * min, * pre, * p;
	
	while (h)	//对待排序序列排序
	{
		min = p = h;
		premin = pre = NULL;
		//寻找待排序的最小值结点及其前驱
		while (p)
		{

			if (p->data < min->data)
			{
				premin = pre;
				min = p;
			}
			pre = p;
			p = p->next;
		}

		if (premin == NULL|| min == h)//最小值是第一个元素
			h = h->next;	//待排序序列减一
		else
		{
			premin->next = min->next;	//取下最小值;

			//最小值插入到h；
			min->next = h->next;
			h->next = min;

			h = h->next;	//待排序序列减一
		}
		
	}

return L;

}