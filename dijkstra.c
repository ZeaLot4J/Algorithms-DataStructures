#include <stdio.h>
#include <stdlib.h>
#define MAX_INT 999999

/* 贪心 dijkstra最短路径 */

void dijkstra(int map[][6], int n){
    int path[100];
    int flag[100] = {0};
    int i,j;
    int minIndex;
    for(i=0; i<n; i++)
        path[i] = map[0][i];        //0号点的所有最短路径

    for(i=1; i<n; i++){
            //先找离0号点最近的点，此处可以用堆来完成，logn
        int min = MAX_INT;
        for(j=1; j<n; j++){
            if(flag[j]==0 && path[j]<min){
                min = path[j];
                minIndex = j;
            }
        }
        flag[minIndex] = 1;

        for(j=1; j<n; j++)
            if(map[minIndex][j] + path[minIndex] < path[j])
                path[j] = map[minIndex][j] + path[minIndex];
    }
    for(i=0; i<n; i++)
        printf("%d ", path[i]);
}

int main(){
    int map[6][6] = {0, 1, 12, MAX_INT, MAX_INT, MAX_INT,
                     MAX_INT, 0, 9, 3, MAX_INT, MAX_INT,
                     MAX_INT, MAX_INT, 0, MAX_INT, 5, MAX_INT,
                     MAX_INT, MAX_INT, 4, 0, 13, 15,
                     MAX_INT, MAX_INT, MAX_INT, MAX_INT, 0, 4,
                     MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 0};
    dijkstra(map, 6);
    return 0;
}
