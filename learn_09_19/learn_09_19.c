#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "
#include <stdio.h>

//ʹ�õݹ麯�����쳲���������
int Fd(int x)
{
	if (x < 0)
	{
		printf("������������x��Ҫ>=0\n");//���ݴ���ʱ��������-999
		return -999;
	}
	else
	{
		switch (x)
		{
		case 0: return 0;//f(0)=0
		case 1: return 1;//f(1)=1
		default: return Fd(x - 1) + Fd(x - 2);//��n>1ʱ��f(n)=f(n-1)+f(n-1)
		}
	}	
}

//ʹ��ѭ�����쳲���������
int Fx(int x)
{
	if (x < 0)
	{
		printf("������������x��Ҫ>=0\n");//���ݴ���ʱ��������-999
		return -999;
		
	}
	else
	{
		int fn = 0;
		int fn_1 = 1;
		int fn_2 = 0;
		switch (x)						//n=0,1ʱֱ�ӷ���f(0),f(1)
		{
			case 0:return 0;
				break;
			case 1:return 1;
				break;
			default:break;
		}
		for (int i = 2; i <= x; i++)	//n>=2ʱ��fn
		{
			fn = fn_1 + fn_2;
			fn_2 = fn_1;				//����ѭ��n-1Ϊ�´�ѭ����n-2
			fn_1 = fn;					//����ѭ��nΪ�´�ѭ����n-1	
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
	printf("\nͨ���ݹ飺����쳲��������У�");
	for (i = 0; i <= x; i++)
	{
		//printf("ͨ���ݹ飺����쳲��������У�f(%d)=%d\n", i, Fd(i));
		printf("%d ", Fd(i));
	}
	printf("\nͨ��ѭ��������쳲��������У�");
	for (i = 0; i <= x; i++)
	{
		//printf("ͨ��ѭ��������쳲��������У�f(%d)=%d\n", i, Fx(i));
		printf("%d ", Fx(i));
	}
	
	return 0;
}
