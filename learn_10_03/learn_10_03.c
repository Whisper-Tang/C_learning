#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#

#include "Queue.h"
#include "Stack.h"
#include "Tree.h"


int main()
{
	BiTree root=NULL;
	InitBiTree(&root);

	CreatBiTree(&root);	//�������˳�򴴽����������������� ABC##DE#G##F###

	//root = CreatNewBiTNode('a');
	//printf(" %c \n", root->value);
	//root->lchild= CreatNewBiTNode('b');
	//printf("%c ", root->lchild->value);
	//root->rchild = CreatNewBiTNode('c');
	//printf(" %c\n", root->rchild->value);

	//InOrderBiTree(root);

	//printf("\n");

	PreOrderTreverse(root); //�������

	return 0;
}

