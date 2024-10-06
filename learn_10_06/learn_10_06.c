#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MVNum 100  // 最大顶点数

// 图的邻接表存储结构
typedef struct ArcNode 
{
    int adjvex;                // 该边指向的顶点位置
    struct ArcNode* nextarc;    // 指向下一条边的指针
} ArcNode;

typedef struct VexNode 
{
    char data;                 // 顶点信息
    ArcNode* firstarc;         // 指向第一条依附于该顶点的边
} VexNode, AdjList[MVNum];

typedef struct ALGraph
{
    AdjList vertices;          // 邻接表
    int vexnum, arcnum;        // 图的当前顶点数和弧数
} ALGraph;

bool visited[MVNum];           // 标记顶点是否被访问
int topo[MVNum];               // 用于存储拓扑排序的结果
int topoIndex;                 // 记录拓扑序列的索引

// 深度优先搜索
void DFS(ALGraph G, int v)
{
    visited[v] = true;         // 标记该顶点已经被访问

    // 遍历所有邻接点
    ArcNode* p = G.vertices[v].firstarc; 
    while (p) 
    {
        // 如果邻接点未访问，递归访问
        if (!visited[p->adjvex]) 
            DFS(G, p->adjvex);

        p = p->nextarc;
    }

    // 所有邻接点处理完后，将该顶点加入拓扑序列
    topo[topoIndex--] = v;   
}

// 拓扑排序
bool TopologicalSort(ALGraph G)
{
    // 初始化拓扑排序的索引
    topoIndex = G.vexnum - 1;   

    // 初始化所有顶点未访问
    for (int i = 0; i < G.vexnum; i++)
    {
        visited[i] = false;     
    }

    for (int i = 0; i < G.vexnum; i++) 
    {
        // 如果顶点未访问，进行DFS
        if (!visited[i]) 
            DFS(G, i);
    }

    //// 输出拓扑排序结果
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
