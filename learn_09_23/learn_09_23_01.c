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


//����һ������n(nΪż��)�Ĳ���ͷ���ĵ������ҽ��ֵ������0��
//����㷨��������������������͡�
//������:����Ϊһ�����ֵ�����������ֵ֮�ͣ�
//���ڵ�i�����(�ӧ���ʼ)�����������Ϊ��n - i - 1����㡣
int TwinsAdd(LinkList L)
{
	//�ձ��жϣ�����0��ʾ����
	if (L == NULL || L->next == NULL)
		return 0;

	//�������ָ�룬fast�ƶ����Σ�slow�ƶ�һ��
	LNode* fast = L;
	LNode* slow = L;

	//Ѱ���м�ڵ�
	while (fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	//�����µ��׽ڵ�,�͹���ָ��
	LNode* head = NULL;
	LNode *p = slow->next;

	//����ԭ�����ú������
	while (p != NULL)
	{
		LNode* temp = p->next;	//�ݴ��������������
		p->next=head;	//ͷ�巨
		head = p;	//�����׽ڵ�

		p = temp; //p�ص�����λ��
	}
	
	//�����õĺ��νӵ�ǰ�����
	slow->next = head;

	//����p����������ĵ�һ���ڵ㣬����i=0�Ľڵ�
	p = L->next;
	//�ƶ�slow����n-i-1���ڵ�
	slow = head;

	//��һ��������
	int sum = p->data + slow->data;

	while (slow != NULL)
	{
		if (p->data + slow->data > sum)
			sum = p->data + slow->data;	//�������ֵ

		//�ƶ��������һ�������ڵ�
		slow = slow->next;
		p = p->next;
	}

	return sum;
}

// ��ӡ�������ڵ��ԣ�
void printList(LinkList L) {
	LNode* temp = L;
	temp = temp->next;
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

// �����ڵ�
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
//	// ������������ {1, 2, 3, 4, 5, 6}
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
//	printf("����");
//	printList(L);
//
//	int result = TwinsAdd(L);
//	printf("���������: %d\n", result);  // ���Ӧ��Ϊ 7 (6+1)
//
//	return 0;
//}








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
		if (p->next != NULL)
			p = p->next;
		else return 0;
	}

	k_data = (*list)->data;	//���dataֵ
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




//19������m�������������ֵ<=n��
// ��ʱ�临�ӶȾ����ܵ͵ļ��㷨
// ������ �ڵ��� �����ľ���ֵ ��ȵ�һ���ڵ㣬
// ɾ���������ֵ��ȵĽ��


bool DeletSameAbsolute(LinkList* L,int n)
{
#define AbsoluteMAX_n 8//�������ĵ����鴴��ʱ������ʵ��n(AbsoluteMAX_n)Ϊ��Ŀ�еľ���ֵ���ֵ��������10
	//�ձ���Ȼ��������
	if (*L == NULL || (*L)->next == NULL)
		return true;

	//���幤��ָ��p����ǰ��
	LNode* q = *L;
	LNode* p = q->next;

	//// ��������ʼ����¼����
	//int* save = (int*)malloc((n + 1) * sizeof(int));
	//for (int i = 0; i <= n; i++)
	//	save[i] = 0;
	int save[AbsoluteMAX_n+1];
	for (int i = 0; i <= AbsoluteMAX_n; i++)
		save[i] = 0;

	//��������
	while (p != NULL)
	{
		//����ڵ����ֵ
		int Absolute = p->data >= 0 ? p->data : -p->data;
		//��������±�[����ֵ]
		switch (save[Absolute])
		{
			//Ϊ0��ʾδ���֣������ýڵ㣬���������¼Ϊ1
		case 0: 
			save[Absolute] = 1;
			q = p;
			p = p->next;
			break;				
			//��֮ɾ���ýڵ�
		default:
		{
			//LNode* temp = p;	//�ݴ�Ҫɾ��������
			q->next = p->next;	//�ƹ����Ͽ���Ҫɾ���Ľڵ�
			free(p);	//ɾ���ͷſռ�
			p = q->next;	//p�ص���һ�������ڵ�
		}//default
		}//switch	
	}//while

	free(save);
	return true;
}



//20 �����Ա�L=(a1,a2,,a3,��",an-2,an-1,an,)���ô�ͷ���ĵ������棬
//�����һ���ռ临�Ӷ�ΪO(1)��ʱ���Ͼ����ܸ�Ч���㷨��
// ��������L�еĸ���㣬�õ����Ա�L'=(a1,an-1,a2,,an-2,a3,an-3,��)��
int main()
{
	return 0;
}