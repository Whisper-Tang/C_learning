#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include "Tree.h"
#include "Stack.h"

////定义一棵树的结点
//typedef struct TreeNode
//{
//	ElemType value;
//	bool isEmpty;
//}TreeNode;

//树的声明 TreeNode t[MaxSize];

//初始化一棵树
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


////定义一颗二叉链树结点
//typedef struct BiTNode
//{
//	ElemType value;
//	struct BiTNode* lchild;
//	struct BiTNode* rchild;
//}BiTNode,*BiTree;

//初始化链二叉树
bool InitBiTree(BiTree* T)
{
	*T = NULL;
	return true;
}

//创建新结点
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

//访问并打印结点值
void visit(ElemType a)
{
	printf("%c ", a);
}


//中序遍历二叉树（递归）
bool InOrderTreverse(BiTree T)
{
	if (T == NULL)
		return true;

	InOrderTreverse(T->lchild);
	visit(T->value);
	InOrderTreverse(T->rchild);

	return	true;
}

//先序遍历二叉树（递归）
bool PreOrderTreverse(BiTree T)
{
	if (T == NULL)
		return true;

	visit(T->value);
	PreOrderTreverse(T->lchild);
	PreOrderTreverse(T->rchild);

	return	true;
}

//后序遍历二叉树（递归）
bool PostOrderTreverse(BiTree T)
{
	if (T == NULL)
		return true;

	PostOrderTreverse(T->lchild);
	PostOrderTreverse(T->rchild);
	visit(T->value);

	return	true;
}



////中序遍历二叉树，非递归
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

