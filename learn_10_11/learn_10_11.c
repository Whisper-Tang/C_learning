#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//��֪��������A��B�ֱ��ʾ�������ϣ���Ԫ�ص������С�
// �����һ���㷨���������A��B�Ľ������������A�����С�

typedef struct SqNode
{
	int data;
	struct SqNode* next;
}SqNode, *LinkList;

bool AUB(LinkList* A, LinkList* B)
{
	SqNode* a = *A, * b = *B;
	//����һ���ǿռ�,�򷵻�ձ�A	//ע��[1]
	if (!a)
		return true;
	if (!b)
	{
		while(a)
		{
			SqNode* temp = a;
			a = a->next;
			free(temp);
		}
		return true;
	}

	//��AB���ǿ�
	SqNode* ra = NULL;
	while (a && b)
	{
		if (a->data == b->data)
		{
			ra = a;
			a = a->next;
		}
		else if (a->data > b->data)
		{
			b = b->next;
		}
		else if (a->data < b->data)
		{
			//���a��ǰ����ǰ������a��ָ����һ�����	//ע��[2]
			if (ra)
				ra->next = a->next;

			//ȡ��a��ɾ��
			SqNode* temp = a;
			a = a->next;
			free(temp);			
		}			
	}

	//���a����ʣ��������ɾ��	//ע��[3]
	while (a)
	{
		SqNode* temp = a;
		a = a->next;
		free(temp);
	}

	return true;


}

//ע��[1]
//��ĿҪ�󽻼��洢��A�У�һ������ΪNULLʱ������Ϊ�ռ���������A�д洢�ռ�

//ע��[2]
//AB�������ͷ��㣬��aָ���һ���������Ҫɾ��ʱ��ra��һֱ����NULL״̬�����Կ���
//ȡ��a��ɾ�� 
//SqNode* temp = a;
//a = a->next;
//free(temp);
//��a����ָ���һ�����ʱ��ra��ָ��ǰ������ʱ��δ������ȷ����֤�������
//���a��ǰ����ǰ������a��ָ����һ�����
//if (ra)
//ra->next = a->next;

//ע��[3]
//while (a && b)������ΪB���������Aδ�����������ѭ��
//��ʱA��ʣ��δ����Ԫ�ؾ���aָ��֮�󣨰���a��������ЩԪ�ؾ�����������AB����