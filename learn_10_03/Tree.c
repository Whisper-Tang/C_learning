#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include "Tree.h"
#include "Stack.h"

////����һ�����Ľ��
//typedef struct TreeNode
//{
//	ElemType value;
//	bool isEmpty;
//}TreeNode;

//�������� TreeNode t[MaxSize];

//��ʼ��һ����
bool InitSqTree(TreeNode t[])
{
	if (t == NULL)
		return false;
	for (int i = 0; i < MaxSize; i++)
	{
		t[i].isEmpty = true;
	}
	return true;
}


////����һ�Ŷ����������
//typedef struct BiTNode
//{
//	ElemType value;
//	struct BiTNode* lchild;
//	struct BiTNode* rchild;
//}BiTNode,*BiTree;

//��ʼ����������
bool InitBiTree(BiTree* T)
{
	*T = NULL;
	return true;
}

//�����½��
BiTNode* CreatNewBiTNode(ElemType value)
{
	BiTNode* newNode = (BiTNode*)malloc(sizeof(BiTNode));
	if (newNode != NULL)
	{
		newNode->value = value;
		newNode->lchild = newNode->rchild = NULL;
		return newNode;
	}
	return NULL;
}

//���ʲ���ӡ���ֵ
void visit(ElemType a)
{
	printf("%c ", a);
}


//����������������ݹ飩
bool InOrderTreverse(BiTree T)
{
	if (T == NULL)
		return true;

	InOrderTreverse(T->lchild);
	visit(T->value);
	InOrderTreverse(T->rchild);

	return	true;
}

//����������������ݹ飩
bool PreOrderTreverse(BiTree T)
{
	if (T == NULL)
		return true;

	visit(T->value);
	PreOrderTreverse(T->lchild);
	PreOrderTreverse(T->rchild);

	return	true;
}

//����������������ݹ飩
bool PostOrderTreverse(BiTree T)
{
	if (T == NULL)
		return true;

	PostOrderTreverse(T->lchild);
	PostOrderTreverse(T->rchild);
	visit(T->value);

	return	true;
}



////����������������ǵݹ�
//bool InOrderBiTree(BiTree T)
//{
//	SqStack S;
//	InitSqStack(&S);
//
//	if (T == NULL)
//		return true;
//
//	BiTNode* p = T;
//
//	while (p != NULL || !SqStackEmpty(S))
//	{
//		if (p != NULL)
//		{
//			PushSqStack(&S, p);
//			p = p->lchild;
//		}
//		else
//		{
//			PopSqStack(&S, &p);
//			visit(p->value);
//			p = p->rchild;
//		}
//	}
//	return true;
//}

