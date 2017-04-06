#include <iostream>
#define MAXSIZE 100
using namespace std;


/*
    AOV网，应用于当某个活动的发生必须要在别的活动之后时
    例如，课程之间的优先关系，工程的施工。
    AOV网保证了一系列事情的先后逻辑。
*/
typedef struct ArcNode
{
    int adjVertex;
    struct ArcNode* nextArc;
}ANode;

typedef struct VertexNode
{
    int indegree;
    ANode* firstArc;
}VNode;

typedef struct AdjGraph
{
    VNode vertex[MAXSIZE];
    int vn, en;
}Graph;

bool visited[MAXSIZE];

void createAOV(Graph& G);
void DFS(Graph& G);
void DFSTraverse(Graph& G,int start);
void topoSort(Graph& G);
int main()
{
    Graph G;
    createAOV(G);
    topoSort(G);
    return 0;
}

//void topoSort(Graph& G)
//{
//    int Stack[G.vn+1];
//    int top = 0, cnt = 0;
//    int i;
//
//    for(i=1; i<=G.vn; i++)
//    {
//        if(G.vertex[i].indegree == 0)
//        {
//            Stack[++top] = i;
//            break;
//        }
//    }
//
//    while(top!=0)
//    {
//        i = Stack[top--];
//        cout << i << " ";
//        cnt++;
//        ANode* p = G.vertex[i].firstArc;
//        while(p)
//        {
//            if((--G.vertex[p->adjVertex].indegree)==0)
//            {
//                Stack[++top] = p->adjVertex;
//            }
//            p = p->nextArc;
//        }
//    }
//    if(cnt<G.vn)
//        cout << endl << "有回路" << endl;
//}

void createAOV(Graph& G)
{
    int v1, v2;
    ANode* p = NULL;
    cout << "请输入点数：";
    cin >> G.vn;
    cout << "请输入边数：";
    cin >> G.en;

    for(int i=1; i<=G.vn; i++)
    {
        G.vertex[i].firstArc = NULL;
        G.vertex[i].indegree = 0;
    }

    cout << "请输入有向边（用两点表示,v1 v2表示v1->v2）：" << endl;
    for(int i=1; i<=G.en; i++)
    {
        cin >> v1 >> v2;
        p = new ANode;
        p->adjVertex = v2;
        p->nextArc = G.vertex[v1].firstArc;
        G.vertex[v1].firstArc = p;
        G.vertex[v2].indegree++;
    }
}
void DFS(Graph& G)
{
    for(int i=1; i<=G.vn; i++)
    {
        visited[i] = false;
    }
    for(int i=1; i<=G.vn; i++)
    {
        if(visited[i]==false)
        DFSTraverse(G,i);
    }
}
void DFSTraverse(Graph &G,int start)
{
    cout << start << "号的入度为:" << G.vertex[start].indegree << endl;
    visited[start] = true;
    ANode* p = G.vertex[start].firstArc;

    while(p)
    {
        if(visited[p->adjVertex]==false)
        {
            DFSTraverse(G,p->adjVertex);
        }
        p = p->nextArc;
    }
}
void topoSort(Graph &G)
{
    int Stack[G.vn+1];
    int top = 0, i,cnt = 0;

    //首先找到一个入度为0的顶点
    for(i=1; i<=G.vn; i++)
    {
        if(G.vertex[i].indegree == 0)
        {
            Stack[++top] = i;
            cnt++;
        }
    }

    while(top!=0)
    {
        //出栈输出，然后将其邻点的入度全部减一

        i = Stack[top--];
        cout << i<< " ";
        ANode* p = G.vertex[i].firstArc;

        while(p)
        {
            //如果减一之后入度为0了，入栈
            if((--G.vertex[p->adjVertex].indegree)==0)
            {
                Stack[++top] = p->adjVertex;
                cnt++;
            }
            p = p->nextArc;
        }
    }
    if(cnt < G.vn)
        cout << "有回路" << endl;

}
