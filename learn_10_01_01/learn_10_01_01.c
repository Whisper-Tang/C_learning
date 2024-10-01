#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
#include <Stack_Queue.h>


//设单链表的表头指针为L，结点结构由data和next两个域构成，其中data域为字符型.
//试设计算法判断该链表的全部n 个字符是否中心对称。例如 xyx、 xyyx都是中心对称。

//定义单链表节点
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode, *LinkList;

//初始化单链表(无头结点)
bool InitLinkList(LinkList* L)
{
	*L = NULL;
	return true;
}

//单链表插入新节点，
bool InsertLinkList(LinkList* L,ElemType x)
{
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	if (p == NULL)
		return false;
	p->data = x;
	p->next = *L;
	*L = p;
	return true;
}


bool MirroEmpty(LinkList L, int n) 
{
	if (L == NULL || L->next == NULL)
		return true;	//空表或仅有一个元素的表天然对称。

	SqStack temp;
	if (!InitSqStack(&temp))
		return false;
	LinkNode* p = L;

	for (int i = 0; i < (n / 2); i++)
	{
		PushSqStack(&temp, p->data);
		p = p->next;
	}

	//p = p->next;
	if (1 == n % 2)
		p = p->next;

	while (p != NULL && !SqStackEmpty(temp))
	{
		ElemType compare=0;
		PopSqStack(&temp, &compare);
		if (compare != p->data)
			return false;
		p = p->next;
	}


	return true;

}

int main()
{
	return 0;

}


