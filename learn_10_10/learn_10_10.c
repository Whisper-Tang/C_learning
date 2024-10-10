#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct SqNode
{
	int data;
	struct SqNode* next;
}SqNode,*LinkList;


//无头结点
LinkList UpdownMerge(LinkList* A, LinkList* B)
{
	LinkList C = NULL;
	SqNode* a = *A, * b = *B;
	SqNode* temp;
	while (a && b)
	{
		//temp取下最小的结点
		if (a->data <= b->data)
		{
			temp = a;
			a = a->next;
		}
		else
		{
			temp = b;
			b = b->next;
			
		}
		//插入到C第一个结点之前（头插法逆序插入）
		temp->next = C;

		//更新第一个结点
		C = temp;
	}

	//将未遍历完的队列头插入c（头插法逆序插入）
	while(b)
	{
		temp = b;
		b = b->next;

		temp->next = C;
		C = temp;

	}
	while (a)
	{
		temp = a;
		a = a->next;

		temp->next = C;
		C = temp;

	}

	return C;

}

int main() {
	// 创建两个有序的链表A和B进行测试
	SqNode n1 = { 1, NULL }, n2 = { 3, NULL }, n3 = { 5, NULL };
	SqNode n4 = { 2, NULL }, n5 = { 4, NULL }, n6 = { 6, NULL };
	n1.next = &n2;
	n2.next = &n3;
	n4.next = &n5;
	n5.next = &n6;

	LinkList A = &n1;
	LinkList B = &n4;

	// 合并链表
	LinkList C = UpdownMerge(&A, &B);

	// 打印合并后的链表
	SqNode* p;
	for (p = C; p; p = p->next)
	{
		printf("%d->", p->data);
	}
	printf("NULL\n");
	return 0;
}




//傻逼git推送冲突，一直显示合并中，合并你妈呢
//傻逼git推送冲突，一直显示合并中，合并你妈呢
//傻逼git推送冲突，一直显示合并中，合并你妈呢
// //傻逼git推送冲突，一直显示合并中，合并你妈呢
// //傻逼git推送冲突，一直显示合并中，合并你妈呢
//傻逼git推送冲突，一直显示合并中，合并你妈呢