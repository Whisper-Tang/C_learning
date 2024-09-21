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
	struct LNode *next;
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
bool InitLNode(LinkList *L)
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


// ������ĩβ����ڵ�
bool InsertEnd(LinkList* L, int data)
{
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	if (newNode == NULL)
		return false;
	newNode->data = data;
	newNode->next = NULL;

	if (*L == NULL)
	{
		// �������Ϊ�գ������һ���ڵ�
		*L = newNode;
		return true;
	}
	else
	{
		// �ҵ������ĩβ
		LNode* p = *L;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = newNode;
		return true;
	}
}

// ��ӡ��������
void PrintList(LinkList L) {
	LNode* p = L;
	while (p != NULL) {
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("NULL\n");
}





//���һ���ݹ��㷨��ɾ������ͷ���ĵ�����L������ֵΪ���Ľ�㡣
// 
// �ǵݹ�
bool DeletLNodeX(LinkList* L, int x)
{
	if (L == NULL || *L == NULL)
		return false;
	//����ָ��p����ɨ�裬
	LNode* p = *L;
	LNode* q = NULL; //q���������Ҫɾ���Ľڵ�
	//��һ�������Ƿ�Ϊx��
	while (p != NULL && p->data == x)
	{
		q = p;	//q���ɾ���ڵ�
		p = p->next;	//�ƶ�ͷָ��
		free(q);	//�ͷ�q�Ŀռ�
	}
	*L = p;	//����ͷָ��
	//�������н�����Lָ��գ���Ϊ�ձ���L���е�һ��ֵ��Ϊx��
		
	//��Ϊ�ձ���һ��p=NULLֱ���������Ϊ����ɨ�衣
	//p�к���û����ɨ����ϣ�ֹͣ����
	while (p != NULL && p->next!= NULL)
	{		
		 if(p->next->data == x)
		{
			q = p->next;//q���ɾ���ڵ�
			p->next = q->next;//��p�ڵ�������ɾ���Ľڵ�ָ����֮��Ľڵ�
			p = q->next;//p�ƶ�����һ���ڵ�
			free(q);	//�ͷ�q�Ŀռ�									
		}

		//��Ϊx��p�ƶ�����һ���ڵ�
		else p = p->next;		
	}
	return true;
}


//�ݹ�
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







//// ����������
//int main() {
//	LinkList L;
//	InitLNodeH(&L);  // ��ʼ������Ϊ��
//
//	// ����һЩ��������
//	InsertEnd(&L, 3);
//	InsertEnd(&L, 5);
//	InsertEnd(&L, 7);
//	InsertEnd(&L, 5);
//	InsertEnd(&L, 9);
//	InsertEnd(&L, 5);
//	InsertEnd(&L, 10);
//
//	printf("��ʼ����: ");
//	PrintList(L);
//
//	// ����ɾ��ֵΪ5�Ľڵ�
//	int x = 5;
//	DeletLNode(&L, x);
////	DeleteX(&L, x);
//	printf("ɾ��ֵΪ %d �Ľڵ������: ", x);
//	PrintList(L);
//
//	return 0;
//}






//int main()
//{
//	return 0;
//}
//


