#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MaxSize_ElemType.h"

//ջ��
//����ջ��˳�����ʽ��
typedef struct {
	ElemType* base;
	ElemType* top;
	int stacksize;
}SqStack;

//˳��ջ������
bool InitSqStack(SqStack* S);	//��ʼ��˳��ջ
bool SqStackEmpty(SqStack S);	//�жϿ�ջ
bool PushSqStack(SqStack* S, ElemType a);	//��ջ��˳��ջ��
bool PopSqStack(SqStack* S, ElemType* x);	//��ջ��˳��ջ��
bool GetSqStack(SqStack* S, ElemType* x);	//��ȡջ��Ԫ�أ�˳��ջ��

//������ջ���
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;
//��ջ����
bool InitLinkStack(LinkStack* S);	//��ʼ����ջ
bool LinkStackEmpty(LinkStack S);	//�ж���ջ�Ƿ�Ϊ��
bool PushLinkStack(LinkStack* S, ElemType a);	//��ջ(��ջ)
bool PopLinkStack(LinkStack* S, ElemType* x);	//��ջ����ջ��
bool GetLinkStack(LinkStack S, ElemType* x);	//��ȡ��ջ��Ԫ��