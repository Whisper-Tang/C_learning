#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MVNum 100  // ��󶥵���

// ͼ���ڽӱ�洢�ṹ
typedef struct ArcNode 
{
    int adjvex;                // �ñ�ָ��Ķ���λ��
    struct ArcNode* nextarc;    // ָ����һ���ߵ�ָ��
} ArcNode;

typedef struct VexNode 
{
    char data;                 // ������Ϣ
    ArcNode* firstarc;         // ָ���һ�������ڸö���ı�
} VexNode, AdjList[MVNum];

typedef struct ALGraph
{
    AdjList vertices;          // �ڽӱ�
    int vexnum, arcnum;        // ͼ�ĵ�ǰ�������ͻ���
} ALGraph;

bool visited[MVNum];           // ��Ƕ����Ƿ񱻷���
int topo[MVNum];               // ���ڴ洢��������Ľ��
int topoIndex;                 // ��¼�������е�����

// �����������
void DFS(ALGraph G, int v)
{
    visited[v] = true;         // ��Ǹö����Ѿ�������

    // ���������ڽӵ�
    ArcNode* p = G.vertices[v].firstarc; 
    while (p) 
    {
        // ����ڽӵ�δ���ʣ��ݹ����
        if (!visited[p->adjvex]) 
            DFS(G, p->adjvex);

        p = p->nextarc;
    }

    // �����ڽӵ㴦����󣬽��ö��������������
    topo[topoIndex--] = v;   
}

// ��������
bool TopologicalSort(ALGraph G)
{
    // ��ʼ���������������
    topoIndex = G.vexnum - 1;   

    // ��ʼ�����ж���δ����
    for (int i = 0; i < G.vexnum; i++)
    {
        visited[i] = false;     
    }

    for (int i = 0; i < G.vexnum; i++) 
    {
        // �������δ���ʣ�����DFS
        if (!visited[i]) 
            DFS(G, i);
    }

    //// �������������
    //printf("Topological Order: ");
    //for (int i = 0; i < G.vexnum; i++) 
    //{
    //    printf("%d ", topo[i]);
    //}
    //printf("\n");

    return true;
}

int main()
{
    return 0;
}
