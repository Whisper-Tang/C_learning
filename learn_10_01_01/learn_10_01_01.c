#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
#include <Stack_Queue.h>


//�赥����ı�ͷָ��ΪL�����ṹ��data��next�����򹹳ɣ�����data��Ϊ�ַ���.
//������㷨�жϸ������ȫ��n ���ַ��Ƿ����ĶԳơ����� xyx�� xyyx�������ĶԳơ�

//���嵥����ڵ�
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode, *LinkList;

//��ʼ��������(��ͷ���)
bool InitLinkList(LinkList* L)
{
	*L = NULL;
	return true;
}

//����������½ڵ㣬
bool InsertLinkList(LinkList* L,ElemType x)
{
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	if (p == NULL)
		return false;
	p->data = x;
	p->next = *L;
	*L = p;
	return true;
}


bool MirroEmpty(LinkList L, int n) 
{
	if (L == NULL || L->next == NULL)
		return true;	//�ձ�����һ��Ԫ�صı���Ȼ�Գơ�

	SqStack temp;
	if (!InitSqStack(&temp))
		return false;
	LinkNode* p = L;

	for (int i = 0; i < (n / 2); i++)
	{
		PushSqStack(&temp, p->data);
		p = p->next;
	}

	//p = p->next;
	if (1 == n % 2)
		p = p->next;

	while (p != NULL && !SqStackEmpty(temp))
	{
		ElemType compare=0;
		PopSqStack(&temp, &compare);
		if (compare != p->data)
			return false;
		p = p->next;
	}


	return true;

}

int main()
{
	return 0;

}


