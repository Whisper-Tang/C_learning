#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//ͼ�Ĵ洢�ṹ
#define MaxInt 32767	//��ʾ����ֵ���൱�ڡޣ�
#define MVNum 100	//������󶥵���Ϊ100
typedef char VerTexType ;	//���� ��������Ϊchar
typedef int ArcTypen,OtherInfo;	//�� ��Ȩֵ����Ϊint


//�ڽӾ���
//�洢��ʾ
typedef struct AMGraph
{
	VerTexType vexs[MVNum];		//�����㣨�洢���㣩
	ArcTypen arcs[MVNum][MVNum];	//����ߣ��ڽӾ���
	int vexnmu, arcnum;		//���ڼ�¼��ǰ���㣬�ߵ�����
}AMGraph;



//�ڽӱ�
//����Ĵ洢��ʾ
typedef struct VexNode
{
	VerTexType data;	//�洢������Ϣ
	struct ArcNode* firstarc;	//ָ��A�����г��� �ĵ�һ����

}VexNode,AdjList[MVNum];		//VexNode��ʾ���㣬��AdjList��ʾ�����ڽӱ�,���������MVNum��VexNode
//�ߵĴ洢��ʾ
typedef struct ArcNode
{
	int adjvex;		//ָ��������ָ��Ķ��㣨A->B��A->C,��洢B���±꣩
	struct ArcNode* nextarc;	//ָ����һ���ߣ�A->B,A->C,��ָ��AC֮��ıߣ�
	OtherInfo info;		//�洢�ߵ���Ϣ����Ȩֵ��A->B֮��ߵ�Ȩֵ�ȱ��������Ϣ��
}ArcNode;
//�ڽӱ��ʾ
typedef struct ALGraph
{
	AdjList vertices;
	int vexnum, arcnum;		//ͼ��Ŀǰ�Ķ��㡢�ߵĸ���
}ALGraph;


