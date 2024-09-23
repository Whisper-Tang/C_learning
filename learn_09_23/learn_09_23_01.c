#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//定义一个单链表节点
typedef struct LNode
{
	int data;	/*= (int*)malloc(sizeof(LNode));*/
	struct LNode* next;
}LNode, * LinkList;

//定义一个双链表节点
typedef struct DNode
{
	int data;	/*= (int*)malloc(sizeof(DNode));*/
	struct DNode* prior;
	struct DNode* next;
}DNode, * DLinkList;

//初始化一个不含头节点的单链表
bool InitLNodeH(LinkList* L)
{
	*L = NULL;
	return true;
}

//初始化一个含头节点的单链表
bool InitLNode(LinkList* L)
{
	*L = (LNode*)malloc(sizeof(DNode));
	if (*L == NULL)
		return false;
	(*L)->next = NULL;
	return true;
}

//初始化一个不含头节点的双链表
bool InitDNodeH(DLinkList* L)
{
	*L = NULL;
	return true;
}


//初始化一个含头节点的双链表
bool InitDNode(DLinkList* L)
{
	*L = (DNode*)malloc(sizeof(DNode));
	if (*L == NULL)
		return false;
	(*L)->next = NULL;
	(*L)->next = NULL;
	return true;
}


//设有一个长度n(n为偶数)的不带头结点的单链表，且结点值都大于0，
//设计算法求这个单链表的最大孪生和。
//孪生和:定义为一个结点值与其孪生结点值之和，
//对于第i个结点(从О开始)，其孪生结点为第n - i - 1个结点。






//17.假设该链表只给出了头指针list。在不改变链表的前提下，
// 请设计一个尽可能高效的算法，查找链表中倒数第k个位置上的结点(k为正整数)。
// 若查找成功，算法输出该结点的data域的值，并返回l;否则，只返回0.

int GetK(LinkList* list, int k, int k_data)
{
	//空表判断
	if (*list == NULL)
		return 0;

	LNode* p = *list;
	int n = 0;

	//遍历链表统计节点个数
	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}

	//k比n大则找不到
	if (k > n)
		return 0;
	//if (k == n)
	//{
	//	k_data = (*list)->data;	//输出data值
	//	return 1;	//返回1
	//}

	p = *list;
	//找到到数k节点，即第n-k+1个节点
	for (int i = 1; i <= n - k + 1; i++)
	{
		p = p->next;
	}

	k_data = (*list)->data;	//输出data值
	return 1;	//返回1
}

//方法二
int GetK(LinkList* list, int k)
{
	//空表判断
	if (*list == NULL)
		return 0;

	//定义工作指针
	LNode* p = *list;
	LNode* q = *list;
	//n表示q指针指向，从p开始到数第n个节点，
	int n = 1;

	//p从开始扫描到末尾
	while (p->next != NULL)
	{
		//从n等于k开始，每次q跟着移动
		if (n >= k)
			q = q->next;
		n++;
		p = p->next;
	}

	//若q还是指向头指针，表示p未移动，链表节点个数不足k
	if (q == *list)//与if (n <= k)等价
	{
		return 0;
	}

	//p即为到数第k个节点
	printf("%d", q->data);
	return 1;
}

//请设计一个时间上尽可能高效的算法，
// 找出由A和B所指向两个链表共同后缀的起始位置。

LNode* SanmePartStart(LinkList* A, LinkList* B)
{
	// 如果任一链表为空，直接返回 NULL
	if (*A == NULL || *B == NULL) return NULL;

	//定义工作指针a，b指向A和B的头节点
	LNode* a = *A;
	LNode* b = *B;

	//a,b一起向后遍历，循环直到两个指针相遇
	while (a == b)	//如果AB有公共部分，ab会在同时指向NULL前，先指向公共链的起始节点
	{
		//当 a 到达链表末尾时，重置为链表 B 的头
		a == NULL ? (a = *B) : (a = a->next);
		//当 b 到达链表末尾时，重置为链表 A 的头
		b == NULL ? (b = *A) : (b = b->next);
	}
	// 返回相遇的节点，或 NULL（表示无公共链）
	return  a == NULL ? NULL : a;
}




//16
//19
//20
