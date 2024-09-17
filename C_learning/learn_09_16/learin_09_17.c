#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "
#include <stdio.h>
int main()
{
	int ascii[] = { 73,32,99,97,110,32,100,111,32,105,116,33 };
	int i=0;
	int sz = sizeof(ascii) / sizeof(ascii[0]);
	for (i=0 ;i <=sz  ; i++)
	{
		printf("%c\n", ascii[i]);
	}
 
	return 0;
	
}