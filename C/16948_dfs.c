#include <stdio.h>
#include <unistd.h>

#define MAX 200

int N;
int start[2];
int end[2];
int dir[6][2] = {{-1, -2}, {1,-2}, {-2,0}, {2,0}, {-1,2}, {1,2}};
int map[MAX][MAX];
int visited[MAX][MAX] = {0,};
int flag=10000;

void dfs(int y, int x, int depth){
    int cur_col = y;
    int cur_row = x;
    //sleep(1);
    visited[cur_col][cur_row]++;
    for(int i = 0 ; i < 6 ; i++){
        int next_col = cur_col + dir[i][0];
        int next_row = cur_row + dir[i][1];

        if(next_col < 0 || next_row < 0 || next_col > N-1 || next_row > N-1){
            continue;
        }
        if(next_col == end[1] && next_row == end[0]){
            if(flag > depth+1)
                flag = depth+1;
            printf("flag %d\n",flag);
            return ;
        }
        if(visited[next_col][next_row] == 0){
            printf("%d %d\n",next_col,next_row);
            dfs(next_col, next_row, depth+1);
            visited[next_col][next_row]--; 
        }
        if(depth+1 >= flag){return ;}
    }
}

int main(){
    scanf("%d", &N);

    scanf("%d %d %d %d",&start[0], &start[1], &end[0], &end[1]);

    dfs(start[1], start[0], 0);

    if(flag != 10000){
        printf("%d\n",flag);
    }
    else{
        printf("-1\n");
    }
}