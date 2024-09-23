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
	if (C == NULL) 
		return NULL;//表示空间不足

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
			if (c->next == NULL) return NULL;//表示空间不足
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

//已知两个链表A和B分别表示两个集合，其元素递增排列。
// 编制函数，求A与B的交集，并存放于A链表中。

bool SameA(LinkList* A, LinkList* B)
{
	if (*A == NULL || *B == NULL)
		return true;

	//两个指针a,b同时扫描链表AB
	LNode* a = (*A)->next;
	LNode* b = (*B)->next;
	//定义a的前驱节点指针prior，也结果链表A的尾指针
	LNode* prior = *A;

	//如果有一个表扫描完毕，停止扫描
	while (a != NULL && b != NULL)
	{
		//若相同则保留a，然后a向后移动
		if (a->data == b->data)
		{
			a = a->next;
			//b = b->next;
		}

		//若不同，b小则b向后扫描，
		else if (a->data > b->data)
		{
			b = b->next;
		}
		//a小则删除a，
		else
		{
			prior->next = a->next;	//绕过a节点
			free(a);	//删除释放空间
			a = prior->next;	//a移动到新的节点
		}		
	}//while

	//下方代码功能已被后续while循环包括，故做注释处理
	//////a扫描完毕，则直接输出
	////if (a = NULL)
	////	return true;
	////若b先扫描完毕，则删除a，置空尾节点指针域
	//else
	//	free(a);
	//prior->next = NULL;
	//上述原代码方案不能做到删除a剩余所有元素		

	//删除a剩余所有元素
	while (a != NULL)
	{
		prior->next = a->next;
		free(a);
		a = prior->next;
	}
	return true;
}
//上述方案并未对表B做处理，如需删除可添加删除操作（没扫描一个b释放一个节点）
//最后释放未扫描完的B表，释放B的头节点


//设计一个算法用于判断带头结点的双链表是否对称。
bool MirrorTF(DLinkList* A)
{
	//空表判断(空表也对称，滑稽)
	if (*A == NULL || (*A)->next == NULL)
		return true;

	//定义前指针，指向第一个元素
	DNode* f = (*A)->next;
	//定义尾指针,并移动到A的尾节点
	DNode* l = *A;

	while (l->next != NULL)
	{
		l = l->next;
	}
	
	//当 f 和 l 相遇或交叉时（即 f == l 或 f->prior == l），说明链表已扫描一半且对称。
	while(f != l && f->prior != l)
	{
		if (f->data == l->data)
		{
			f = f->next;
			l = l->prior;
		}
		else return false;//有不相等的则返回不对称
	}
	//全部相等则对称
	return true;
}



//有两个循环单链表，链表头指针分别为h1和 h2，
// 编写一个函数将链表h2链接到链表h1之后，
// 要求链接后的链表仍保持循环链表形式。


bool DumpAB(LinkList*h1, LinkList* h2)
{
	//错误参数判断
	if (*h1 == NULL || *h2 == NULL)
		return false;
			
	//定义指针p
	LNode* p = *h1;
	//从h1开始扫描到h1尾节点
	while (p->next != *h1)
		p = p->next;

	p->next = (*h2)->next;//链接h1的尾节点到h2头节点后第一个节点

	//开始继续向后扫描到h2尾节点
	while (p->next != *h2)
		p = p->next;

	p->next = *h1;	//链接h2尾节点到h1头节点

	free(*h2); //释放h2头节点

	return true;

}


//设有一个带头结点的非循环双链表工，
// 其每个结点中除有pre、 data和next域外，
// 还有一个访问频度域freq,其值均初始化为零。
// 每当在链表中进行一次Locate(L,x)运算时，令值为x的结点中freq域的值增1，
// 并使此链表中的结点保持按访问频度递减的顺序排列，
// 且最近访问的结点排在频度相同的结点之前，以便使频繁访问的结点总是靠近表头。
// 试编写符合上述要求的Locate(L,z)函数，返回找到结点的地址，类型为指针

typedef struct FDNode
{
	struct FDNode* pre;
	int data;
	int freq;
	struct FDNode* next;
}FDNode, *FDLinkList;



FDLinkList Locate(FDLinkList *L, int z)
{
	//空表判断
	if (*L == NULL || (*L)->next == NULL)
		return NULL;	//表示没有找到z所在节点
		
	//定义扫描指针
	FDNode* q= (*L)->next;
	int i = 0;	//z记录频度
	FDNode* p = *L;

	//只有一个元素
	if (q->next == NULL)
	{
		if (q->data == z)
		{
			q->freq++;
			return q;
		}
		else return NULL; //找不到
	}

	//不止一个元素
	//先让所有值为Z的节点频度+1
	while (p->next != NULL)
	{
		//Z的节点频度 + 1,并用i记录
		if (p->next->data == z)
		{
			i = ++(p->next->freq);
			p = p->next;//下一个待处理的节点
		}		
	}
	//若找到z则i至少为1，若i为0则直接返回
	if (i == 0)
		return NULL;//若i为0则直接返回，表示没找到z

	//对L中所有节点按照frep进行排序
	//分析，因为每次访问，所有数据为z的值都一起加一，并按要求进行排序
	//所以只需将本次访问的z对应的节点，统一移动到最后一个大于其频度的节点之后即可

	//从最后一个节点向前扫描，找到到数第一个频度大于z的节点,并让p指向它
	while (p != *L)
	{
		if (p->freq > i)
			break;
		p = p->pre;
	}
	//跳出循环时，p指向它最后一个频度大于z的节点或者指向头节点
	
	//指针q开始遍历链表，找到z并将其移动到p之后；
	while (q!= NULL)
	{
		//指针q找到z节点；
		if (q->data == z)
		{
			//这不是尾节点
			if (q->next != NULL)
			{
				FDNode* temp = q->next;//暂存后续节点

				//断开p的连接，并保证原表连续
				q->pre->next = temp;
				temp->pre = q->pre;

				if (p->next == NULL)
					break;//p->next不会等于NULL，但是VS报警警告
				//将q（z节点）移动到p之后
				q->pre = p;
				q->next = p->next;
				p->next->pre = q;
				p->next = q;

				q = temp;	//q回到下一个扫描节点
			}
			//该z节点为尾节点
			else
			{
				q->pre->next = NULL;	//前驱成为新尾节点，置空其后指针域


				if (p->next == NULL)
					break;//p->next不会等于NULL，但是VS报警警告
				//将q（z节点）移动到p之后
				q->pre = p;
				q->next = p->next;
				p->next->pre = q;
				p->next = q;
			}
					
		}
	}
	return p->next;//z的地址在p之后
}




//设将n(n>1 )个整数存放到不带头结点的单链表L中，
// 设计算法将L中保存的序列循环右移k(0<k<n)个位置。
// 例如，若k=1，则将链表{0,1,2,3}变为{3,0,1,2}。
bool Move(LinkList* L, int n,int k)
{
	//参数合理性判断，不合理则结束并返回错误
	if (*L==NULL||n > 1 || k <= 0 || k >= n)
		return false;

	//工作指针p
	LNode* p = *L;

	//只需将表尾巴k个元素集体移动到第一个元素之前即可；
	for (int i = 1; i < n - k; i++)
	{
		p = p->next;
	}
	//q标记结果链表的尾节点，
	LNode* q = p;
	//l标记结果链表的首节点，
	LNode* l = p->next;
	//继续移动p到当前链表尾节点
	while (p->next != NULL)
		p = p->next;

	p->next = *L;	//形成环
	*L = l;		//更新头指针
	q->next = NULL;	//断开尾节点并置空指针域
	return true;
}
//上述方法时间复杂度为O(n)
//法二
bool Movek(LinkList* L, int n, int k)
{
	//参数合理性判断，不合理则结束并返回错误
	if (*L == NULL || n > 1 || k <= 0 || k >= n)
		return false;

	//定义工作指针p并移动为尾指针
	LNode* p = *L;
	while (p->next != *L)
		p = p->next;

	p->next = *L; //形成循环单链表

	//移动到断开位置
	for (int i = 1; i <= n - k; i++)
		p = p->next;

	//更新头指针，并断开尾指针、置空尾指针指针域形成新的非循环单链表
	*L = p->next;
	p->next = NULL;

	return true;

}


//单链表有环，是指单链表的最后一个结点的指针指向了链表中的某个结点
//试编写算法判断单链表是否存在环。
// 
//有环true；无环false；
bool RoundTF(LinkList* L)
{
	//空表天然无环
	if (*L == NULL || (*L)->next == NULL)
		return false;

	//定义两个指针，fast每向后移动两次，slow向后移动一次；
	LNode* slow = *L;
	LNode* fast = slow->next;
	int i = 0;

	//如果又任意指针指向NULL则显然无环
	//while (fast != NULL&& slow !=NULL )
	while(fast != NULL && fast->next != NULL)
	{
		//如果fast和slow相等，
		// 则说明fast在环中已比slow多走了一圈，
		if (fast == slow)
			return true;	//// 故有环

		// slow 每次走一步
		slow = slow->next;
		// fast 每次走两步
		fast = fast->next->next;
		////fast移动一次，i计数一次
		//fast = fast->next;
		//i++;
		//if (i = 2)//i计数为2时，代表fast移动两次，此时slow移动一次并重新计数
		//{
		//	slow = slow->next;
		//	i = 0;
		//}
	}
	return false;//任意指针指向NULL则显然无环

}

//设有一个长度n(n为偶数)的不带头结点的单链表，且结点值都大于0，
//设计算法求这个单链表的最大孪生和。
//孪生和:定义为一个结点值与其孪生结点值之和，
//对于第i个结点(从О开始)，其孪生结点为第n - i - 1个结点。






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
		if(p->next!=NULL)
			p = p->next;
	}

	k_data = (p)->data;	//输出data值
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




//16
//19
//20








int main()
{
	return 0;
}