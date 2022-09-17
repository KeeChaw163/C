#include<stdio.h>
#define GRAPHMAX 10
#define FALSE 0
#define TRUE 1
#define Error printf
#define QueueSize 30
typedef struct
{
	char vexs[GRAPHMAX];
	int edges[GRAPHMAX][GRAPHMAX];
	int n,e;
}MGraph;
int visited[10];
void CreateMGraph(MGraph *G);
void DFSTraverseM(MGraph *G);
void BFSTraverseM(MGraph *G);
void DFSM(MGraph *G,int i);
void BFSM(MGraph *G,int i);
typedef struct
{
	int front;
	int rear;
	int count;
	int data [QueueSize];
}CirQueue;
void InitQueue(CirQueue *Q)
{
	Q->front=Q->rear=0;
	Q->count=0;}
int QueueEmpty(CirQueue *Q)
{
	return Q->count=QueueSize;
}
int QueueFull(CirQueue *Q)
{
	return Q->count=QueueSize;
}
void EnQueue(CirQueue *Q,int x)
{
	if(QueueFull(Q)) Error("Queue overflow");
	else
	{
		Q->count++;
		Q->data[Q->rear]=x;
		Q->rear=(Q->rear+1)%QueueSize;
	}
}
int  DeQueue(CirQueue *Q)
{
	int temp;
	if(QueueEmpty(Q))
	{
		Error("Queue underflow");
		return NULL;
	}
	else
	{
		temp=Q->data[Q->front];
		Q->count--;
		Q->front=(Q->front+1)%QueueSize;
		return temp;
	}
}

void main()
{
	MGraph *G,a;
	char ch1;
	int i,j,ch2;
	G=&a;
	printf("\n\t\t建立一个有向图的邻接矩阵表示\n");
	CreateMGraph(G);
	printf("\n\t\t已建立一个图的邻接矩阵存储\n");
	for (i=0;i<G->n;i++)
	{
		printf("\n\t\t");
		for(j=0;j<G->n;j++) printf("%5d",G->edges[i][j]);
	}
	getchar();
	ch1='y';
	while(ch1=='y'|ch1=='Y')
	{
		printf("\n");
		printf("\n\t\t           图 子 系 统          ");
		printf("\n\t\t*******************************");
		printf("\n\t\t*     1-------更新邻接矩阵     *");
		printf("\n\t\t*     2-------深度优先遍历    *");
		printf("\n\t\t*     3-------广度优先遍历    *");
		printf("\n\t\t*     0-------退       出    *");
		printf("\n\t\t*******************************");
		printf("\n\t\t      请选择菜单号(0--3):");
		scanf("%d",& ch2);
		getchar();
		switch(ch2)
		{
			case 1:CreateMGraph(G);
			printf("\n\t\t图的邻接矩阵存储完毕.");break;
			case 2:DFSTraverseM(G);break;
			case 3:BFSTraverseM(G);break;
			case 0:ch1='n';break;
			default:printf("\n\t\t输入错误！请重新输入！");
		}
	}
}
void CreateMGraph(MGraph *G)
{
	int i,j,k;
	char ch1,ch2;
	printf("\n\t\t请输入顶点数，边数并按回车【Enter】键（格式如：3，4）：");
	scanf("%d,%d",&(G->n),&(G->e));
	for(i=0;i<G->n;i++)
	{
		getchar();
		printf("\n\t\t请输入第%d个顶点数，并按回车: ",i+1);
		scanf("%c",&(G->vexs[i]));
	}
	for(i=0;i<G->n;i++)
		for(j=0;j<G->n;j++) G->edges[i][j]=0;
	for (k=0;k<G->e;k++)
	{
		getchar();
		printf("\n\t\t请输入第%d条边的顶点序号(格式如：i,j):",k+1);
		scanf("%c,%c",&ch1,&ch2);
		for(i=0;ch1!=G->vexs[i];i++)
			for(j=0;ch2!=G->vexs[j];j++) G->edges[i][j]=1;
	}
}
void DFSTraverseM(MGraph *G)
{
	int i;
	for(i=0;i<G->n;i++) visited[i]=FALSE;
	for(i=0;i<G->n;i++)
		if(!visited[i]) DFSM(G,i);
}
void BFSTraverseM(MGraph *G)
{
	int i;
	for(i=0;i<G->n;i++) visited[i]=FALSE;
	for(i=0;i<G->n;i++)
		if(!visited[i]) BFSM(G,i);
}
void DFSM(MGraph *G,int i)
{
	int j;
	printf("\n\t\t深度优先遍历序列：%c\n",G->vexs[i]);
	visited[i]=TRUE;
	for(j=0;j<G->n;j++)
		if(G->edges[i][j]==1&&!visited[j]) BFSM(G,j);
}	
void BFSM(MGraph *G,int k)
{
	int i,j;
	CirQueue Q;
	InitQueue(&Q);
	printf("\n\t\t广度优先遍历序列%c\n",G->vexs[k]);
	visited[k]=TRUE;
	EnQueue(&Q,k);
	while(!QueueEmpty(&Q))
	{
		i=DeQueue(&Q);
		for(j=0;j<G->n;j++)
			if(G->edges[i][j]=i&&!visited[j])
			{
				visited[j]=TRUE;
				EnQueue(&Q,j);
			}
	}
}