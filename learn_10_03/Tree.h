#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MaxSize_ElemType.h"

//����һ�����Ľ��
typedef struct TreeNode
{
	ElemType value;
	bool isEmpty;
}TreeNode;

//�������� TreeNode t[MaxSize];

//��ʼ��һ����
bool InitSqTree(TreeNode t[]);


//����һ�Ŷ����������
typedef struct BiTNode
{
	ElemType value;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

//��ʼ����������
bool InitBiTree(BiTree* T);
//�����½��
BiTNode* CreatNewBiTNode(ElemType value);

//���ʲ���ӡ���
void visit(ElemType a);

//�������ı���
bool InOrderTreverse(BiTree T);//����������������ݹ飩
bool PreOrderTreverse(BiTree T);//����������������ݹ飩
bool PostOrderTreverse(BiTree T);//����������������ݹ飩

//bool InOrderBiTree(BiTree T);//����������������ǵݹ�




