#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//图的存储结构
#define MaxInt 32767	//表示极大值（相当于∞）
#define MVNum 100	//定义最大顶点数为100
typedef char VerTexType ;	//顶点 数据类型为char
typedef int ArcTypen,OtherInfo;	//边 的权值类型为int


//邻接矩阵
//存储表示
typedef struct AMGraph
{
	VerTexType vexs[MVNum];		//定义结点（存储顶点）
	ArcTypen arcs[MVNum][MVNum];	//定义边（邻接矩阵）
	int vexnmu, arcnum;		//用于记录当前顶点，边的数量
}AMGraph;



//邻接表
//顶点的存储表示
typedef struct VexNode
{
	VerTexType data;	//存储顶点信息
	struct ArcNode* firstarc;	//指向A的所有出度 的第一条边

}VexNode,AdjList[MVNum];		//VexNode表示顶点，用AdjList表示整个邻接表,表中最多有MVNum个VexNode
//边的存储表示
typedef struct ArcNode
{
	int adjvex;		//指向这条边指向的顶点（A->B，A->C,则存储B的下标）
	struct ArcNode* nextarc;	//指向下一个边（A->B,A->C,则指向AC之间的边）
	OtherInfo info;		//存储边的信息，如权值（A->B之间边的权值等边自身的信息）
}ArcNode;
//邻接表表示
typedef struct ALGraph
{
	AdjList vertices;
	int vexnum, arcnum;		//图中目前的顶点、边的个数
}ALGraph;

int main()
{
	return 0;
}

//邻接表转化为邻接矩阵
//for (int i = 0; i < vexsum; i++)
//{
//	ArcNode* p = AdjList[i].firstArc;
//	while (p)
//	{
//		Graph.arcs[i][p->adjvex] = p->info;
//		p = p->nextarc;
//	}
//}


//输出出度比入度大的结点k和返回k的数量
int printVertices(AMGraph G)
{
	int num = 0;
	for (int row = 0; row < G.vexnmu; row++)
	{
		int out = 0, in = 0;
		for (int col = 0; col < G.vexnmu; col++)
		{
			if (G.arcs[row][col] != 0 || G.arcs[row][col] != MaxInt)		//求row行和
				out++;
			if (G.arcs[col][row] != 0 || G.arcs[col][row] != MaxInt)		//求row列和
				in++;
		}
		if (out > in)	//行和大于列和，满足条件
		{
			printf("%c", G.vexs[row]);	//输出并计数加一
			num++;
		}
			
	}
	return num;
}


//有向图中是否有顶点vi到vj的路径
bool visited[MVNum];
bool isRoad(ALGraph G, int i, int j)
{
	visited[i] = true;	// 标记顶点i已经访问
	ArcNode* p = G.vertices[i].firstarc;	// 获取顶点i的第一条边

	while(p)	// 遍历顶点i的所有邻接点
	{
		if (p->adjvex == j)	//i的第一个邻接点就是j
			return true;
		else if (visited[p->adjvex] == false)	//i的第一个邻接点不是j，且未被访问过
			return isRoad(G, p->adjvex, j);	 // 递归检查从该邻接点到j是否有路径
		p = p->nextarc;	// 检查下一个邻接点
	}
	return false;
}

//四种存储结构
// 
// 有向图无向图——邻接矩阵、邻接表
// 十字链表（有向图），邻接多重表（无向图）

//图的两种遍历方法：广度优先遍历BFS和深度优先遍历DFS(均为阵:O(n^2)和表:O(n+e))

//图的应用
// 
//最小生成树：Prime算法、Kruskal算法（表:O(e log e)）
// 
//最短路径：	BFS（权值为1）	Dijkstra（无负权值）	Floyd（无带负权值的环）
//时间复杂度		O(n^2)			O(n^2)				O(n^3)
// 
//拓扑排序——有向无环图，关键路径(均为阵:O(n^2)和表:O(n+e))