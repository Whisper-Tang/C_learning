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


//设有一个长度n(n为偶数)的不带头结点的单链表，且结点值都大于0，
//设计算法求这个单链表的最大孪生和。
//孪生和:定义为一个结点值与其孪生结点值之和，
//对于第i个结点(从О开始)，其孪生结点为第n - i - 1个结点。
int TwinsAdd(LinkList L)
{
	//空表判断，返回0表示错误
	if (L == NULL || L->next == NULL)
		return 0;

	//定义快慢指针，fast移动两次，slow移动一次
	LNode* fast = L;
	LNode* slow = L;

	//寻找中间节点
	while (fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	//定义新的首节点,和工作指针
	LNode* head = NULL;
	LNode *p = slow->next;

	//遍历原地逆置后半链表
	while (p != NULL)
	{
		LNode* temp = p->next;	//暂存后续待处理链表
		p->next=head;	//头插法
		head = p;	//重置首节点

		p = temp; //p回到工作位置
	}
	
	//将逆置的后半段接到前半段上
	slow->next = head;

	//重置p到整个链表的第一个节点，即第i=0的节点
	p = L->next;
	//移动slow到第n-i-1个节点
	slow = head;

	//第一个孪生和
	int sum = p->data + slow->data;

	while (slow != NULL)
	{
		if (p->data + slow->data > sum)
			sum = p->data + slow->data;	//更新最大值

		//移动到检查下一组孪生节点
		slow = slow->next;
		p = p->next;
	}

	return sum;
}

// 打印链表（用于调试）
void printList(LinkList L) {
	LNode* temp = L;
	temp = temp->next;
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

// 创建节点
bool createNode(LinkList *L,int value) 
{
	/*if(*L=NULL)*/
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	if (newNode == NULL)
		return false;
	LNode* p= *L;
	while (p->next != NULL)
		p = p->next;
	p->next = newNode;
	newNode->data = value;
	newNode->next = NULL;
	return true;
}

//int main() {
//	// 创建测试链表 {1, 2, 3, 4, 5, 6}
//	LinkList L ;
//	InitLNode(&L);
//	createNode(&L, 1);
//	createNode(&L, 2);
//	createNode(&L, 5);
//	createNode(&L, 4);
//	createNode(&L, 7);
//	createNode(&L, 3);
//	createNode(&L, 3);
//	createNode(&L, 4);
//	createNode(&L, 7);
//	createNode(&L, 6);
//	createNode(&L, 6);
//	createNode(&L, 2);
//	createNode(&L, 9);
//
//
//	printf("链表：");
//	printList(L);
//
//	int result = TwinsAdd(L);
//	printf("最大孪生和: %d\n", result);  // 输出应该为 7 (6+1)
//
//	return 0;
//}








//17.假设该链表只给出了头指针list。在不改变链表的前提下，
// 请设计一个尽可能高效的算法，查找链表中倒数第k个位置上的结点(k为正整数)。
// 若查找成功，算法输出该结点的data域的值，并返回l;否则，只返回0.

int GetK(LinkList* list, int k, int k_data)
{
	//空表判断
	if (*list == NULL)
		return 0;

	LNode* p = *list;
	int n = 0;

	//遍历链表统计节点个数
	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}

	//k比n大则找不到
	if (k > n)
		return 0;
	//if (k == n)
	//{
	//	k_data = (*list)->data;	//输出data值
	//	return 1;	//返回1
	//}

	p = *list;
	//找到到数k节点，即第n-k+1个节点
	for (int i = 1; i <= n - k + 1; i++)
	{
		if (p->next != NULL)
			p = p->next;
		else return 0;
	}

	k_data = (*list)->data;	//输出data值
	return 1;	//返回1
}

//方法二
int Get_K(LinkList* list, int k)
{
	//空表判断
	if (*list == NULL)
		return 0;

	//定义工作指针
	LNode* p = *list;
	LNode* q = *list;
	//n表示q指针指向，从p开始到数第n个节点，
	int n = 1;

	//p从开始扫描到末尾
	while (p->next != NULL)
	{
		//从n等于k开始，每次q跟着移动
		if (n >= k)
			q = q->next;
		n++;
		p = p->next;
	}

	//若q还是指向头指针，表示p未移动，链表节点个数不足k
	if (q == *list)//与if (n <= k)等价
	{
		return 0;
	}

	//p即为到数第k个节点
	printf("%d", q->data);
	return 1;
}

//请设计一个时间上尽可能高效的算法，
// 找出由A和B所指向两个链表共同后缀的起始位置。

LNode* SanmePartStart(LinkList* A, LinkList* B)
{
	// 如果任一链表为空，直接返回 NULL
	if (*A == NULL || *B == NULL) return NULL;

	//定义工作指针a，b指向A和B的头节点
	LNode* a = *A;
	LNode* b = *B;

	//a,b一起向后遍历，循环直到两个指针相遇
	while (a == b)	//如果AB有公共部分，ab会在同时指向NULL前，先指向公共链的起始节点
	{
		//当 a 到达链表末尾时，重置为链表 B 的头
		a == NULL ? (a = *B) : (a = a->next);
		//当 b 到达链表末尾时，重置为链表 A 的头
		b == NULL ? (b = *A) : (b = b->next);
	}
	// 返回相遇的节点，或 NULL（表示无公共链）
	return  a == NULL ? NULL : a;
}




//19单链表保m个整数，其绝对值<=n；
// 设时间复杂度尽可能低的计算法
// 仅保留 节点中 整数的绝对值 相等第一个节点，
// 删除其余绝对值相等的结点


bool DeletSameAbsolute(LinkList* L,int n)
{
#define AbsoluteMAX_n 8//仅让下文的数组创建时不报错，实际n(AbsoluteMAX_n)为题目中的绝对值最大值，而不是10
	//空表天然满足条件
	if (*L == NULL || (*L)->next == NULL)
		return true;

	//定义工作指针p及其前驱
	LNode* q = *L;
	LNode* p = q->next;

	//// 创建并初始化记录数组
	//int* save = (int*)malloc((n + 1) * sizeof(int));
	//for (int i = 0; i <= n; i++)
	//	save[i] = 0;
	int save[AbsoluteMAX_n+1];
	for (int i = 0; i <= AbsoluteMAX_n; i++)
		save[i] = 0;

	//遍历链表
	while (p != NULL)
	{
		//计算节点绝对值
		int Absolute = p->data >= 0 ? p->data : -p->data;
		//检查数组下标[绝对值]
		switch (save[Absolute])
		{
			//为0表示未出现，跳过该节点，并修数组记录为1
		case 0: 
			save[Absolute] = 1;
			q = p;
			p = p->next;
			break;				
			//反之删除该节点
		default:
		{
			//LNode* temp = p;	//暂存要删除的数据
			q->next = p->next;	//绕过并断开需要删除的节点
			free(p);	//删除释放空间
			p = q->next;	//p回到下一个工作节点
		}//default
		}//switch	
	}//while

	free(save);
	return true;
}



//20 设线性表L=(a1,a2,,a3,…",an-2,an-1,an,)采用带头结点的单链表保存，
//请设计一个空间复杂度为O(1)且时间上尽可能高效的算法，
// 重新排列L中的各结点，得到线性表L'=(a1,an-1,a2,,an-2,a3,an-3,…)。
int main()
{
	return 0;
}