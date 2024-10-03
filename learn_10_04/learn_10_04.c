#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BiTNode
{
	int data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,*BiTree;


//��������ж�Ϊ2�Ľ����
int CountDoubleNode(BiTree T)
{
	if (T == 0)
		return 0;
	else if (T->lchild && T->rchild)
		return CountDoubleNode(T->lchild) + CountDoubleNode(T->rchild) + 1;
	else return CountDoubleNode(T->lchild) + CountDoubleNode(T->rchild);
}

//Ѱ�����������k������ֵ
void PreOrder(BiTree T, int* i, int k,int *save)
{
	if (T && *i != k)
	{
		*save = T->data;
		(*i)++;
		PreOrder(T->lchild, &i, k, &save);
		PreOrder(T->rchild, &i, k, &save);
	}
}


int GetValueK(BiTree T, int k)
{
	int i = 1;
	int save = 0;

	PreOrder(T, &i, k,&save);

	return (i == k) ? save : -1;

}


//ɾ����TΪ������
void DeleteX(BiTree* T)
{
	if (*T)
	{
		DeleteX(&(*T)->lchild);
		DeleteX(&(*T)->rchild);
		free(*T);
		*T = NULL;
	}
}

//��������ɾ��

//ɾ�������������� �� ���ΪֵΪx�� ��� Ϊ���� ����
bool DeleteAllX(BiTree* T, int x)
{
	if (T&& *T)
	{
		DeleteAllX(&(*T)->lchild, x);
		DeleteAllX(&(*T)->rchild, x);
		if((*T)->data == x ) 
			DeleteX(&(*T)) ;
	}

	return true;

}

typedef struct SqStack {
	int* base;
	int* top;
	int stacksize;
}SqStack;

bool InitSqStack(SqStack* S)
{
	(*S).base = (int*)malloc(sizeof(int) * 50);
	if ((*S).base == NULL)
		return false;
	(*S).top = (*S).base;
	(*S).stacksize = 50;
	return true;
}

bool Push(SqStack* S, int x)
{
	if ((*S).top - (*S).base >= (*S).stacksize)
		return false;
	*S->top++ = x;
	return true;
}
bool Pop(SqStack* S, int* x)
{
	if ((*S).top == (*S).base)
		return false;
	*x = *--S->top;
	return true;
}



void PrePrint(BiTree T, SqStack* S, int x)
{
	if (T&&T->data!=x)
	{
		Push(&(*S), T->data);
		PrePrint(&T->lchild, &(*S), x);
		PrePrint(&T->rchild, &(*S), x);
	}
}

//��ӡ��������ֵΪx�Ľ����������ȣ�ֵΪx�Ľ�����һ����

bool PrintXAllParets(BiTree T, int x)
{
	SqStack S;
	InitSqStack(&S);

	PrePrint(&T, &S, x);

	int value;
	while (Pop(&S, &value))
	{
		printf("%d ", value);
	}
	free(S.base);

	return true; 
}

int main()
{
	return 0;
}