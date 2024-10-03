#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#

#include "Queue.h"

//定义顺序队列(循环队列)
typedef struct SqQueue 
{
	ElemType* base;	//存储空间基地址
	int front,rear;
}SqQueue;

//初始化顺序队列
bool InitSqQueue(SqQueue* Q)
{
	(*Q).base = (ElemType*)malloc(MaxSize * sizeof(ElemType));
	if ((*Q).base == NULL)
		return false;
	(*Q).front = (*Q).rear = 0;
	return true;
}

//循环队列入队
bool EnSqQueue(SqQueue* Q, ElemType a)
{
	if (Q->base == NULL || (Q->rear + 1) % MaxSize == Q->front)
		return false;
	Q->base[Q->rear] = a;
	Q->rear = (Q->rear + 1) % MaxSize;
	return true;
}

//循环队列出队
bool DeSqQueue(SqQueue* Q, ElemType* x)
{
	if (Q->base == NULL || Q->rear == Q->front)
		return false;
	*x =Q->base[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
	return true;
}

//获取队头元素
bool GetSqQueue(SqQueue Q,ElemType *x)
{
	if (Q.base == NULL || Q.rear == Q.front)
		return false;
	*x = Q.base[Q.front];
	return true;
}

//获取队列长度（顺序表）
bool SqQueueLength(SqQueue Q,int *len)
{
	len = (Q.rear + (MaxSize - Q.front) )% MaxSize;
	return 0;
}


//定义一个链队列结点
typedef struct LQueueNode
{
	ElemType data;
	struct LQueueNode* next;
}LQueueNode, *LQueueQtr;

//定义一个队列
typedef struct LinkQueue
{
	LQueueQtr front;
	LQueueQtr rear;
}LinkQueue;

//初始化链队列(含头结点)
bool InitLinkQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (LQueueNode*)malloc(sizeof(LQueueNode));
	if (Q->front == NULL)
		return false;

	Q->front->next = NULL;
	return true;
}

//入队（链队列）
bool EnLinkQueue(LinkQueue* Q, ElemType a)
{
	LQueueNode* newNode=(LQueueNode*)malloc(sizeof(LQueueNode));
	if (newNode == NULL)
		return false;

	newNode->data = a;
	newNode->next = NULL;

	Q->rear->next = newNode;
	Q->rear = newNode;

	return true;
}

//出队（链队列）
bool DeLinkQueue(LinkQueue* Q, ElemType* x)
{
	if (Q->front == Q->rear || Q->rear == NULL)
		return false;
	
	LQueueNode* temp = Q->front->next;
	*x = temp->data;

	(*Q).front->next = temp->next;
	if (temp == Q->rear)
		Q->rear = Q->front;	//如果删除的是最后一个元素，让队尾指针指向头结点

	free(temp);
	return true;
}

//获取队首元素
bool GetLinkQueue(LinkQueue Q, ElemType* x)
{
	if (Q.front == Q.rear)
		return false;

	*x = Q.front->data;
	return true;
}

//获取链队列长度
bool LinkQueueLength(LinkQueue Q, int *len)
{
	//if (Q.front == NULL || Q.rear == NULL)
	//	return false;
	if (Q.front == Q.rear || Q.front == NULL || Q.rear == NULL)
	{
		*len = 0;
		return true;
	}
	*len = 0;
	for (LQueueNode* p = Q.front; p != NULL; p = p->next)
	{
		*len++;
	}
	return true;
}