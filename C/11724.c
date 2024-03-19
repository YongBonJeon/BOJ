#include <stdio.h>

#define MAX 1001

int M,N;
int map[MAX][MAX];
int visited[MAX];

int allvisit(){
    for(int i = 1 ; i <= M ; i++){
        if(visited[i] == 0){
            return i;
        }
    }
    return -1;
}

void dfs(int v){
    visited[v] = 1;
    //printf("%d ",v);

    for(int i = 1 ; i<= M ; i++){
        if(map[v][i] == 1 && visited[i] == 0){
            dfs(i);
        }
    }
}

int main(){

    scanf("%d %d",&M, &N);
    for(int i = 0 ; i < N ; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        map[a][b] = 1;
        map[b][a] = 1;
    }

    int i,j;
    for(i = 0 ; i < M ; i++){
        if((j = allvisit()) > 0){
            dfs(j);
        }
        else{
            break;
        }
    }
    printf("%d\n",i);
}