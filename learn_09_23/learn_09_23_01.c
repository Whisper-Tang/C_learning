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
		p = p->next;
	}

	k_data = (*list)->data;	//���dataֵ
	return 1;	//����1
}

//������
int GetK(LinkList* list, int k)
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
