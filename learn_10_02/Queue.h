#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MaxSize_ElemType.h"

//定义顺序队列(循环队列)
typedef struct SqQueue
{
	ElemType* base;	//存储空间基地址
	int front, rear;
}SqQueue;

//循环队列操作
bool InitSqQueue(SqQueue* Q);//初始化顺序队列
bool EnSqQueue(SqQueue* Q, ElemType a);//循环队列入队
bool DeSqQueue(SqQueue* Q, ElemType* x);//循环队列出队
bool GetSqQueue(SqQueue Q, ElemType* x);//获取队头元素
bool SqQueueLength(SqQueue Q, int* len);//获取队列长度（顺序表）



//定义一个链队列结点
typedef struct LQueueNode
{
	ElemType data;
	struct LQueueNode* next;
}LQueueNode, * LQueueQtr;

//定义一个链队列
typedef struct LinkQueue
{
	LQueueQtr front;
	LQueueQtr rear;
}LinkQueue;

//链队列操作
bool InitLinkQueue(LinkQueue* Q);	//初始化链队列(含头结点)
bool EnLinkQueue(LinkQueue* Q, ElemType a);	//入队（链队列）
bool DeLinkQueue(LinkQueue* Q, ElemType* x);	//出队（链队列）
bool GetLinkQueue(LinkQueue Q, ElemType* x);	//获取队首元素
bool LinkQueueLength(LinkQueue Q, int* len);	//获取链队列长度