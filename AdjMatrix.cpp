#include <iostream>
#define MaxVertexNum 100
using namespace std;

typedef struct
{
    int vn;
    int en;
    char vertex[MaxVertexNum];
    int edge[MaxVertexNum][MaxVertexNum];
}MGraph;
bool visited[MaxVertexNum];

void createGraph(MGraph &G);
void DFS(MGraph &G, int start);
void DFSTraverse(MGraph &G);
void BFS(MGraph &G, int start);
void BFSTraverse(MGraph &G);

int main()
{
    MGraph G;
    createGraph(G);
    BFSTraverse(G);
    return 0;
}
void createGraph(MGraph &G)
{
    int v1, v2;

    cout << "请输入点数:";
    cin >> G.vn;
    cout << "请输入边数:";
    cin >> G.en;

    cout << "请输入每个点的内容:";
    for(int i=0; i<G.vn; i++)
    {
        cin >>  G.vertex[i];
    }

    for(int i=0; i<G.en; i++)0
        for(int j=0; j<G.en; j++)
            G.edge[i][j] = 0;

    cout << "请分别输入每一条边(用两点表示):" << endl;
    for(int i=0; i<G.en; i++)
    {
        cin >> v1 >> v2;
        G.edge[v1][v2] = 1;
        G.edge[v2][v1] = 1;
    }
}

void DFSTraverse(MGraph &G)
{
    for(int i=0; i<G.vn; i++)
    {
        visited[i] = false;
    }

    for(int i=0; i<G.vn; i++)
    {
        if(visited[i]==false)
        {
            DFS(G,i);
        }
    }
}

void DFS(MGraph &G, int start)
{
    cout << G.vertex[start];
    visited[start] = true;

    for(int i=0; i<G.vn; i++)
    {
        if(visited[i]==false && G.edge[i][start]==1)
        {
            DFS(G,i);
        }
    }
}

void BFS(MGraph &G, int start)
{
    int j;
    int queue[G.vn+1];
    int front,rear;
    front = rear = 0;

    cout << G.vertex[start];
    visited[start] = true;
    queue[++rear] = start;

    while(front != rear)
    {
        j = queue[++front];
        for(int i=0; i<G.vn; i++)
        {
            if(visited[i]==false && G.edge[i][j]==1)
            {
                cout << G.vertex[i];
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}
void BFSTraverse(MGraph &G)
{
    for(int i=0; i<G.vn; i++)
    {
        visited[i] = false;
    }

    for(int i=0; i<G.vn; i++)
    {
        if(visited[i]==false)
        {
            BFS(G,i);
        }
    }
}












//
//typedef struct
//{
//    char vertex[MaxVertexNum];
//    int edge[MaxVertexNum][MaxVertexNum];
//    int vn;//顶点数
//    int en;//边数
//}MGraph;
//
///*创建无向图的邻接矩阵*/
//void createGraph(MGraph &G)
//{
//    cout << "请输入点数:";
//    cin >> G.vn;
//    cout << "请输入边数:";
//    cin >> G.en;
//
//    cout << "请输入点的信息:";
//    for(int i=0; i<G.vn; i++)
//    {
//        cin >> G.vertex[i];
//    }
//
//    //初始化邻接矩阵
//    for(int i=0; i<G.vn; i++)
//    {
//        for(int j=0; j<G.vn; j++)
//        {
//            G.edge[i][j] = 0;
//        }
//    }
//
//    cout << "请输入每两个点的连接关系:";
//    int v1,v2;
//    for(int i=0; i<G.en; i++)
//    {
//        cin >> v1 >> v2;
//        G.edge[v1][v2] = 1;
//        G.edge[v2][v1] = 1;//此为无向图
//    }
//}
///*DFS遍历图的邻接矩阵，以start为遍历起点*/
//bool visited[MaxVertexNum] = {false};
//void DFS(MGraph &G,int start)
//{
//    cout << G.vertex[start];
//    visited[start] = true;
//
//    for(int i=0; i<G.vn; i++)
//    {
//        if(visited[i]==false && G.edge[start][i]==1)
//        {
//            DFS(G,i);
//        }
//    }
//}
//void DFT(MGraph &G)
//{
//    for(int i=0; i<G.vn; i++)
//    {
//        visited[i] = false;
//    }
//    for(int i=0; i<G.vn; i++)//图分连通与不连通，所以这里要一个循环扫描所有的点
//    {
//        if(visited[i]==false)
//        {
//            DFS(G,i);
//        }
//    }
//}
///*BFS遍历图的邻接矩阵，从start开始*/
//void BFS(MGraph &G,int start)
//{
//    int queue[G.vn+1];//定义普通队列
//    int front, rear;
//    front = rear = 0;
//
//    queue[++rear] = start;
//    cout << G.vertex[start];
//    visited[start] = true;
//    while(front != rear)
//    {
//        int j = queue[++front];
//
//        for(int i=0; i<G.vn; i++)
//        {
//            if(visited[i]==false && G.edge[i][j]==1)
//            {
//                queue[++rear] = i;
//                cout << G.vertex[i];
//                visited[i] = true;
//            }
//        }
//    }
//
//}
//void BFT(MGraph &G)
//{
//    for(int i=0; i<G.vn; i++)
//    {
//        visited[i] = false;
//    }
//    for(int i=0; i<G.vn; i++)
//    {
//        if(visited[i]==false)
//            BFS(G,i);
//    }
//}
//
//int main()
//{
//    MGraph G;
//    createGraph(G);
//    BFS(G,0);
//    return 0;
//}
