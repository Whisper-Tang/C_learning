#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct LinkNode
{
	int data;
	struct LinkNode* next;

}LinkNode,*LinkList;

LinkList mergeList(LinkList* A, LinkList* B)
{
	LinkNode* a = *A, * ra = NULL;

	LinkNode* b = *B, *temp;

	while (a && b)
	{

		if (b->data < a->data)
		{
			temp = b->next;	//�ݴ�b�������
			//����a��ǰ��
			if (ra)
			{
				ra->next = b;	//���a����ǰ��������Ҫ��ǰ����b�Լ�a��������
			}
				
			b->next = a;

			b = temp;	//b��λ��
		}
		else if (b->data > a->data)
		{
			ra = a;
			a = a->next;
		}
		else if (b->data == a->data)
		{
			temp = b;	//�ݴ��ظ����
			b = b->next;

			free(temp);	//ɾ���ظ����
		}
			
	}
	if (b)//���b����ʣ�࣬��ȫ����a���ұ���whileѭ����a=NULL�����ģ���a��ǰ��ra��Ȼ����
	{
		//�������ʣ�࣬��ȫ����a
		ra->next = b;
	}
	return *A;

}