#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//已知指针ha，hb分别指向两个点链表的头结点，并且已知两个链表表长分别为m和n；
//试写一个算法将这两个链表连接在一起
//假设指针hc指向连接后的链表的头结点；

typedef struct LNode
{
	int* data;
	struct LNode* next;
}LNode,*LinkList;

LinkList MergeSqList(LinkList* ha, LinkList* hb,int m,int n)
{
	//b表短的在前面，省时间
	LNode* Short = m < n ? *ha : *hb;
	LinkList hc = Short;
	LNode* Long = m < n ? *hb : *ha;

	//找到短表的表尾巴结点
	while (Short->next)
	{
		Short = Short->next;
	}
	
	//越过长表头结点，将首元连接在短表上
	Short->next = Long->next;

	free(Long);//释放头结点

	return hc;//赶回合并后的表
}