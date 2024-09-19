#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�������к������ر�ɾ����Ԫ�ص�ֵ��
//��λ�����һ��Ԫ�������˳���Ϊ�գ�����ʾ������Ϣ���Ƴ�����

//����˳���
//#define MaxSize 10
#define InitSize 10
typedef struct SqList {
	//int data[MaxSize];
	int *data;
	int MaxSize;
	int length;
}SqList;


//��ʼ��˳���
bool InitSqlist(SqList *L)
{
	L->data = (int*)malloc(sizeof(int) * InitSize);		//����ռ䣬Ĭ��Ϊ10
	
	if (!L->data)
		return false;									//�ռ�����ʧ��
	L->MaxSize = InitSize;
	for (int i = 1; i <= L->MaxSize; i++)
	{
		L->data[i - 1] = 0;
	}
	L->length = 0;
	return true;
}


//��̬����˳���ı�������len����
bool IncreaseSize(SqList* L, int len)
{
	int* p = L->data;
	L->data = (int*)malloc(sizeof(int) * (L->MaxSize+len));//˳�������һƪ�µĿռ䣬�ռ��С����len
	if (!L->data)
		return false;									//�ռ�����ʧ��,������ʧ��
	for (int i = 1; i <= L->length; i++)				//��ԭ�ռ�˳������ݱ����ƶ����±�ռ�
	{
		L->data[i - 1] = p[i - 1];
	}
	L->MaxSize = L->MaxSize + len;						//˳�����󳤶�����len
	for (int i = L->length+1; i <= L->MaxSize; i++)		//˳��������λ�ó�ʼ��Ϊ0
	{
		L->data[i - 1] = 0;
	}
	free(p);											//�ͷ�ԭ���ݱ��ſռ�
	return true;
}

//��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�������к������ر�ɾ����Ԫ�ص�ֵ��
//��λ�����һ��Ԫ�������˳���Ϊ�գ�����ʾ������Ϣ���Ƴ�����
bool DeletMinElem(SqList *L, int *min)
{
	if (L->length == 0)									//�ж��Ƿ�Ϊ�ձ�
			return false;								//�ձ��ش��󲢽�������
	min = L->data[0];
	int min_num = 0;									//Ԥ��0��Ԫ��Ϊ��Сֵ����¼�±�0
	for (int i = 1; i <= L->length; i++)				//����˳����ҵ���Сֵ
	{
		if (min > L->data[i-1])							//��ǰ��Сֵ��˳�����ÿһ��Ԫ�����Ƚ�
		{
			min = L->data[i - 1];						//����С��ֵ�洢��min
			min_num = i - 1;							//��¼��ǰ��Сֵ�±굽min_num
		}
	}
	L->data[min_num] = L->data[L->length - 1];			//����СԪ��λ�������һ��Ԫ�ظ���ɾ��
	L->length--;										//�����1
	return true;										//ɾ����ɡ�
}


//���һ���㷨����˳�������Ԫ�����ã�Ҫ���㷨�ռ䰴���Ӷ�ΪO(1).
bool UpsetSqList(SqList* L)
{
	if (L->length == 0)									//�ж��Ƿ�Ϊ�ձ�
		return false;									//�ձ��ش��󲢽�������
	////int* p = L->data;									//ָ��pָ������Ԫ������
	////L->data = (int*)malloc(sizeof(int) * L->MaxSize);	//�����¿ռ����ڴ�����ú��Ԫ�أ�����˳���ͷָ��ָ���¿ռ�
	////if (!L->data)
	////	return false;									//�ռ�����ʧ��,	
	//int len = L->length;
	//if (len % 2 == 1)
	//	len -= 1;
	//for (int i = 0; i < len/2 ; i++)

	int trans = 0;
	for (int i = 0; i < L->length; i++)
	{	
		trans = L->data[i];
		L->data[i] = L->data[L->length - 1 - i];
		L->data[L->length - 1 - i] = trans;
	}
	//free(p);											//�ͷ�P���ռ�
	return true;										//�������
}