/* 다익스트라 알고리즘 */
#include <stdio.h>

#define MAX 1001
#define INF 1000000
#define TRUE 1
#define FALSE 0

int num_vertex, num_edges, target;
int map[MAX][MAX] = {0,};
int v[MAX];
int d[MAX];

int getSmallIndex(){
    int min = INF;
    int idx = 0;

    for(int i = 1 ; i <= num_vertex ; i++){
        if(d[i] < min && !v[i]){
            min = d[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int start){
    for(int i = 1 ; i <= num_vertex ; i++){
        d[i] = map[start][i];
    }
    v[start] = TRUE;

    for(int i = 1 ; i <= num_vertex - 2 ; i++){
        int cur = getSmallIndex();
        v[cur] = TRUE;
        for(int j = 1 ; j <= num_vertex ; j++){
            if(!v[j]){
                if(d[cur] + map[cur][j] < d[j]){
                    d[j] = d[cur] + map[cur][j];
                }
            }
        }
    }
}

void reset(){
    for(int i = 0 ; i <= num_vertex ; i++){
        d[i] = 0;
        v[i] = 0;
    }
}

int main(){

    scanf("%d %d %d",&num_vertex, &num_edges, &target);

    for(int i = 0 ; i <= num_vertex ; i++){
        for(int j = 0 ; j <= num_vertex ; j++){
            map[i][j] = INF;
            if(i == j ){
                map[i][j] = 0;
            }
        }
    }

    for(int i = 0 ; i < num_edges ; i++){
        int start, end, weight;
        scanf("%d %d %d",&start, &end, &weight);

        map[start][end] = weight;
    }
    /*for(int i = 1 ; i <= num_vertex ; i++){
        for(int j = 1 ; j <= num_vertex ; j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }*/

    int max = 0;

    for(int i = 1 ; i <= num_vertex ; i++){
        reset();
        dijkstra(i);
        int temp1 = d[target];
        /*for(int i = 1 ; i <= num_vertex ; i++){
            printf("%d ",d[i]);
        }
        printf("\n");*/

        reset();
        dijkstra(target);
       /* for(int i = 1 ; i <= num_vertex ; i++){
            printf("%d ",d[i]);
        }
        printf("\n");*/
        int temp2 = temp1 + d[i];

        if(temp2 > max){
            max = temp2;
            //printf("idx %d\n",i);
        }
    }
    printf("%d\n",max);
}
