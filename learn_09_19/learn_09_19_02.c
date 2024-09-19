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

//对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除顺序表中所有值为x的数据元素。
bool DeletElemX(SqList* L, int x)
{
	if (L->length == 0)							//判断是否为空表
		return false;
	int k = 0;									//定义k记录需要被删除的x数量，用以移动x后的元素
	for (int i = 0; i < L->length; i++)				
	{
		if (L->data[i] = x)						//每找到一个x，其后元素需要额外向前移动1次
			k++;								
		else
			L->data[i - k] = L->data[i];		//非x元素迁移
	}
	L->length -= k;								//删除后顺序表表长缩短k
	return true;
}

//从顺序表中删除其值在给定值s和t之间(包含s和t，要求s<t)的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行。
bool DeletAmongS_T(SqList *L, int s, int t)
{
	if (s >= t || 0 == L->length)				//判断s,t是否合法或顺序表是否为空
		return true;
	int k = 0;									//记录需要保留的元素个数
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i]<s || L->data[i]>t)		//判断是否需要保留
		{
			L->data[k] = L->data[i];			//保留无需删除的元素
			k++;								//保留元素数+1
		}
	}
	L->length = k;								//顺序表长为保留下来的元素数
	return true;
}

//从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
bool DeletSameElem(SqList* L)	//有序表的相同元素均相邻
{
	if (0 == L->length)
		return false;
	int k = 0;									//记录需要删除的元素个数
	for (int i = 1; i < L->length; i++)			//有序顺序表，默认第一个元素前无与之相同元素，从第二位开始检索
	{
		if (L->data[i] == L->data[i - 1])		//从第二位开始检索该元素是否与前一个元素相同
			k++;								//与前一个元素相同，则需要删除的元素+1
		else
			L->data[i - k] = L->data[i];		//与前一个元素不同则向前移动当前意需要删除的元素数
	}
	L->length -= k;								//表长缩短k
	return true;
}

