#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIST_INIT_SIZE 100

typedef struct
{
	int* elem;
	int length;
	int listsize;
}SqList;


//˳���ABȥ�����ͬǰ׺��ʣ��ı�A*��B*��
//��A*��B*��Ϊ�ձ���A=B��
//���A*Ϊ�գ�B*��Ϊ�գ��������߶���Ϊ�ձ���A*��ԪС��B*��Ԫ����A<B;
//����A>B

//��дһ���Ƚ��㷨���Ƚ�AB��С���������ƻ�ԭ��AB

int CompareA_B(SqList A, SqList B)
{
	int a = 0;
	int b = 0;

	//�����ҵ���һ������ȵ�Ԫ���±�a,b
	for (a, b; A.elem[a] == B.elem[b] && a < A.length && b < B.length; a++, b++);

	//A*B*��
	int remain_A = A.length - a;
	int remain_B = B.length - b;

	//A*B*��Ϊ�ձ���A=B�����0
	if (!remain_A && !remain_B)
		return 0;
	//A*�գ�B*�ǿ� �� ���߶���Ϊ�ձ���A*��ԪС��B*��Ԫ�� ��A<B; ����-1
	else if ((!remain_A && remain_B) || (remain_A && remain_B && A.elem[a] < B.elem[b]))
		return -1;
	//����A>B������1
	else
		return 1;
	
}