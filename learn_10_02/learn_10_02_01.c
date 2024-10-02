#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#

#include "Stack.h"
#include "Queue.h"


int main() {
	return 0;
}

//假设一个算术表达式中包含圆括号、方括号和花括号3种类型的括号，
// 编写一个算法来判别表达式中的括号是否配对，以字符“\0”作为算术表达式的结束符。


bool CheckChar(char C[])
{
	//创建一个工作栈
	SqStack check;
	InitSqStack(&check);

	for (int i = 0; C[i] != '\0'; i++)
	{
		char temp ;
		switch (C[i])
		{
		//当遇到'(','[','{'时压入栈，
		case '(':
		case '[':
		case '{':
			PushSqStack(&check, C[i]);
			break;
		//当遇到')',']','}'时弹出栈顶元素对比
		case ')':
		case ']':
		case '}':
			//if (SqStackEmpty(check))
			//	return false;
			//PopSqStack(&check, &temp);//栈顶元素temp若能匹配则必为左括号
			if (PopSqStack(&check, &temp) || C[i] != temp)//栈空PopSqStack值为假
				return false;	//不对应时，不匹配
			break;
		default: break;
		}//switch		
		//对应则继续检测下一个符号
	}//for
	return SqStackEmpty(check) ? true : false;
}



//树的总度数+1=树的结点数
//度为m，结点数为n的树，
// 最小高度：h(min) = 以m为底(n(m-1)+1)的对数，
// 最大高度：h(max) = n-m+1
//高度为h的m叉树，最多有 ( (m的k次方) - 1 ) ( m - 1 ) )个结点