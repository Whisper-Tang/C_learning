#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#

#include "Stack.h"
#include "Queue.h"


int main() {
	return 0;
}

//����һ���������ʽ�а���Բ���š������źͻ�����3�����͵����ţ�
// ��дһ���㷨���б���ʽ�е������Ƿ���ԣ����ַ���\0����Ϊ�������ʽ�Ľ�������


bool CheckChar(char C[])
{
	//����һ������ջ
	SqStack check;
	InitSqStack(&check);

	for (int i = 0; C[i] != '\0'; i++)
	{
		char temp ;
		switch (C[i])
		{
		//������'(','[','{'ʱѹ��ջ��
		case '(':
		case '[':
		case '{':
			PushSqStack(&check, C[i]);
			break;
		//������')',']','}'ʱ����ջ��Ԫ�ضԱ�
		case ')':
		case ']':
		case '}':
			//if (SqStackEmpty(check))
			//	return false;
			//PopSqStack(&check, &temp);//ջ��Ԫ��temp����ƥ�����Ϊ������
			if (PopSqStack(&check, &temp) || C[i] != temp)//ջ��PopSqStackֵΪ��
				return false;	//����Ӧʱ����ƥ��
			break;
		default: break;
		}//switch		
		//��Ӧ����������һ������
	}//for
	return SqStackEmpty(check) ? true : false;
}



//�����ܶ���+1=���Ľ����
//��Ϊm�������Ϊn������
// ��С�߶ȣ�h(min) = ��mΪ��(n(m-1)+1)�Ķ�����
// ���߶ȣ�h(max) = n-m+1
//�߶�Ϊh��m����������� ( (m��k�η�) - 1 ) ( m - 1 ) )�����