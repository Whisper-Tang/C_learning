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







int main()
{
	return 0;
}