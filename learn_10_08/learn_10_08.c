#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//�Ե�������м�ѡ������
typedef struct SqNode
{
	int data;
	struct SqNode* next;
}SqNode,*LinkList;

//���赥������ͷ��㣻
LinkList* SortLinkList(LinkList* L)
{
	SqNode* h = L;//��������еĵ�һ�����
	SqNode* premin, * min, * pre, * p;
	
	while (h)	//�Դ�������������
	{
		min = p = h;
		premin = pre = NULL;
		//Ѱ�Ҵ��������Сֵ��㼰��ǰ��
		while (p)
		{

			if (p->data < min->data)
			{
				premin = pre;
				min = p;
			}
			pre = p;
			p = p->next;
		}

		if (premin == NULL|| min == h)//��Сֵ�ǵ�һ��Ԫ��
			h = h->next;	//���������м�һ
		else
		{
			premin->next = min->next;	//ȡ����Сֵ;

			//��Сֵ���뵽h��
			min->next = h->next;
			h->next = min;

			h = h->next;	//���������м�һ
		}
		
	}

return L;

}