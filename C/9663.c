#include <stdio.h>
#include <unistd.h>

/* 각 줄에 퀸 하나씩은 무조건 */
/* y번째 행에 x번째 칸에 논다. */
/* y는 퀸을 놓는 횟수 */
int N;
int sum = 0;

void dfs(int chess[15][15],int y){
        

    if(y+1 == N){
        for(int i = 0 ; i < N ; i++){
          
            if(chess[y][i] == 0){
                sum++;
            }
        }
        return ;
    }
    
    for(int i = 0 ; i < N ; i++){
        /* 퀸을 놓을 수 없다면 오른쪽 칸으로 */
        if(chess[y][i] > 0){continue;}

        /* 퀸을 놓는 행위 */
        chess[y][i]++;
        for(int j = 0 ; j < N ; j++){
            if(j != i){
                chess[y][j]++; /* 가로 색칠 */
            }
            if(y != j){
                chess[j][i]++; /* 세로 색칠 */
            }
        }
        for(int j = 1 ; j < N ; j++){
            if(y+j < N && i+j < N){
                chess[y+j][i+j]++; /* 우하 대각 색칠 */
            }
            if(y+j < N && i-j >= 0){
                chess[y+j][i-j]++; /* 좌하 대각 색칠 */
            }
            if(y-j >= 0 && i+j < N){
                chess[y-j][i+j]++; /* 우상 대각 색칠 */
            }
            if(y-j >= 0 && i-j >= 0){
                chess[y-j][i-j]++; /* 좌상 대각 색칠 */
            }
        }

        dfs(chess, y+1);

        /* 백트래킹 */
        chess[y][i]--;
        for(int j = 0 ; j < N ; j++){
            if(j != i){
                chess[y][j]--; /* 가로 색칠 */
            }
            if(y != j){
                chess[j][i]--; /* 세로 색칠 */
            }
        }
        for(int j = 1 ; j < N ; j++){
            if(y+j < N && i+j < N){
                chess[y+j][i+j]--; /* 우하 대각 색칠 */
            }
            if(y+j < N && i-j >= 0){
                chess[y+j][i-j]--; /* 좌하 대각 색칠 */
            }
            if(y-j >= 0 && i+j < N){
                chess[y-j][i+j]--; /* 우상 대각 색칠 */
            }
            if(y-j >= 0 && i-j >= 0){
                chess[y-j][i-j]--; /* 좌상 대각 색칠 */
            }
        }

    }
    /* y+1 행에 놓을 퀸이 없다면 */
    return ;
}


int main(){
    scanf("%d",&N);
    
    int chess[15][15] = {0,};

    dfs(chess,0);
    
    printf("%d\n",sum);
}