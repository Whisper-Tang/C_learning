#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#

#include "Queue.h"
#include "Stack.h"
#include "Tree.h"


int main()
{
	BiTree root=NULL;
	InitBiTree(&root);

	root = CreatNewBiTNode('a');
	printf(" %c \n", root->value);
	root->lchild= CreatNewBiTNode('b');
	printf("%c ", root->lchild->value);
	root->rchild = CreatNewBiTNode('c');
	printf(" %c\n", root->rchild->value);

	//InOrderBiTree(root);

	//printf("\n");

	InOrderTreverse(root);

	return 0;
}


