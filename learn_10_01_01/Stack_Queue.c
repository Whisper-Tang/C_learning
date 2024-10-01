#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#


#include <Stack_Queue.h>
////ջ��
////����ջ��˳�����ʽ��
//typedef struct {	
//	ElemType* base;
//	ElemType* top;
//	int stacksize;
//}SqStack;

//��ʼ��˳��ջ
bool InitSqStack(SqStack* S)
{
	S->base = (ElemType*)malloc(MaxSize * sizeof(ElemType));
	if (S->base == NULL)
		return false;
	S->top = S->base;	// ��ʼ��ջ��ָ�룬ջ��ָ��ָ����һ��ֵ����ջλ��
	S->stacksize = MaxSize; // ջ���������
	return true; // ȷ������ֵ
}
//�жϿ�ջ
bool SqStackEmpty(SqStack S)
{
	if (S.base == NULL)
		return false;	//����ֵ����
	return S.base == S.top/*? true : false*/;	//ջ��Ϊtrue������Ϊfalse
}
//��ջ��˳��ջ��
bool PushSqStack(SqStack* S, ElemType a)
{
	if (S->top - S->base >= S->stacksize || S->base == NULL)
		return false;
	*S->top++ = a;
	return true;
}

//��ջ��˳��ջ��
bool PopSqStack(SqStack* S, ElemType* x)
{
	if (S->top == S->base || S->base == NULL)
		return false;
	*x = *--S->top;
	return true;
}

//��ȡջ��Ԫ�أ�˳��ջ��
bool GetSqStack(SqStack* S, ElemType* x)
{
	if (S->top == S->base || S->base == NULL)
		return false;
	*x = *((S->top) - 1);
	return true;
}
// 
// 

////������ջ���
//typedef struct StackNode {
//	ElemType data;
//	struct StackNode* next;
//}StackNode, * LinkStack;

//��ʼ����ջ
bool InitLinkStack(LinkStack* S)
{
	*S = NULL;
	return true;
}
//{
//	StackNode* base = (StackNode*)malloc(sizeof(StackNode));
//	if (base == NULL)
//		return false;
//	base->data = 0;
//	base->next = NULL;
//	StackNode* top = base;
//	reture true;
//}

//�ж���ջ�Ƿ�Ϊ��
bool LinkStackEmpty(LinkStack S)
{
	return S != NULL;
}

//��ջ(��ջ)
bool PushLinkStack(LinkStack* S, ElemType a)
{
	StackNode* top = (StackNode*)malloc(sizeof(StackNode));
	if (top == NULL)
		return false;
	//S = top;	//Ӧʹ��ͷ�巨�������ջʱ��ջ��S�ص���һ���ڵ�
	//top->next = NULL;
	top->next = *S;
	top->data = a;
	*S = top;
	return true;
}

//��ջ����ջ��
bool PopLinkStack(LinkStack* S, ElemType* x)
{
	if (*S == NULL)
		return false;
	StackNode* temp = *S;
	*x = temp->data;
	*S = temp->next;
	free(temp);
	return true;
}

//��ȡ��ջ��Ԫ��
bool GetLinkStack(LinkStack S, ElemType* x)
{
	if (S == NULL)
		return false;
	*x = S->data;
	return true;
}


















