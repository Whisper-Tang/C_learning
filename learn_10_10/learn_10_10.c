#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct SqNode
{
	int data;
	struct SqNode* next;
}SqNode,*LinkList;


//��ͷ���
LinkList UpdownMerge(LinkList* A, LinkList* B)
{
	LinkList C = NULL;
	SqNode* a = *A, * b = *B;
	SqNode* temp;
	while (a && b)
	{
		//tempȡ����С�Ľ��
		if (a->data <= b->data)
		{
			temp = a;
			a = a->next;
		}
		else
		{
			temp = b;
			b = b->next;
			
		}
		//���뵽C��һ�����֮ǰ��ͷ�巨������룩
		temp->next = C;

		//���µ�һ�����
		C = temp;
	}

	//��δ������Ķ���ͷ����c��ͷ�巨������룩
	while(b)
	{
		temp = b;
		b = b->next;

		temp->next = C;
		C = temp;

	}
	while (a)
	{
		temp = a;
		a = a->next;

		temp->next = C;
		C = temp;

	}

	return C;

}

int main() {
	// �����������������A��B���в���
	SqNode n1 = { 1, NULL }, n2 = { 3, NULL }, n3 = { 5, NULL };
	SqNode n4 = { 2, NULL }, n5 = { 4, NULL }, n6 = { 6, NULL };
	n1.next = &n2;
	n2.next = &n3;
	n4.next = &n5;
	n5.next = &n6;

	LinkList A = &n1;
	LinkList B = &n4;

	// �ϲ�����
	LinkList C = UpdownMerge(&A, &B);

	// ��ӡ�ϲ��������
	SqNode* p;
	for (p = C; p; p = p->next)
	{
		printf("%d->", p->data);
	}
	printf("NULL\n");
	return 0;
}




//ɵ��git���ͳ�ͻ��һֱ��ʾ�ϲ��У��ϲ�������
//ɵ��git���ͳ�ͻ��һֱ��ʾ�ϲ��У��ϲ�������
//ɵ��git���ͳ�ͻ��һֱ��ʾ�ϲ��У��ϲ�������
// //ɵ��git���ͳ�ͻ��һֱ��ʾ�ϲ��У��ϲ�������
// //ɵ��git���ͳ�ͻ��һֱ��ʾ�ϲ��У��ϲ�������
//ɵ��git���ͳ�ͻ��һֱ��ʾ�ϲ��У��ϲ�������