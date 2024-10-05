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

int main()
{
	return 0;
}

//�ڽӱ�ת��Ϊ�ڽӾ���
//for (int i = 0; i < vexsum; i++)
//{
//	ArcNode* p = AdjList[i].firstArc;
//	while (p)
//	{
//		Graph.arcs[i][p->adjvex] = p->info;
//		p = p->nextarc;
//	}
//}


//������ȱ���ȴ�Ľ��k�ͷ���k������
int printVertices(AMGraph G)
{
	int num = 0;
	for (int row = 0; row < G.vexnmu; row++)
	{
		int out = 0, in = 0;
		for (int col = 0; col < G.vexnmu; col++)
		{
			if (G.arcs[row][col] != 0 || G.arcs[row][col] != MaxInt)		//��row�к�
				out++;
			if (G.arcs[col][row] != 0 || G.arcs[col][row] != MaxInt)		//��row�к�
				in++;
		}
		if (out > in)	//�кʹ����кͣ���������
		{
			printf("%c", G.vexs[row]);	//�����������һ
			num++;
		}
			
	}
	return num;
}


//����ͼ���Ƿ��ж���vi��vj��·��
bool visited[MVNum];
bool isRoad(ALGraph G, int i, int j)
{
	visited[i] = true;	// ��Ƕ���i�Ѿ�����
	ArcNode* p = G.vertices[i].firstarc;	// ��ȡ����i�ĵ�һ����

	while(p)	// ��������i�������ڽӵ�
	{
		if (p->adjvex == j)	//i�ĵ�һ���ڽӵ����j
			return true;
		else if (visited[p->adjvex] == false)	//i�ĵ�һ���ڽӵ㲻��j����δ�����ʹ�
			return isRoad(G, p->adjvex, j);	 // �ݹ���Ӹ��ڽӵ㵽j�Ƿ���·��
		p = p->nextarc;	// �����һ���ڽӵ�
	}
	return false;
}

//���ִ洢�ṹ
// 
// ����ͼ����ͼ�����ڽӾ����ڽӱ�
// ʮ����������ͼ�����ڽӶ��ر�����ͼ��

//ͼ�����ֱ���������������ȱ���BFS��������ȱ���DFS(��Ϊ��:O(n^2)�ͱ�:O(n+e))

//ͼ��Ӧ��
// 
//��С��������Prime�㷨��Kruskal�㷨����:O(e log e)��
// 
//���·����	BFS��ȨֵΪ1��	Dijkstra���޸�Ȩֵ��	Floyd���޴���Ȩֵ�Ļ���
//ʱ�临�Ӷ�		O(n^2)			O(n^2)				O(n^3)
// 
//�������򡪡������޻�ͼ���ؼ�·��(��Ϊ��:O(n^2)�ͱ�:O(n+e))