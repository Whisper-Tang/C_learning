#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//����һ��������ڵ�
typedef struct LNode
{
	int data;	/*= (int*)malloc(sizeof(LNode));*/
	struct LNode* next;
}LNode, * LinkList;

//����һ��˫����ڵ�
typedef struct DNode
{
	int data;	/*= (int*)malloc(sizeof(DNode));*/
	struct DNode* prior;
	struct DNode* next;
}DNode, * DLinkList;

//��ʼ��һ������ͷ�ڵ�ĵ�����
bool InitLNodeH(LinkList* L)
{
	*L = NULL;
	return true;
}

//��ʼ��һ����ͷ�ڵ�ĵ�����
bool InitLNode(LinkList* L)
{
	*L = (LNode*)malloc(sizeof(DNode));
	if (*L == NULL)
		return false;
	(*L)->next = NULL;
	return true;
}

//��ʼ��һ������ͷ�ڵ��˫����
bool InitDNodeH(DLinkList* L)
{
	*L = NULL;
	return true;
}


//��ʼ��һ����ͷ�ڵ��˫����
bool InitDNode(DLinkList* L)
{
	*L = (DNode*)malloc(sizeof(DNode));
	if (*L == NULL)
		return false;
	(*L)->next = NULL;
	(*L)->next = NULL;
	return true;
}


//�ڴ�ͷ���ĵ������У�ɾ������ֵΪ�Ľ�㣬���ͷ���ռ䣬
// ����ֵΪ���Ľ�㲻Ψһ���Ա�д�㷨��ʵ������������

bool DeletX(LinkList* L, int x)
{
	if (L == NULL || *L == NULL)
		return false;	
	LNode* p = *L;
	LNode* q = p->next;
	//��ͷ�ڵ�p���һ���ڵ�q��ʼɨ��
	while (q != NULL)
	{
		//�����һ���ڵ�Ϊx��ɾ��
		if (q->data == x)
		{
			p->next = q->next;//p�ƹ����x�����¸��ڵ�
			free(q);//ɾ��x�ͷſռ�
			q = p->next;//qָ���½ڵ�
		}
		else
		{
			p = q;	//p���Ƶ�q
			q = q->next; //qָ�����׼��ɨ����һ���ڵ�
		}		
	}
	return true;
}

//������
bool Delete_X(LinkList* L, int x)
{
	//�ձ��ж�
	if (L == NULL || *L == NULL)
		return false;
	
	//����ָ��p����ɨ�裬rָ��p��ǰ��
	LNode* r = *L;
	LNode* p = r->next;

	//ָ��pɨ��L
	while (p != NULL)
	{
		//���p����x����r�������ӣ�����ָ��r��pͬʱ����ƽ�
		if (p->data != x)
		{
			r->next = p;
			r = p;
			p = p->next;
		}

		//���pΪx�������ͷţ�ɨ����һ���ڵ�
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


//�Ա�д�ڴ�ͷ���ĵ�����L��ɾ��һ����Сֵ���ĸ�Ч�㷨������ý��Ψһ)��
bool Delete_Min(LinkList *L)
{
	//�ձ��ж�
	if (*L == NULL ||  (*L)->next == NULL)
		return false;

	//����ָ��p��qɨ�裬pΪq��ǰ��
	LNode* p = *L,  * q = (*L)->next;
	//����ָ��j��k��¼��Сֵ���ڽڵ㣬jΪ��Сֵ�ڵ�K��ǰ��
	LNode* j = *L,  * k = (*L)->next;//k��ʼΪ��һ���ڵ�

	//ָ��p��qɨ��������kָ����С�������ڵĽڵ�,jָ��k��ǰ����
	while (q != NULL)
	{
		//���q�ڵ�ֵ��С������ָ��k��¼
		if (q->data < k->data)
		{
			k = q;
			j = p;
		}
		//���ɨ��
		p = q;
		q = q->next;
	}
	j->next = k->next;
	free(k);
	return true;
}
////p��̽ڵ������ƶ�p�ڵ��У�
	//q->data = q->next->data;

	////ɾ��p�ĺ��
	//q->next = q->next->next;
	//free(p->next);
	//

//�Ա�д�㷨����ͷ���ĵ�����͵����ã���ν���͵ء���ָ�����ռ临�Ӷ�ΪO(I),
bool TENET_LNode(LinkList* L)
{
	//�ձ��ж�
	if (*L == NULL || (*L)->next == NULL)
		return false;

	LNode* a = *L;
	LNode* b = a->next;
	//���ֻ��һ������Ԫ��
	if (b->next == NULL)
		return true;
	LNode* c = b->next;

	//���ú��׸�Ԫ��Ϊ���һ��Ԫ���޺�̣�ָ�����ÿ�
	b->next = NULL;
	
	//����һ���⣬֮��a���ͷ�ڵ��̣�b��Ǵ�����ڵ㣬c�����һ����Ҫ����Ľڵ�
	while (c != NULL)
	{
		//��b����ͷ�ڵ�l�ͺ��a֮��
		(*L)->next = b;
		b->next = a;
		
		a = b;//����l�ĺ��
		b = c;//���´�����ڵ�
		c = c->next;//������һ��������ڵ�		
	}
	//�������һ��������ڵ�
	(*L)->next = b;
	b->next = a;
	return true;
}
//ͷ�巨����
bool TENET(LinkList* L)
{
	//�ձ��ж�
	if (*L == NULL || (*L)->next == NULL)
		return false;

	//���幤��ָ��p���ȴ�ָ��next
	LNode* p = (*L)->next;
	LNode* Next = NULL;
	
	//�Ͽ�ͷ�ڵ�
	(*L)->next = NULL;

	while (p != NULL)
	{
		//�ݴ�P�ĺ��
		Next = p->next;
		//��ʼͷ��
		p->next = (*L)->next;
		(*L)->next = p;

		//ָ����ƣ�
		p = Next;
	}
	return true;
}

//����һ������ͷ���ĵ������У����н���Ԫ��ֵ����
// �Ա�дһ��������ɾ���������н��ڸ���������ֵ����Ϊ������������)֮���Ԫ�أ�������).
bool DeleteAmongA_B(LinkList* L, int a, int b)
{
	//�ձ������ж�
	if (*L == NULL || (*L)->next == NULL || a == b)
		return false;
	
	//������ָ��p����ǰ��pre
	LNode* pre = *L;
	LNode* p = (*L)->next;

	//ȷ��ab����
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
	
	//����
	while (p != NULL)
	{
		//�������ɾ������ɾ��
		if (p->data > min && p->data < max)
		{		
			LNode* q = p;	//��¼ɾ���ڵ�
			p = p->next;	//pǰ����һ����ɨ��Ľڵ�
			free(q);	//ɾ���ͷ�q
			pre->next = p;	//���Ӷϵ�
		}
		//����ɾ����ɨ����һ���ڵ�
		else
		{
			pre = p;
			p = p->next;
		}			
	}
	return true;
}

//��C={a1, b1, a2, b2�� , am bn}Ϊ���Ա����ô�ͷ���ĵ������ţ�
// ���һ���͵��㷨��������Ϊ�������Ա�ʹ��A= {a1, a2��, a}��B= {bn,��,b2,b1}��
bool DivideList(LinkList* L, LinkList* A, LinkList* B,int m,int n)
{
	//�ձ��ж�
	if (*L == NULL || (*L)->next == NULL)
		return false;

	////�����ĿҪ�����Ĳ���ֻ��һ����a�����Խ�����������������Ϊ���Ա�
	////Ȼ�����븨���ռ䴴��b���ͷ�ڵ㣬����b����Ϊ����ֵ
	//LNode* a = (*L)->next;
	////������ͷָ��B��ָ�������Ա�bn��ͷ�ڵ�
	//LinkList B = (LNode *)malloc(sizeof(LNode)); //����һ���µ�ͷ�ڵ�
	//B->next = NULL; //��ʼ��ͷ�ڵ�ָ��

	LNode* a = *A; //����ָ��aָ���A��β�ڵ�
	LNode* b = *B; //����ָ��bָ���B��ͷ�ڵ�

	//ָ��p��������L��
	LNode *p = (*L)->next;

	for (int i = 0; i <= m + n; i++)	//δ֪mn��Сʱ�����ж�P!=NULL����Ϊ��ֹѭ��������
	{
		//iΪż��ʱ��pָ��an������ʱ��pָ��bm
		if (i % 2 == 0)
		{
			//a���а�˳�����
			a->next = p;
			a = p;	//�ƶ�a������ĩβ
			p = p->next; //�ƶ�p����һ����ɨ��ڵ�

		}
		else
		{
			//b�Ķ��в���ͷ�巨����
			LNode* save = p->next; //�ݴ�p�ĺ�������
			//��p����B��ͷ�ڵ�֮��
			p->next = b->next;	
			b->next = p;

			p = save;	//pָ�������ɨ�����
		}
	}
	a->next = NULL; //�Ͽ�a��p������
	return true;	
}

//��һ����������ĵ������У������ظ���Ԫ�ء�����㷨ɾ���ظ���Ԫ�أ�
//����(7,10,10,21,30,42,42,42,51,70������Ϊ(7��10,21,30,42,51,70 ).
bool DeleteSameElem(LinkList* L)
{
	//�ձ��ж�
	if (*L == NULL || (*L)->next == NULL)
		return false;

	//���幤��ָ��p���ڱ�����ָ��q���ڼ�¼���ݲ��ظ������һ���ڵ�
	LNode* p = *L;
	LNode* q = p->next;

	while (q != NULL)
	{
		//��������ظ�����ɾ��
		if (q->data == p->data)
		{
			LNode* c = q; //��¼Ҫɾ���Ľڵ�
			q = q->next;	//pָ������ڵ�
			free(c);	//�ͷ�ɾ���ظ��ڵ�
			p->next = q;	//��p�����Ϸ�ֹ����
		}				
		else
		{
			p = q;
			q= q->next;	//����ʱqָ��NULL��ѭ��������β�ڵ�pδ�ÿ�
		}
	}
	p->next = NULL;//ȷ���ÿ�β�ڵ�
	return  true;
}

//��A��B��������������ͷ���)������Ԫ�ص�������
// ���һ���㷨��A��B�еĹ���Ԫ�ز���������C��Ҫ���ƻ�A��B�Ľ�㡣

LinkList SameList(LinkList A, LinkList B)
{
	////�ձ��ж�
	//if (*L == NULL || (*L)->next == NULL)
	//	return false;
	//��������ʼ����C ��ǰ�����ж��� typedef struct LNode* LinkList��
	LinkList C = (LNode*)malloc(sizeof(LNode));
	if (C == NULL) 
		return NULL;//��ʾ�ռ䲻��

	C->next = NULL;

	//�����Cβָ��c
	LNode* c = C;

	//���幤��ָ��a,b���ڱ���
	LNode* a = A->next;
	LNode* b = B->next;

	while (a != NULL && b != NULL)
	{
		//ab�ڵ�ֵ����������ֵ��С��ָ��
		if (a->data < b->data)
			a = a->next;
		else if (a->data > b->data)
			b = b->next;
		else//������¼�ڱ�c��
		{
			c->next=(LNode*)malloc(sizeof(LNode));	//�����½ڵ㲢���ӵ���c
			if (c->next == NULL) return NULL;//��ʾ�ռ䲻��
			c = c->next;	//�ƶ����½ڵ�
			c->data = a->data;	//��������
			c->next = NULL;	//�ÿ�β�ڵ�ָ����

			//ͬʱ�ƶ�ָ��ab
			a = a->next;
			b = b->next;
		}		
	}
	return C;
}

//��֪��������A��B�ֱ��ʾ�������ϣ���Ԫ�ص������С�
// ���ƺ�������A��B�Ľ������������A�����С�

bool SameA(LinkList* A, LinkList* B)
{
	if (*A == NULL || *B == NULL)
		return true;

	//����ָ��a,bͬʱɨ������AB
	LNode* a = (*A)->next;
	LNode* b = (*B)->next;
	//����a��ǰ���ڵ�ָ��prior��Ҳ�������A��βָ��
	LNode* prior = *A;

	//�����һ����ɨ����ϣ�ֹͣɨ��
	while (a != NULL && b != NULL)
	{
		//����ͬ����a��Ȼ��a����ƶ�
		if (a->data == b->data)
		{
			a = a->next;
			//b = b->next;
		}

		//����ͬ��bС��b���ɨ�裬
		else if (a->data > b->data)
		{
			b = b->next;
		}
		//aС��ɾ��a��
		else
		{
			prior->next = a->next;	//�ƹ�a�ڵ�
			free(a);	//ɾ���ͷſռ�
			a = prior->next;	//a�ƶ����µĽڵ�
		}		
	}//while

	//�·����빦���ѱ�����whileѭ������������ע�ʹ���
	//////aɨ����ϣ���ֱ�����
	////if (a = NULL)
	////	return true;
	////��b��ɨ����ϣ���ɾ��a���ÿ�β�ڵ�ָ����
	//else
	//	free(a);
	//prior->next = NULL;
	//����ԭ���뷽����������ɾ��aʣ������Ԫ��		

	//ɾ��aʣ������Ԫ��
	while (a != NULL)
	{
		prior->next = a->next;
		free(a);
		a = prior->next;
	}
	return true;
}
//����������δ�Ա�B����������ɾ�������ɾ��������ûɨ��һ��b�ͷ�һ���ڵ㣩
//����ͷ�δɨ�����B���ͷ�B��ͷ�ڵ�


//���һ���㷨�����жϴ�ͷ����˫�����Ƿ�Գơ�
bool MirrorTF(DLinkList* A)
{
	//�ձ��ж�(�ձ�Ҳ�Գƣ�����)
	if (*A == NULL || (*A)->next == NULL)
		return true;

	//����ǰָ�룬ָ���һ��Ԫ��
	DNode* f = (*A)->next;
	//����βָ��,���ƶ���A��β�ڵ�
	DNode* l = *A;

	while (l->next != NULL)
	{
		l = l->next;
	}
	
	//�� f �� l �����򽻲�ʱ���� f == l �� f->prior == l����˵��������ɨ��һ���ҶԳơ�
	while(f != l && f->prior != l)
	{
		if (f->data == l->data)
		{
			f = f->next;
			l = l->prior;
		}
		else return false;//�в���ȵ��򷵻ز��Գ�
	}
	//ȫ�������Գ�
	return true;
}



//������ѭ������������ͷָ��ֱ�Ϊh1�� h2��
// ��дһ������������h2���ӵ�����h1֮��
// Ҫ�����Ӻ�������Ա���ѭ��������ʽ��


bool DumpAB(LinkList*h1, LinkList* h2)
{
	//��������ж�
	if (*h1 == NULL || *h2 == NULL)
		return false;
			
	//����ָ��p
	LNode* p = *h1;
	//��h1��ʼɨ�赽h1β�ڵ�
	while (p->next != *h1)
		p = p->next;

	p->next = (*h2)->next;//����h1��β�ڵ㵽h2ͷ�ڵ���һ���ڵ�

	//��ʼ�������ɨ�赽h2β�ڵ�
	while (p->next != *h2)
		p = p->next;

	p->next = *h1;	//����h2β�ڵ㵽h1ͷ�ڵ�

	free(*h2); //�ͷ�h2ͷ�ڵ�

	return true;

}


//����һ����ͷ���ķ�ѭ��˫������
// ��ÿ������г���pre�� data��next���⣬
// ����һ������Ƶ����freq,��ֵ����ʼ��Ϊ�㡣
// ÿ���������н���һ��Locate(L,x)����ʱ����ֵΪx�Ľ����freq���ֵ��1��
// ��ʹ�������еĽ�㱣�ְ�����Ƶ�ȵݼ���˳�����У�
// ��������ʵĽ������Ƶ����ͬ�Ľ��֮ǰ���Ա�ʹƵ�����ʵĽ�����ǿ�����ͷ��
// �Ա�д��������Ҫ���Locate(L,z)�����������ҵ����ĵ�ַ������Ϊָ��

typedef struct FDNode
{
	struct FDNode* pre;
	int data;
	int freq;
	struct FDNode* next;
}FDNode, *FDLinkList;



FDLinkList Locate(FDLinkList *L, int z)
{
	//�ձ��ж�
	if (*L == NULL || (*L)->next == NULL)
		return NULL;	//��ʾû���ҵ�z���ڽڵ�
		
	//����ɨ��ָ��
	FDNode* q= (*L)->next;
	int i = 0;	//z��¼Ƶ��
	FDNode* p = *L;

	//ֻ��һ��Ԫ��
	if (q->next == NULL)
	{
		if (q->data == z)
		{
			q->freq++;
			return q;
		}
		else return NULL; //�Ҳ���
	}

	//��ֹһ��Ԫ��
	//��������ֵΪZ�Ľڵ�Ƶ��+1
	while (p->next != NULL)
	{
		//Z�Ľڵ�Ƶ�� + 1,����i��¼
		if (p->next->data == z)
		{
			i = ++(p->next->freq);
			p = p->next;//��һ��������Ľڵ�
		}		
	}
	//���ҵ�z��i����Ϊ1����iΪ0��ֱ�ӷ���
	if (i == 0)
		return NULL;//��iΪ0��ֱ�ӷ��أ���ʾû�ҵ�z

	//��L�����нڵ㰴��frep��������
	//��������Ϊÿ�η��ʣ���������Ϊz��ֵ��һ���һ������Ҫ���������
	//����ֻ�轫���η��ʵ�z��Ӧ�Ľڵ㣬ͳһ�ƶ������һ��������Ƶ�ȵĽڵ�֮�󼴿�

	//�����һ���ڵ���ǰɨ�裬�ҵ�������һ��Ƶ�ȴ���z�Ľڵ�,����pָ����
	while (p != *L)
	{
		if (p->freq > i)
			break;
		p = p->pre;
	}
	//����ѭ��ʱ��pָ�������һ��Ƶ�ȴ���z�Ľڵ����ָ��ͷ�ڵ�
	
	//ָ��q��ʼ���������ҵ�z�������ƶ���p֮��
	while (q!= NULL)
	{
		//ָ��q�ҵ�z�ڵ㣻
		if (q->data == z)
		{
			//�ⲻ��β�ڵ�
			if (q->next != NULL)
			{
				FDNode* temp = q->next;//�ݴ�����ڵ�

				//�Ͽ�p�����ӣ�����֤ԭ������
				q->pre->next = temp;
				temp->pre = q->pre;

				if (p->next == NULL)
					break;//p->next�������NULL������VS��������
				//��q��z�ڵ㣩�ƶ���p֮��
				q->pre = p;
				q->next = p->next;
				p->next->pre = q;
				p->next = q;

				q = temp;	//q�ص���һ��ɨ��ڵ�
			}
			//��z�ڵ�Ϊβ�ڵ�
			else
			{
				q->pre->next = NULL;	//ǰ����Ϊ��β�ڵ㣬�ÿ����ָ����


				if (p->next == NULL)
					break;//p->next�������NULL������VS��������
				//��q��z�ڵ㣩�ƶ���p֮��
				q->pre = p;
				q->next = p->next;
				p->next->pre = q;
				p->next = q;
			}
					
		}
	}
	return p->next;//z�ĵ�ַ��p֮��
}




//�轫n(n>1 )��������ŵ�����ͷ���ĵ�����L�У�
// ����㷨��L�б��������ѭ������k(0<k<n)��λ�á�
// ���磬��k=1��������{0,1,2,3}��Ϊ{3,0,1,2}��
bool Move(LinkList* L, int n,int k)
{
	//�����������жϣ�����������������ش���
	if (*L==NULL||n > 1 || k <= 0 || k >= n)
		return false;

	//����ָ��p
	LNode* p = *L;

	//ֻ�轫��β��k��Ԫ�ؼ����ƶ�����һ��Ԫ��֮ǰ���ɣ�
	for (int i = 1; i < n - k; i++)
	{
		p = p->next;
	}
	//q��ǽ�������β�ڵ㣬
	LNode* q = p;
	//l��ǽ��������׽ڵ㣬
	LNode* l = p->next;
	//�����ƶ�p����ǰ����β�ڵ�
	while (p->next != NULL)
		p = p->next;

	p->next = *L;	//�γɻ�
	*L = l;		//����ͷָ��
	q->next = NULL;	//�Ͽ�β�ڵ㲢�ÿ�ָ����
	return true;
}
//��������ʱ�临�Ӷ�ΪO(n)
//����
bool Movek(LinkList* L, int n, int k)
{
	//�����������жϣ�����������������ش���
	if (*L == NULL || n > 1 || k <= 0 || k >= n)
		return false;

	//���幤��ָ��p���ƶ�Ϊβָ��
	LNode* p = *L;
	while (p->next != *L)
		p = p->next;

	p->next = *L; //�γ�ѭ��������

	//�ƶ����Ͽ�λ��
	for (int i = 1; i <= n - k; i++)
		p = p->next;

	//����ͷָ�룬���Ͽ�βָ�롢�ÿ�βָ��ָ�����γ��µķ�ѭ��������
	*L = p->next;
	p->next = NULL;

	return true;

}


//�������л�����ָ����������һ������ָ��ָ���������е�ĳ�����
//�Ա�д�㷨�жϵ������Ƿ���ڻ���
// 
//�л�true���޻�false��
bool RoundTF(LinkList* L)
{
	//�ձ���Ȼ�޻�
	if (*L == NULL || (*L)->next == NULL)
		return false;

	//��������ָ�룬fastÿ����ƶ����Σ�slow����ƶ�һ�Σ�
	LNode* slow = *L;
	LNode* fast = slow->next;
	int i = 0;

	//���������ָ��ָ��NULL����Ȼ�޻�
	//while (fast != NULL&& slow !=NULL )
	while(fast != NULL && fast->next != NULL)
	{
		//���fast��slow��ȣ�
		// ��˵��fast�ڻ����ѱ�slow������һȦ��
		if (fast == slow)
			return true;	//// ���л�

		// slow ÿ����һ��
		slow = slow->next;
		// fast ÿ��������
		fast = fast->next->next;
		////fast�ƶ�һ�Σ�i����һ��
		//fast = fast->next;
		//i++;
		//if (i = 2)//i����Ϊ2ʱ������fast�ƶ����Σ���ʱslow�ƶ�һ�β����¼���
		//{
		//	slow = slow->next;
		//	i = 0;
		//}
	}
	return false;//����ָ��ָ��NULL����Ȼ�޻�

}

//����һ������n(nΪż��)�Ĳ���ͷ���ĵ������ҽ��ֵ������0��
//����㷨��������������������͡�
//������:����Ϊһ�����ֵ�����������ֵ֮�ͣ�
//���ڵ�i�����(�ӧ���ʼ)�����������Ϊ��n - i - 1����㡣






//17.���������ֻ������ͷָ��list���ڲ��ı������ǰ���£�
// �����һ�������ܸ�Ч���㷨�����������е�����k��λ���ϵĽ��(kΪ������)��
// �����ҳɹ����㷨����ý���data���ֵ��������l;����ֻ����0.

int GetK(LinkList* list, int k, int k_data)
{
	//�ձ��ж�
	if (*list == NULL)
		return 0;

	LNode* p = *list;
	int n = 0;

	//��������ͳ�ƽڵ����
	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}

	//k��n�����Ҳ���
	if (k > n)
		return 0;
	//if (k == n)
	//{
	//	k_data = (*list)->data;	//���dataֵ
	//	return 1;	//����1
	//}

	p = *list;
	//�ҵ�����k�ڵ㣬����n-k+1���ڵ�
	for (int i = 1; i <= n - k + 1; i++)
	{
		if(p->next!=NULL)
			p = p->next;
	}

	k_data = (p)->data;	//���dataֵ
	return 1;	//����1
}

//������
int Get_K(LinkList* list, int k)
{
	//�ձ��ж�
	if (*list == NULL)
		return 0;

	//���幤��ָ��
	LNode* p = *list;
	LNode* q = *list;
	//n��ʾqָ��ָ�򣬴�p��ʼ������n���ڵ㣬
	int n = 1;

	//p�ӿ�ʼɨ�赽ĩβ
	while (p->next != NULL)
	{
		//��n����k��ʼ��ÿ��q�����ƶ�
		if (n >= k)
			q = q->next;
		n++;
		p = p->next;
	}

	//��q����ָ��ͷָ�룬��ʾpδ�ƶ�������ڵ��������k
	if (q == *list)//��if (n <= k)�ȼ�
	{
		return 0;
	}

	//p��Ϊ������k���ڵ�
	printf("%d", q->data);
	return 1;
}

//�����һ��ʱ���Ͼ����ܸ�Ч���㷨��
// �ҳ���A��B��ָ����������ͬ��׺����ʼλ�á�

LNode* SanmePartStart(LinkList* A, LinkList* B)
{
	// �����һ����Ϊ�գ�ֱ�ӷ��� NULL
	if (*A == NULL || *B == NULL) return NULL;

	//���幤��ָ��a��bָ��A��B��ͷ�ڵ�
	LNode* a = *A;
	LNode* b = *B;

	//a,bһ����������ѭ��ֱ������ָ������
	while (a == b)	//���AB�й������֣�ab����ͬʱָ��NULLǰ����ָ�򹫹�������ʼ�ڵ�
	{
		//�� a ��������ĩβʱ������Ϊ���� B ��ͷ
		a == NULL ? (a = *B) : (a = a->next);
		//�� b ��������ĩβʱ������Ϊ���� A ��ͷ
		b == NULL ? (b = *A) : (b = b->next);
	}
	// ���������Ľڵ㣬�� NULL����ʾ�޹�������
	return  a == NULL ? NULL : a;
}




//16
//19
//20








int main()
{
	return 0;
}