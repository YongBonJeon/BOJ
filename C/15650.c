#include <stdio.h>
int n, m;
int visited[9]={0,};
int arr[9]={0,};
void dfs(int depth, int cur){
    if(depth == m){
        for(int i = 0 ; i < m ; i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return ;
    }
    for(int i = 1 ; i <= n ; i++){
        if(visited[i] == 0 && i > cur){
            arr[depth] = i;
            visited[i] = 1;
            dfs(depth+1, i);
            visited[i] = 0;
        }
    }
    return ;
}

int main(){

    scanf("%d %d",&n, &m);

    dfs(0,0);
}