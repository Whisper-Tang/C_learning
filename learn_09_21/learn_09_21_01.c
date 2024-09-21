#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//定义一个单链表节点
typedef struct LNode
{
	int data;	/*= (int*)malloc(sizeof(LNode));*/
	struct LNode *next;
}LNode, * LinkList;

//定义一个双链表节点
typedef struct DNode
{
	int data;	/*= (int*)malloc(sizeof(DNode));*/
	struct DNode* prior;
	struct DNode* next;
}DNode, * DLinkList;

//初始化一个不含头节点的单链表
bool InitLNodeH(LinkList* L)
{
	*L = NULL;
	return true;
}

//初始化一个含头节点的单链表
bool InitLNode(LinkList *L)
{
	*L = (LNode*)malloc(sizeof(DNode));
	if (*L == NULL)
		return false;
	(*L)->next = NULL;
	return true;
}

//初始化一个不含头节点的双链表
bool InitDNodeH(DLinkList* L)
{
	*L = NULL;
	return true;
}


//初始化一个含头节点的双链表
bool InitDNode(DLinkList* L)
{
	*L = (DNode*)malloc(sizeof(DNode));
	if (*L == NULL)
		return false;
	(*L)->next = NULL;
	(*L)->next = NULL;
	return true;
}


// 向链表末尾插入节点
bool InsertEnd(LinkList* L, int data)
{
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	if (newNode == NULL)
		return false;
	newNode->data = data;
	newNode->next = NULL;

	if (*L == NULL)
	{
		// 如果链表为空，插入第一个节点
		*L = newNode;
		return true;
	}
	else
	{
		// 找到链表的末尾
		LNode* p = *L;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = newNode;
		return true;
	}
}

// 打印链表内容
void PrintList(LinkList L) {
	LNode* p = L;
	while (p != NULL) {
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("NULL\n");
}





//设计一个递归算法，删除不带头结点的单链表L中所有值为×的结点。
// 
// 非递归
bool DeletLNodeX(LinkList* L, int x)
{
	if (L == NULL || *L == NULL)
		return false;
	//定义指针p用来扫描，
	LNode* p = *L;
	LNode* q = NULL; //q用来标记需要删除的节点
	//第一个数据是否为x？
	while (p != NULL && p->data == x)
	{
		q = p;	//q标记删除节点
		p = p->next;	//移动头指针
		free(q);	//释放q的空间
	}
	*L = p;	//更新头指针
	//上述运行结束后，L指向空（即为空表）或L表中第一个值不为x；
		
	//若为空表，下一步p=NULL直接输出，不为空则扫描。
	//p有后继嘛？没有则扫描完毕，停止运行
	while (p != NULL && p->next!= NULL)
	{		
		 if(p->next->data == x)
		{
			q = p->next;//q标记删除节点
			p->next = q->next;//将p节点跳过被删除的节点指向其之后的节点
			p = q->next;//p移动到下一个节点
			free(q);	//释放q的空间									
		}

		//不为x则p移动到下一个节点
		else p = p->next;		
	}
	return true;
}


//递归
bool DeleteX(LinkList* L, int x)
{
	if (NULL == *L)
		return true;
	if (x == (*L)->data)
	{
		LNode* temp = *L;
		*L = (*L)->next;
		free(temp);
		DeleteX(L, x);
	}
	else DeleteX(&((*L)->next), x);
}







//// 测试主函数
//int main() {
//	LinkList L;
//	InitLNodeH(&L);  // 初始化链表为空
//
//	// 插入一些测试数据
//	InsertEnd(&L, 3);
//	InsertEnd(&L, 5);
//	InsertEnd(&L, 7);
//	InsertEnd(&L, 5);
//	InsertEnd(&L, 9);
//	InsertEnd(&L, 5);
//	InsertEnd(&L, 10);
//
//	printf("初始链表: ");
//	PrintList(L);
//
//	// 测试删除值为5的节点
//	int x = 5;
//	DeletLNode(&L, x);
////	DeleteX(&L, x);
//	printf("删除值为 %d 的节点后链表: ", x);
//	PrintList(L);
//
//	return 0;
//}






//int main()
//{
//	return 0;
//}
//


