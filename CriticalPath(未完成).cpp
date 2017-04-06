#include <iostream>
#define MAXSIZE 100
using namespace std;

typedef struct ArcNode
{
    int adjvertex;
    int weight;
    int
    struct ArcNode* nextArc;
}ANode;
typedef struct VertexNode
{
    int indegree;
    ANode* firstArc;
}VNode;
typedef struct AOE
{
    VNode vertex[MAXSIZE];
    int vn, en;
}Graph
void createAOE(Graph &G)
{
    int start,end,weight;
    ANode* p = NULL;

    cout << "请输入顶点数：";
    cin >> G.vn;
    cout << "请输入边数："；
    cin >> G.en;

    for(int i=1; i<=G.vn;i++)
    {
        G.vertex[i].indegree = 0;
        G.vertex[i].firstArc = NULL;
    }

    cout << "请输入始点，终点和权值:";
    for(int i=1; i<=G.en; i++)
    {
        cin >> start >> end >>　weight;
`       p = new ANode;
        p->adjVertex = end;
        p->nextArc = G.vertex[start].firstArc;
        G.vertex[start].firstArc = p;
        p->weight = weight; //多了权值
    }
}

int main()
{
    Graph G;
    return 0;
}
