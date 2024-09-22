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
	struct LNode* next;
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
bool InitLNode(LinkList* L)
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


//在带头结点的单链表工中，删除所有值为的结点，并释放其空间，
// 假设值为×的结点不唯一，试编写算法以实现上述操作。

bool DeletX(LinkList* L, int x)
{
	if (L == NULL || *L == NULL)
		return false;	
	LNode* p = *L;
	LNode* q = p->next;
	//从头节点p后第一个节点q开始扫描
	while (q != NULL)
	{
		//检查下一个节点为x则删除
		if (q->data == x)
		{
			p->next = q->next;//p绕过后继x链接下个节点
			free(q);//删除x释放空间
			q = p->next;//q指向新节点
		}
		else
		{
			p = q;	//p右移到q
			q = q->next; //q指针向后，准备扫描下一个节点
		}		
	}
	return true;
}

//方法二
bool Delete_X(LinkList* L, int x)
{
	//空表判断
	if (L == NULL || *L == NULL)
		return false;
	
	//设置指针p用来扫描，r指向p的前驱
	LNode* r = *L;
	LNode* p = r->next;

	//指针p扫描L
	while (p != NULL)
	{
		//如果p不是x，将r和其链接，并将指针r，p同时向后推进
		if (p->data != x)
		{
			r->next = p;
			r = p;
			p = p->next;
		}

		//如果p为x，则将其释放，扫描下一个节点
		else
		{
			LNode* q = p;
			p = p->next;
			free(q);
		}		
	}
	r->next = NULL;
	return true;
}


//试编写在带头结点的单链表L中删除一个最小值结点的高效算法（假设该结点唯一)。
bool Delete_Min(LinkList *L)
{
	//空表判断
	if (*L == NULL ||  (*L)->next == NULL)
		return false;

	//定义指针p、q扫描，p为q的前驱
	LNode* p = *L,  * q = (*L)->next;
	//定义指针j、k记录最小值所在节点，j为最小值节点K的前驱
	LNode* j = *L,  * k = (*L)->next;//k初始为第一个节点

	//指针p、q扫描链表，让k指向最小的数所在的节点,j指向k的前驱；
	while (q != NULL)
	{
		//如果q节点值更小，则用指针k记录
		if (q->data < k->data)
		{
			k = q;
			j = p;
		}
		//向后扫描
		p = q;
		q = q->next;
	}
	j->next = k->next;
	free(k);
	return true;
}
////p后继节点数据移动p节点中，
	//q->data = q->next->data;

	////删除p的后继
	//q->next = q->next->next;
	//free(p->next);
	//

//试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为O(I),
bool TENET_LNode(LinkList* L)
{
	//空表判断
	if (*L == NULL || (*L)->next == NULL)
		return false;

	LNode* a = *L;
	LNode* b = a->next;
	//如果只有一个数据元素
	if (b->next == NULL)
		return true;
	LNode* c = b->next;

	//逆置后，首个元素为最后一个元素无后继，指针域置空
	b->next = NULL;
	
	//除第一次外，之后a标记头节点后继，b标记待处理节点，c标记下一个需要处理的节点
	while (c != NULL)
	{
		//将b插入头节点l和后继a之间
		(*L)->next = b;
		b->next = a;
		
		a = b;//更新l的后继
		b = c;//更新待处理节点
		c = c->next;//更新下一个待处理节点		
	}
	//处理最后一个待处理节点
	(*L)->next = b;
	b->next = a;
	return true;
}
//头插法逆置
bool TENET(LinkList* L)
{
	//空表判断
	if (*L == NULL || (*L)->next == NULL)
		return false;

	//定义工作指针p，等待指针next
	LNode* p = (*L)->next;
	LNode* Next = NULL;
	
	//断开头节点
	(*L)->next = NULL;

	while (p != NULL)
	{
		//暂存P的后继
		Next = p->next;
		//开始头插
		p->next = (*L)->next;
		(*L)->next = p;

		//指针后移，
		p = Next;
	}
	return true;
}

//设在一个带表头结点的单链表中，所有结点的元素值无序，
// 试编写一个函数，删除表中所有介于给定的两个值（作为函数参数给出)之间的元素（若存在).
bool DeleteAmongA_B(LinkList* L, int a, int b)
{
	//空表、参数判断
	if (*L == NULL || (*L)->next == NULL || a == b)
		return false;
	
	//定义检测指针p和其前驱pre
	LNode* pre = *L;
	LNode* p = (*L)->next;

	//确定ab区间
	int min = a < b ? a : b;
	int max = a > b ? a : b;
	//int min, max;
	//if (a < b){
	//	min = a; 
	//	max = b;
	//}else{
	//	min = b;
	//	max = a;
	//}
	
	//遍历
	while (p != NULL)
	{
		//如果满足删除条件删除
		if (p->data > min && p->data < max)
		{		
			LNode* q = p;	//记录删除节点
			p = p->next;	//p前往下一个待扫描的节点
			free(q);	//删除释放q
			pre->next = p;	//连接断点
		}
		//无需删除则扫描下一个节点
		else
		{
			pre = p;
			p = p->next;
		}			
	}
	return true;
}

//设C={a1, b1, a2, b2… , am bn}为线性表，采用带头结点的单链表存放，
// 设计一个就地算法，将其拆分为两个线性表，使得A= {a1, a2…, a}，B= {bn,…,b2,b1}。
bool DivideList(LinkList* L, LinkList* A, LinkList* B,int m,int n)
{
	//空表判断
	if (*L == NULL || (*L)->next == NULL)
		return false;

	////如果题目要求函数的参数只有一个表a，可以将函数返回类型设置为线性表
	////然后申请辅助空间创建b表的头节点，并将b表作为返回值
	//LNode* a = (*L)->next;
	////定义新头指针B，指向新线性表bn的头节点
	//LinkList B = (LNode *)malloc(sizeof(LNode)); //申请一个新的头节点
	//B->next = NULL; //初始化头节点指针

	LNode* a = *A; //定义指针a指向表A的尾节点
	LNode* b = *B; //定义指针b指向表B的头节点

	//指针p用来遍历L，
	LNode *p = (*L)->next;

	for (int i = 0; i <= m + n; i++)	//未知mn大小时可以判断P!=NULL来作为终止循环条件；
	{
		//i为偶数时，p指向an，奇数时，p指向bm
		if (i % 2 == 0)
		{
			//a队列按顺序插入
			a->next = p;
			a = p;	//移动a到队列末尾
			p = p->next; //移动p到下一个待扫描节点

		}
		else
		{
			//b的队列采用头插法逆置
			LNode* save = p->next; //暂存p的后续队列
			//将p插入B表头节点之后
			p->next = b->next;	
			b->next = p;

			p = save;	//p指向后续待扫描队列
		}
	}
	a->next = NULL; //断开a和p的连接
	return true;	
}

//在一个递增有序的单链表中，存在重复的元素。设计算法删除重复的元素，
//例如(7,10,10,21,30,42,42,42,51,70）将变为(7，10,21,30,42,51,70 ).
bool DeleteSameElem(LinkList* L)
{
	//空表判断
	if (*L == NULL || (*L)->next == NULL)
		return false;

	//定义工作指针p用于遍历；指针q用于记录数据不重复的最后一个节点
	LNode* p = *L;
	LNode* q = p->next;

	while (q != NULL)
	{
		//如果数据重复，则删除
		if (q->data == p->data)
		{
			LNode* c = q; //记录要删除的节点
			q = q->next;	//p指向后续节点
			free(c);	//释放删除重复节点
			p->next = q;	//将p链接上防止断联
		}				
		else
		{
			p = q;
			q= q->next;	//若此时q指向NULL，循环结束后尾节点p未置空
		}
	}
	p->next = NULL;//确认置空尾节点
	return  true;
}

//设A和B是两个单链表（带头结点)，其中元素递增有序。
// 设计一个算法从A和B中的公共元素产生单链表C，要求不破坏A、B的结点。

LinkList SameList(LinkList A, LinkList B)
{
	////空表判断
	//if (*L == NULL || (*L)->next == NULL)
	//	return false;
	//创建并初始化表C （前文已有定义 typedef struct LNode* LinkList）
	LinkList C = (LNode*)malloc(sizeof(LNode));
	C->next = NULL;

	//定义表C尾指针c
	LNode* c = C;

	//定义工作指针a,b用于遍历
	LNode* a = A->next;
	LNode* b = B->next;

	while (a != NULL && b != NULL)
	{
		//ab节点值不相等则后移值较小的指针
		if (a->data < b->data)
			a = a->next;
		else if (a->data > b->data)
			b = b->next;
		else//相等则记录在表c中
		{
			c->next=(LNode*)malloc(sizeof(LNode));	//申请新节点并连接到表c
			c = c->next;	//移动到新节点
			c->data = a->data;	//存入数据
			c->next = NULL;	//置空尾节点指针域

			//同时移动指针ab
			a = a->next;
			b = b->next;
		}		
	}
	return C;
}







int main()
{
	return 0;
}