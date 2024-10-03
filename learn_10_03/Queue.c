#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#

#include "Queue.h"

//����˳�����(ѭ������)
typedef struct SqQueue 
{
	ElemType* base;	//�洢�ռ����ַ
	int front,rear;
}SqQueue;

//��ʼ��˳�����
bool InitSqQueue(SqQueue* Q)
{
	(*Q).base = (ElemType*)malloc(MaxSize * sizeof(ElemType));
	if ((*Q).base == NULL)
		return false;
	(*Q).front = (*Q).rear = 0;
	return true;
}

//ѭ���������
bool EnSqQueue(SqQueue* Q, ElemType a)
{
	if (Q->base == NULL || (Q->rear + 1) % MaxSize == Q->front)
		return false;
	Q->base[Q->rear] = a;
	Q->rear = (Q->rear + 1) % MaxSize;
	return true;
}

//ѭ�����г���
bool DeSqQueue(SqQueue* Q, ElemType* x)
{
	if (Q->base == NULL || Q->rear == Q->front)
		return false;
	*x =Q->base[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
	return true;
}

//��ȡ��ͷԪ��
bool GetSqQueue(SqQueue Q,ElemType *x)
{
	if (Q.base == NULL || Q.rear == Q.front)
		return false;
	*x = Q.base[Q.front];
	return true;
}

//��ȡ���г��ȣ�˳���
bool SqQueueLength(SqQueue Q,int *len)
{
	len = (Q.rear + (MaxSize - Q.front) )% MaxSize;
	return 0;
}


//����һ�������н��
typedef struct LQueueNode
{
	ElemType data;
	struct LQueueNode* next;
}LQueueNode, *LQueueQtr;

//����һ������
typedef struct LinkQueue
{
	LQueueQtr front;
	LQueueQtr rear;
}LinkQueue;

//��ʼ��������(��ͷ���)
bool InitLinkQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (LQueueNode*)malloc(sizeof(LQueueNode));
	if (Q->front == NULL)
		return false;

	Q->front->next = NULL;
	return true;
}

//��ӣ������У�
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

//���ӣ������У�
bool DeLinkQueue(LinkQueue* Q, ElemType* x)
{
	if (Q->front == Q->rear || Q->rear == NULL)
		return false;
	
	LQueueNode* temp = Q->front->next;
	*x = temp->data;

	(*Q).front->next = temp->next;
	if (temp == Q->rear)
		Q->rear = Q->front;	//���ɾ���������һ��Ԫ�أ��ö�βָ��ָ��ͷ���

	free(temp);
	return true;
}

//��ȡ����Ԫ��
bool GetLinkQueue(LinkQueue Q, ElemType* x)
{
	if (Q.front == Q.rear)
		return false;

	*x = Q.front->data;
	return true;
}

//��ȡ�����г���
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