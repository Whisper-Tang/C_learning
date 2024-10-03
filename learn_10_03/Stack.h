#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MaxSize_ElemType.h"

//栈，
//定义栈（顺序表形式）
typedef struct {
	ElemType* base;
	ElemType* top;
	int stacksize;
}SqStack;

//顺序栈操作：
bool InitSqStack(SqStack* S);	//初始化顺序栈
bool SqStackEmpty(SqStack S);	//判断空栈
bool PushSqStack(SqStack* S, ElemType a);	//入栈（顺序栈）
bool PopSqStack(SqStack* S, ElemType* x);	//出栈（顺序栈）
bool GetSqStack(SqStack* S, ElemType* x);	//获取栈顶元素（顺序栈）

//定义链栈结点
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;
//链栈操作
bool InitLinkStack(LinkStack* S);	//初始化链栈
bool LinkStackEmpty(LinkStack S);	//判断链栈是否为空
bool PushLinkStack(LinkStack* S, ElemType a);	//入栈(链栈)
bool PopLinkStack(LinkStack* S, ElemType* x);	//出栈（链栈）
bool GetLinkStack(LinkStack S, ElemType* x);	//获取链栈顶元素