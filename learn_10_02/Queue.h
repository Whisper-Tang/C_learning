#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MaxSize_ElemType.h"

//����˳�����(ѭ������)
typedef struct SqQueue
{
	ElemType* base;	//�洢�ռ����ַ
	int front, rear;
}SqQueue;

//ѭ�����в���
bool InitSqQueue(SqQueue* Q);//��ʼ��˳�����
bool EnSqQueue(SqQueue* Q, ElemType a);//ѭ���������
bool DeSqQueue(SqQueue* Q, ElemType* x);//ѭ�����г���
bool GetSqQueue(SqQueue Q, ElemType* x);//��ȡ��ͷԪ��
bool SqQueueLength(SqQueue Q, int* len);//��ȡ���г��ȣ�˳���



//����һ�������н��
typedef struct LQueueNode
{
	ElemType data;
	struct LQueueNode* next;
}LQueueNode, * LQueueQtr;

//����һ��������
typedef struct LinkQueue
{
	LQueueQtr front;
	LQueueQtr rear;
}LinkQueue;

//�����в���
bool InitLinkQueue(LinkQueue* Q);	//��ʼ��������(��ͷ���)
bool EnLinkQueue(LinkQueue* Q, ElemType a);	//��ӣ������У�
bool DeLinkQueue(LinkQueue* Q, ElemType* x);	//���ӣ������У�
bool GetLinkQueue(LinkQueue Q, ElemType* x);	//��ȡ����Ԫ��
bool LinkQueueLength(LinkQueue Q, int* len);	//��ȡ�����г���