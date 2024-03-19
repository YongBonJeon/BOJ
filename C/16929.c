#include <stdio.h>

#define MAX 50

int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int n,m;
int startAt[2];
char map[MAX][MAX];
int visited[MAX][MAX] = {0,};
int flag = 0;

void dfs(int depth, int y, int x){
    int cur_col = y;
    int cur_row = x;
    char cur_item = map[y][x];

    visited[cur_col][cur_row] = 1;

    for(int i = 0 ; i < 4 ; i++){

        int next_col = cur_col + dir[i][0];
        int next_row = cur_row + dir[i][1];

        if(next_col >= 0 && next_row >= 0 && next_col < n && next_row < m){
            char next_item = map[next_col][next_row];

            /* 미방문이면 간다 */
            if(visited[next_col][next_row] == 0 && next_item == cur_item ){
                dfs(depth+1, next_col, next_row);
                if(flag){
                    return ;
                }
            }
            else if(visited[next_col][next_row] == 1 && next_item == cur_item){
                /* 방문인데 목적지(시작점)인가? */
                if(next_col == startAt[0] && next_row == startAt[1] && depth >= 3){
                    flag++;
                    printf("Yes\n");
                    return ;
                }
            }
        }
    }
    //printf("\n");
}

void reset(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            visited[i][j] = 0;
        }
    }
}

int main(){
    scanf("%d %d",&n, &m);

    for(int i = 0 ; i < n ; i++){
        scanf("%s",map[i]);
    }

    for(int i = 0 ; i < n ; i++){
        if(flag){break;}
        for(int j = 0 ; j < m ; j++){
            if(flag){break;}
            reset();
            startAt[0] = i;
            startAt[1] = j;
            dfs(0,i,j);
        }
    }
    if(!flag){
        printf("No\n");
    }
    


}