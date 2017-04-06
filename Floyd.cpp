#include <iostream>
#define MAXSIZE 100
using namespace std;

typedef struct{
    int vn;
    int en;
    int vertex[MAXSIZE];
    int edge[MAXSIZE][MAXSIZE];
}Graph;
void createGraph(Graph &g){
    cout << "请输入顶点数:";
    cin >> g.vn;
    cout << "请输入边数:";
    cin >> g.en;

    for(int i=0; i<g.vn; i++){
        for(int j=0; j<g.vn; j++){
            g.edge[i][j] = 0;
        }
    }

    cout << "请输入顶点值:";
    for(int i=0; i<g.vn; i++){
        cin >> g.vertex[i];
    }

    int v1, v2, dis;
    cout << "请输入边（用两顶点表示,注意方向）和长度:" << endl;
    for(int i=0; i<g.en; i++){
        cin >> v1 >> v2 >> dis;
        g.edge[v1][v2] = dis;
    }
}
void Floyd(Graph &g){
    int origin, dest;
    cout << "请输入起点和终点:";
    cin >> origin >> dest;

    for(int k=0; k<g.vn; k++){
        for(int i=origin; i<g.vn; i++){
            for(int j=dest; j<g.vn; j++){
                if(g.edge[i][])
            }
        }
    }
}
int main(){
    Graph g;
    createGraph(g);

    return 0;
}
