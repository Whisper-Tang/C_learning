#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MaxSize_ElemType.h"

//定义一棵树的结点
typedef struct TreeNode
{
	ElemType value;
	bool isEmpty;
}TreeNode;

//树的声明 TreeNode t[MaxSize];

//初始化一棵树
bool InitSqTree(TreeNode t[]);


//定义一颗二叉链树结点
typedef struct BiTNode
{
	ElemType value;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

//初始化链二叉树
bool InitBiTree(BiTree* T);
//创建新结点
BiTNode* CreatNewBiTNode(ElemType value);

//访问并打印结点
void visit(ElemType a);

//二叉树的遍历
bool InOrderTreverse(BiTree T);//中序遍历二叉树（递归）
bool PreOrderTreverse(BiTree T);//先序遍历二叉树（递归）
bool PostOrderTreverse(BiTree T);//后序遍历二叉树（递归）

//bool InOrderBiTree(BiTree T);//中序遍历二叉树，非递归




