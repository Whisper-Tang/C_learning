#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//����һ����̬��˳���
#define MaxSize 10
typedef struct
{
	int data[MaxSize];
	int length;
} SqList;

//��ʼ��˳���
bool InitSqList(SqList* L)
{
	for (int i = 0; i < MaxSize; i++)
	{
		L->data[i] = 0;
	}
	L -> length = 0;
	return true;
}

//���Ա�(a), a2, as,"��", an)�е�Ԫ�ص��������Ұ�˳��洢�ڼ������,
//Ҫ�����һ���㷨�����������ʱ���ڱ��в�����ֵΪx��Ԫ�أ�
//���ҵ�����������Ԫ��λ���ཻ����
//���Ҳ��������������в�ʹ����Ԫ���Ե�������

//1.��˳����i��Ԫ�غ�(�±�Ϊi)����һ��Ԫ��x
bool IsertNextSqlist(SqList *L,int i,int x)	
{
	if (i < 0 || i > L->length || L->length == MaxSize)//i=0ʱΪ��һ��λ�ò��룻i=��ʱΪ����ĩβ���룻����ʱ�޷�����
		return false;			
	for (int k=0; k <= L->length - 1 - i; k++)	////��˳����ĩβ��ʼ��������ƶ�һλ��ֱ����i+1���±�Ϊi����Ԫ�أ�
	{
		L->data[L->length-k] = L->data[L->length - 1 - k];	//��˳����ĩβ��ʼ��������ƶ�һλ��ֱ����i+1��Ԫ�أ�
	}
	L->data[i] = x;
	L->length += 1;
	return true;
}

//2.������ֵΪx��Ԫ�أ����ҵ�������Ϊ��n��Ԫ�أ����Ҳ�����nΪ��ӽ�x����
bool SeachElem(SqList L, int x ,int *n)
{	
	if (0 == L.length)
		return false;
	int mid=0,left = 0;
	int right = L.length - 1;
	while (left <= right)							//���ֲ���
	{
		mid = left + (right - left) / 2;
		if (L.data[mid] < x)	//�м������xС��x���ұߡ�
		{
			left = mid+1;		//�ƶ���ָ�뵽�ұ�
		}
		else if (L.data[mid] > x)	//�м������xС��x����ߡ�
		{
			right = mid-1;	//�ƶ���ָ�뵽���
		}
		else
		{
			*n = mid+1;	//���xλ��
			return true;
		}

	}
	*n = mid+1;		//����ӽ�x��λ��
	return false;
}

//3.�ҵ����ҵ�����������Ԫ��λ���ཻ����
//���Ҳ��������������в�ʹ����Ԫ���Ե�������
bool findx(SqList *L,int x)
{
	if (L->length == 0)
		return false;
	int n = 0;
	if (SeachElem(*L, x, &n))	//�ҵ����ҵ�,����������Ԫ��λ���ཻ����
	{
		if (n = L->length) return true;	//��xΪ���һ��Ԫ�أ������轻����
		int k = L->data[n-1];
		L->data[n-1] = L->data[n];
		L->data[n] = k;
		return true;
	}
	else ////���Ҳ��������������в�ʹ����Ԫ���Ե�������
	{
		if (L->data[n - 1] < x)	//�����x��Ԫ�أ�λ��n������xС��xӦ���뵽��(λ��n)֮��
		{
			IsertNextSqlist(L, n, x);	//���ú�庯������nλ�����
			return true;
		}	
		else if (L->data[n - 1] > x)	//�����x��Ԫ�أ�λ��n������x��xӦ���뵽��ǰ��(λ��n-1)֮��
		{
			IsertNextSqlist(L, n - 1, x);	////���ú�庯������n-1λ�����
			return true;

		}
		else return false;
	}

}


//bool insertSqList(SqList *L)
//{
//	if (L->length == MaxSize)
//		return false;
//	int i = L-> length;
//	int a = 0;
//	while (i < MaxSize)
//	{
//		sacnf("%d ", a);
//		L->data[i++] = a;
//		L->length++;
//	}	
//	return true;
//}
//	



int main()
{
	SqList L;
	InitSqList(&L);
	int x = 0;
	//scanf("%d %d %d %d %d %d %d ", L.data);
	for (int i = 0; i < 8; i++)	//��˳����д洢һЩ����
	{
		int j = i*3+5;
		IsertNextSqlist(&L, i, j);
	}
		
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}

	printf("\n����x\n");
	scanf("%d",&x);

	findx(&L, x);	//ִ�к�������
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	return 0;
}