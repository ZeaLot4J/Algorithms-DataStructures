#include <iostream>
#define MAXSIZE 50
using namespace std;

/*存放边*/
typedef struct ArcNode
{
    int adjVertex;//
    struct ArcNode* nextArc;
} ANode;
/*存放点*/
typedef struct VertexNode
{
    char data;
    struct ArcNode* firstArc;
} VNode;
/*邻接表*/
typedef struct Graph
{
    VNode vertex[MAXSIZE];
    int vn, en;
} Graph;

bool visited[MAXSIZE];
void createGraph(Graph &G);
void DFSTraverse(Graph &G);
void DFS(Graph &G, int start);
void BFSTraverse(Graph &G);
void BFS(Graph &G, int start);

int main()
{
    Graph G;
    createGraph(G);
    BFSTraverse(G);
    return 0;
}
void createGraph(Graph &G)
{
    int v1, v2;
    ANode* p = NULL;

    cout << "请输入点数:";
    cin >> G.vn;
    cout << "请输入边数:";
    cin >> G.en;

    /*初始化所有顶点*/
    cout << "请依次输入顶点的数据:";
    for (int i = 0; i < G.vn; i++)
    {
        cin >> G.vertex[i].data;
        G.vertex[i].firstArc = NULL;
    }

    /*构造边的关系*/
    for (int i = 0; i < G.en; i++)
    {
        cout << "请输入边(用两点表示):";
        cin >> v1 >> v2;//0 1
        p = new ANode;
        p->adjVertex = v2;
        p->nextArc = G.vertex[v1].firstArc;
        G.vertex[v1].firstArc = p;

        p = new ANode;
        p->adjVertex = v1;
        p->nextArc = G.vertex[v2].firstArc;
        G.vertex[v2].firstArc = p;
    }
    cout << endl;

    //    for(int i=0; i<G.vn; i++)
    //    {
    //        cout << "vertex" << i << "的边是:";
    //        p = G.vertex[i].firstArc;
    //        while(p)
    //        {
    //            cout << p->adjVertex << " ";
    //            p = p->nextArc;
    //        }
    //        cout << endl;
    //    }
}
void DFSTraverse(Graph &G)
{
    for (int i = 0; i < G.vn; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < G.vn; i++)
    {
        if (visited[i] == false)
        {
            DFS(G, i);
        }
    }
}

void DFS(Graph &G, int start)
{
    cout << G.vertex[start].data << " ";
    visited[start] = true;

    ANode* p = G.vertex[start].firstArc;
    while (p)
    {
        if (visited[p->adjVertex] == false)
        {
            DFS(G, p->adjVertex);
        }
        p = p->nextArc;
    }
}

void BFSTraverse(Graph &G)
{
    for (int i = 0; i < G.vn; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < G.vn; i++)
    {
        if (visited[i] == false)
        {
            BFS(G, i);
        }
    }
}
void BFS(Graph &G, int start)
{
    ANode* p = NULL;
    int  queue[G.vn + 1];
    int front, rear, i, j;
    front = rear = 0;

    queue[++rear] = start;
    cout << G.vertex[start].data << " ";
    visited[start] = true;

    while (rear != front)
    {
        i = queue[++front];
        p = G.vertex[i].firstArc;
        //入队
        while(p)
        {
            i = p->adjVertex;
            if (visited[i] == false)
            {
                cout << G.vertex[i].data << " ";
                queue[++rear] = i;
                visited[i] = true;
            }
            p = p->nextArc;
        }
    }
}
