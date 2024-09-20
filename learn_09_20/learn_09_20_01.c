#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//定义一个静态的顺序表
#define MaxSize 10
typedef struct
{
	int data[MaxSize];
	int length;
} SqList;

//初始化顺序表
bool InitSqList(SqList* L)
{
	for (int i = 0; i < MaxSize; i++)
	{
		L->data[i] = 0;
	}
	L -> length = 0;
	return true;
}

//线性表(a), a2, as,"…", an)中的元素递增有序且按顺序存储于计算机内,
//要求设计一个算法，完成用最少时间在表中查找数值为x的元素，
//若找到，则将其与后继元素位置相交换，
//若找不到，则将其插入表中并使表中元素仍递增有序。

//1.在顺序表第i个元素后(下标为i)插入一个元素x
bool IsertNextSqlist(SqList *L,int i,int x)	
{
	if (i < 0 || i > L->length || L->length == MaxSize)//i=0时为第一个位置插入；i=表长时为在最末尾插入；表满时无法插入
		return false;			
	for (int k=0; k <= L->length - 1 - i; k++)	////将顺序表从末尾开始依次向后移动一位，直到第i+1（下标为i）个元素，
	{
		L->data[L->length-k] = L->data[L->length - 1 - k];	//将顺序表从末尾开始依次向后移动一位，直到第i+1个元素，
	}
	L->data[i] = x;
	L->length += 1;
	return true;
}

//2.查找数值为x的元素，若找到返回其为第n个元素，若找不到则n为最接近x的数
bool SeachElem(SqList L, int x ,int *n)
{	
	if (0 == L.length)
		return false;
	int mid=0,left = 0;
	int right = L.length - 1;
	while (left <= right)							//二分查找
	{
		mid = left + (right - left) / 2;
		if (L.data[mid] < x)	//中间的数比x小，x在右边。
		{
			left = mid+1;		//移动左指针到右边
		}
		else if (L.data[mid] > x)	//中间的数比x小，x在左边。
		{
			right = mid-1;	//移动右指针到左边
		}
		else
		{
			*n = mid+1;	//输出x位置
			return true;
		}

	}
	*n = mid+1;		//输出接近x的位置
	return false;
}

//3.找到若找到，则将其与后继元素位置相交换，
//若找不到，则将其插入表中并使表中元素仍递增有序。
bool findx(SqList *L,int x)
{
	if (L->length == 0)
		return false;
	int n = 0;
	if (SeachElem(*L, x, &n))	//找到若找到,，则将其与后继元素位置相交换，
	{
		if (n = L->length) return true;	//若x为最后一个元素，则无需交换。
		int k = L->data[n-1];
		L->data[n-1] = L->data[n];
		L->data[n] = k;
		return true;
	}
	else ////若找不到，则将其插入表中并使表中元素仍递增有序。
	{
		if (L->data[n - 1] < x)	//最相近x的元素（位置n）若比x小，x应插入到他(位置n)之后
		{
			IsertNextSqlist(L, n, x);	//引用后插函数，在n位后插入
			return true;
		}	
		else if (L->data[n - 1] > x)	//最相近x的元素（位置n）若比x大，x应插入到他前驱(位置n-1)之后
		{
			IsertNextSqlist(L, n - 1, x);	////引用后插函数，在n-1位后插入
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
	for (int i = 0; i < 8; i++)	//在顺序表中存储一些数据
	{
		int j = i*3+5;
		IsertNextSqlist(&L, i, j);
	}
		
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}

	printf("\n输入x\n");
	scanf("%d",&x);

	findx(&L, x);	//执行函数测试
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	return 0;
}