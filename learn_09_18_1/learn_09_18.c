#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct LNode			//���嵥����ڵ�����
{
	int data;					//�ڵ��д�ŵ�����Ԫ��
	struct LNode* next;
}LNode, * LinkList;				//������struct LNodeΪLNode��struct LNode *ΪLinkList

////��ʼ��һ������������ͷ�ڵ㣩
// bool InitLNode(LinkList *L)	//�����ʼ��InitLNode����
//{
//	L = NULL;					//�����ʼ��Ϊ�ձ�
//	return true;
//}

//��ʼ��һ������������ͷ�ڵ㣩
bool InitLNode(LinkList *L)		//�����ʼ��InitLNode����
{
	*L = (struct LNode *)malloc(sizeof(LNode)); //������ͷ�ڵ�����ڴ�
	if ( *L == NULL )		
		return false;			// ����ʧ�ܣ�����false
	(*L)->next = NULL;			// ��ʼ��ͷ�ڵ��nextָ��
	return true;				// ��ʼ���ɹ�������true
}

//static void test()
//{
//	LinkList L ;//����һ��ָ�������ָ��
//	InitLNode(L);				//��ʼ���ձ�
//}


int main()
{
	LinkList L;
	//InitLNode(&L);
	if (InitLNode(&L)) {   // ʹ��ָ�봫������ͷ
		printf("�����ʼ���ɹ���\n");
	}
	else {
		printf("�����ʼ��ʧ�ܡ�\n");
	}
	//// ע�⣺�ǵ����ʵ���ʱ���ͷ��ڴ�
	//if (L != NULL)
	//	free(L);  // �ͷŶ�̬������ڴ�
	return 0;
	//�������ڵ��ļ��ύ����


}

