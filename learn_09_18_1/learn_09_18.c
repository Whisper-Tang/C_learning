#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct LNode			//定义单链表节点类型
{
	int data;					//节点中存放的数据元素
	struct LNode* next;
}LNode, * LinkList;				//重命名struct LNode为LNode；struct LNode *为LinkList

////初始化一个单链表（不带头节点）
// bool InitLNode(LinkList *L)	//定义初始化InitLNode函数
//{
//	L = NULL;					//将表初始化为空表
//	return true;
//}

//初始化一个单链表（不带头节点）
bool InitLNode(LinkList *L)		//定义初始化InitLNode函数
{
	*L = (struct LNode *)malloc(sizeof(LNode)); //给链表头节点分配内存
	if ( *L == NULL )		
		return false;			// 分配失败，返回false
	(*L)->next = NULL;			// 初始化头节点的next指针
	return true;				// 初始化成功，返回true
}

//static void test()
//{
//	LinkList L ;//生成一个指向单链表的指针
//	InitLNode(L);				//初始化空表
//}


int main()
{
	LinkList L;
	//InitLNode(&L);
	if (InitLNode(&L)) {   // 使用指针传递链表头
		printf("链表初始化成功。\n");
	}
	else {
		printf("链表初始化失败。\n");
	}
	//// 注意：记得在适当的时候释放内存
	//if (L != NULL)
	//	free(L);  // 释放动态分配的内存
	return 0;
	//测试用于单文件提交描述


}

