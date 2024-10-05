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


