#include <stdio.h>
#include <stdlib.h>

typedef struct TUJZ
{
	char vexs[20];			//顶点表
	int arc[20][20] = {-1}; //邻接矩阵
	int numV, numE;			//当前顶点数和边数
} * TTUJZ;

typedef struct EdgeNext
{				//顶点之后边
	int vex;	//存储该顶点下标
	int weight; //边权值
	struct EdgeNext *next;
};

typedef struct VexD
{ //顶点
	char data;
	EdgeNext *firstedge; //顶点下一个
} VexList[20];

typedef struct TUB
{
	VexList vexList;
	int numV, numE; //图中当前顶点数和边数
} * TTUB;

TTUJZ CreateTUJZ()
{ //创建无向图
	TTUJZ G = (TTUJZ)malloc(sizeof(TUJZ));
	int i, j, k, w;
	printf("输入顶点数和边数(空格隔开)：\n");
	scanf("%d %d", &G->numV, &G->numE);
	getchar();
	printf("输入顶点:\n");
	for (i = 0; i < G->numV; i++)
	{
		scanf("%c", &G->vexs[i]);
		getchar();
	}
	//先把用到的地方归零
	for (i = 0; i < G->numV; i++)
	{
		for (j = 0; j < G->numV; j++)
		{
			G->arc[i][j] = 0;
		}
	}
	for (k = 0; k < G->numE; k++)
	{
		printf("输入边（vi，vj）上的下标i，下标j和权w（空格隔开）：\n");
		scanf("%d %d %d", &i, &j, &w);
		G->arc[i - 1][j - 1] = w;
		G->arc[j - 1][i - 1] = G->arc[i - 1][j - 1]; //无向图，矩阵对称
	}
	return G;
}

TTUB CreateTUB()
{ //无向图的创建
	TTUB G = (TTUB)malloc(sizeof(TUB));
	int i, j, w, k;
	EdgeNext *e;
	printf("输入顶点数和边数(空格隔开):\n");
	scanf("%d %d", &G->numV, &G->numE);
	getchar();
	printf("输入顶点:\n");
	for (i = 0; i < G->numV; i++)
	{
		scanf("%c", &G->vexList[i].data);
		getchar();
		G->vexList[i].firstedge = NULL;
	}

	for (k = 0; k < G->numE; k++)
	{
		printf("输入边（vi，vj）上的下标i，下标以及权重W(空格隔开):\n");
		scanf("%d %d %d", &i, &j, &w);
		e = (EdgeNext *)malloc(sizeof(EdgeNext));
		e->vex = j;
		e->weight = w;
		e->next = G->vexList[i - 1].firstedge; //头插入
		G->vexList[i - 1].firstedge = e;
		e = (EdgeNext *)malloc(sizeof(EdgeNext));
		e->vex = i;
		e->weight = w;
		e->next = G->vexList[j - 1].firstedge;
		G->vexList[j - 1].firstedge = e;
	}
	return G;
}
void prtTUJZ(TUJZ G)
{
	printf("一共%d个节点，%d条边\n", G.numV, G.numE);
	for (int i = 0; i < G.numV; i++)
	{
		printf("%c ", G.vexs[i]);
	}
	printf("\n");
	for (int i = 0; i < G.numV; i++)
	{
		for (int x = 0; x < G.numV; x++)
		{
			printf("%d ", G.arc[i][x]);
		}
		printf("\n");
	}
}
void prtTUB(TUB G)
{
	for (int i = 0; i < G.numV; i++)
	{
		printf("%c", G.vexList[i].data);
		EdgeNext *e = (EdgeNext *)malloc(sizeof(EdgeNext));
		e = G.vexList[i].firstedge;
		while (e)
		{
			printf("-->%d(%d)", e->vex, e->weight);
			e = e->next;
		}
		printf("\n");
	}
}