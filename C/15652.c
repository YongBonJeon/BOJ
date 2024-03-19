#include <stdio.h>

int N, M;
int visited[9] = {0,};

void dfs(int temp[], int depth, int lower){
    if(depth == M){
        for(int i = 0 ; i < depth ; i++){
            printf("%d ",temp[i]);
        }
        printf("\n");
        return ;
    }
    for(int i = 1 ; i <= N ; i++){
        if(i >= lower){
            temp[depth] = i;
            dfs(temp, depth+1, i);
        }
    }
}

int main(){
    scanf("%d %d",&N, &M);

    int temp[9];

    dfs(temp, 0, 0);
}