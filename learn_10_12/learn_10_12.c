#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIST_INIT_SIZE 100
//��˳���va�е�����Ԫ�ص���������дһ�㷨����x���뵽˳�����ʵ�λ��
typedef struct
{
	int* elem;
	int length;
	int listsize;
}SqList;

bool InitSqList(SqList* L)
{
	(*L).elem = (int*)malloc(sizeof(int) * LIST_INIT_SIZE);
	if (!(*L).elem)
		return false;
	for (int i = 0; i < LIST_INIT_SIZE; i++)
	{
		(*L).elem[i] = 0;
	}
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
	return true;
}

bool InsertSqListSort(SqList* L,int x)
{
	//�����ڣ�δ��ʼ��������ʱ�����ش���
	if (!L || !(*L).elem||(*L).length==(*L).listsize)
		return false;
	int i = 0;
	int len = (*L).length;

	//�ҵ���һ������x��elem���±�i
	for (i; i < len && (*L).elem[i] <= x; i++);

	//��i����֮���Ԫ�غ��ƣ��ճ��±�Ϊi��λ��
	for (len; len>i; len--)
	{
		(*L).elem[len] = (*L).elem[len - 1];	
	}

	//����i��ͬʱ��+1
	(*L).elem[i] = x;
	(*L).length++;

	return true;
}