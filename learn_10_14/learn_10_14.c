#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//��ָ֪��ha��hb�ֱ�ָ�������������ͷ��㣬������֪����������ֱ�Ϊm��n��
//��дһ���㷨������������������һ��
//����ָ��hcָ�����Ӻ�������ͷ��㣻

typedef struct LNode
{
	int* data;
	struct LNode* next;
}LNode,*LinkList;

LinkList MergeSqList(LinkList* ha, LinkList* hb,int m,int n)
{
	//b��̵���ǰ�棬ʡʱ��
	LNode* Short = m < n ? *ha : *hb;
	LinkList hc = Short;
	LNode* Long = m < n ? *hb : *ha;

	//�ҵ��̱�ı�β�ͽ��
	while (Short->next)
	{
		Short = Short->next;
	}
	
	//Խ������ͷ��㣬����Ԫ�����ڶ̱���
	Short->next = Long->next;

	free(Long);//�ͷ�ͷ���

	return hc;//�ϻغϲ���ı�
}