#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "
#include <stdio.h>

//使用递归函数求解斐波那契数列
int Fd(int x)
{
	if (x < 0)
	{
		printf("输入数据有误，x需要>=0\n");//数据错误时报错并返回-999
		return -999;
	}
	else
	{
		switch (x)
		{
		case 0: return 0;//f(0)=0
		case 1: return 1;//f(1)=1
		default: return Fd(x - 1) + Fd(x - 2);//当n>1时，f(n)=f(n-1)+f(n-1)
		}
	}	
}

//使用循环求解斐波那契数列
int Fx(int x)
{
	if (x < 0)
	{
		printf("输入数据有误，x需要>=0\n");//数据错误时报错并返回-999
		return -999;
		
	}
	else
	{
		int fn = 0;
		int fn_1 = 1;
		int fn_2 = 0;
		switch (x)						//n=0,1时直接返回f(0),f(1)
		{
			case 0:return 0;
				break;
			case 1:return 1;
				break;
			default:break;
		}
		for (int i = 2; i <= x; i++)	//n>=2时求fn
		{
			fn = fn_1 + fn_2;
			fn_2 = fn_1;				//本次循环n-1为下次循环的n-2
			fn_1 = fn;					//本次循环n为下次循环的n-1	
		}
		return fn;
		
	};


}

//int F(int x)
//{
//	x = x + 1;
//	return x;
//}

int main()
{
	int x = 0, fx = 0, i = 0;
	scanf("%d", &x);
	printf("\n通过递归：计算斐波那契数列：");
	for (i = 0; i <= x; i++)
	{
		//printf("通过递归：计算斐波那契数列：f(%d)=%d\n", i, Fd(i));
		printf("%d ", Fd(i));
	}
	printf("\n通过循环：计算斐波那契数列：");
	for (i = 0; i <= x; i++)
	{
		//printf("通过循环：计算斐波那契数列：f(%d)=%d\n", i, Fx(i));
		printf("%d ", Fx(i));
	}
	
	return 0;
}
