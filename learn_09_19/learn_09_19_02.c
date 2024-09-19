#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//从顺序表中删除具有最小值的元素（假设唯一），并有函数返回被删除的元素的值。
//空位由最后一个元素填补，若顺序表为空，则显示错误信息并推出运行

//定义顺序表
//#define MaxSize 10
#define InitSize 10
typedef struct SqList {
	//int data[MaxSize];
	int *data;
	int MaxSize;
	int length;
}SqList;


//初始化顺序表
bool InitSqlist(SqList *L)
{
	L->data = (int*)malloc(sizeof(int) * InitSize);		//申请空间，默认为10
	
	if (!L->data)
		return false;									//空间申请失败
	L->MaxSize = InitSize;
	for (int i = 1; i <= L->MaxSize; i++)
	{
		L->data[i - 1] = 0;
	}
	L->length = 0;
	return true;
}


//动态增加顺序表的表长，增加len长度
bool IncreaseSize(SqList* L, int len)
{
	int* p = L->data;
	L->data = (int*)malloc(sizeof(int) * (L->MaxSize+len));//顺序表申请一篇新的空间，空间大小增加len
	if (!L->data)
		return false;									//空间申请失败,表长增加失败
	for (int i = 1; i <= L->length; i++)				//将原空间顺序表数据遍历移动到新表空间
	{
		L->data[i - 1] = p[i - 1];
	}
	L->MaxSize = L->MaxSize + len;						//顺序表最大长度增加len
	for (int i = L->length+1; i <= L->MaxSize; i++)		//顺序表空数据位置初始化为0
	{
		L->data[i - 1] = 0;
	}
	free(p);											//释放原数据表存放空间
	return true;
}

//从顺序表中删除具有最小值的元素（假设唯一），并有函数返回被删除的元素的值。
//空位由最后一个元素填补，若顺序表为空，则显示错误信息并推出运行
bool DeletMinElem(SqList *L, int *min)
{
	if (L->length == 0)									//判断是否为空表
			return false;								//空表返回错误并结束运行
	min = L->data[0];
	int min_num = 0;									//预设0号元素为最小值，记录下标0
	for (int i = 1; i <= L->length; i++)				//遍历顺序表，找到最小值
	{
		if (min > L->data[i-1])							//当前最小值与顺序表中每一个元素作比较
		{
			min = L->data[i - 1];						//将更小的值存储到min
			min_num = i - 1;							//记录当前最小值下标到min_num
		}
	}
	L->data[min_num] = L->data[L->length - 1];			//当最小元素位置用最后一个元素覆盖删除
	L->length--;										//表长算短1
	return true;										//删除完成。
}


//设计一个算法，将顺序表所有元素逆置，要求算法空间按复杂度为O(1).
bool UpsetSqList(SqList* L)
{
	if (L->length == 0)									//判断是否为空表
		return false;									//空表返回错误并结束运行
	////int* p = L->data;									//指针p指向现有元素数据
	////L->data = (int*)malloc(sizeof(int) * L->MaxSize);	//申请新空间用于存放逆置后的元素，并将顺序表头指针指向新空间
	////if (!L->data)
	////	return false;									//空间申请失败,	
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
	//free(p);											//释放P处空间
	return true;										//逆置完成
}