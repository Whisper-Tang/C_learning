#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#


#include <Stack_Queue.h>
////栈，
////定义栈（顺序表形式）
//typedef struct {	
//	ElemType* base;
//	ElemType* top;
//	int stacksize;
//}SqStack;

//初始化顺序栈
bool InitSqStack(SqStack* S)
{
	S->base = (ElemType*)malloc(MaxSize * sizeof(ElemType));
	if (S->base == NULL)
		return false;
	S->top = S->base;	// 初始化栈顶指针，栈顶指针指向下一个值的入栈位置
	S->stacksize = MaxSize; // 栈的最大容量
	return true; // 确保返回值
}
//判断空栈
bool SqStackEmpty(SqStack S)
{
	if (S.base == NULL)
		return false;	//输入值有误
	return S.base == S.top/*? true : false*/;	//栈空为true，否则为false
}
//入栈（顺序栈）
bool PushSqStack(SqStack* S, ElemType a)
{
	if (S->top - S->base >= S->stacksize || S->base == NULL)
		return false;
	*S->top++ = a;
	return true;
}

//出栈（顺序栈）
bool PopSqStack(SqStack* S, ElemType* x)
{
	if (S->top == S->base || S->base == NULL)
		return false;
	*x = *--S->top;
	return true;
}

//获取栈顶元素（顺序栈）
bool GetSqStack(SqStack* S, ElemType* x)
{
	if (S->top == S->base || S->base == NULL)
		return false;
	*x = *((S->top) - 1);
	return true;
}
// 
// 

////定义链栈结点
//typedef struct StackNode {
//	ElemType data;
//	struct StackNode* next;
//}StackNode, * LinkStack;

//初始化链栈
bool InitLinkStack(LinkStack* S)
{
	*S = NULL;
	return true;
}
//{
//	StackNode* base = (StackNode*)malloc(sizeof(StackNode));
//	if (base == NULL)
//		return false;
//	base->data = 0;
//	base->next = NULL;
//	StackNode* top = base;
//	reture true;
//}

//判断链栈是否为空
bool LinkStackEmpty(LinkStack S)
{
	return S != NULL;
}

//入栈(链栈)
bool PushLinkStack(LinkStack* S, ElemType a)
{
	StackNode* top = (StackNode*)malloc(sizeof(StackNode));
	if (top == NULL)
		return false;
	//S = top;	//应使用头插法，方便出栈时，栈顶S回到上一个节点
	//top->next = NULL;
	top->next = *S;
	top->data = a;
	*S = top;
	return true;
}

//出栈（链栈）
bool PopLinkStack(LinkStack* S, ElemType* x)
{
	if (*S == NULL)
		return false;
	StackNode* temp = *S;
	*x = temp->data;
	*S = temp->next;
	free(temp);
	return true;
}

//获取链栈顶元素
bool GetLinkStack(LinkStack S, ElemType* x)
{
	if (S == NULL)
		return false;
	*x = S->data;
	return true;
}


















