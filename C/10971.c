#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICE 10
#define TRUE 1
#define FALSE 0

int n;
int ans=INT_MAX;
int startV;
int weight_map[MAX_VERTICE][MAX_VERTICE];
int visited[MAX_VERTICE];

void modified_dfs(int v, int depth, int sum){
    //printf("depth sum %d %d %d \n",depth, sum, v);

    if(depth == n-1 && weight_map[v][startV]){
        //printf("%d %d\n",ans, sum + weight_map[v][startV]);
        if (ans > sum + weight_map[v][startV]){
            ans = sum + weight_map[v][startV];
        }
        return ;
    }

    for(int i = 0 ; i < n; i++){
        if(weight_map[v][i] > 0 && visited[i] == 0){
            visited[i] = 1;
            sum += weight_map[v][i];
            modified_dfs(i, depth + 1, sum);
            visited[i] = 0;
            sum -= weight_map[v][i];
        }
    }
    
}

void reset(){
    for(int i = 0 ; i < n ; i++){
        visited[i] = 0;
    }
}

int main(){  

    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf(" %d",&weight_map[i][j]);
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        startV = i;
        reset();
        visited[i] = 1;
        modified_dfs(i,0,0);
        reset();
    }
    printf("%d\n",ans);


}