#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 51

enum destination {N,E,S,W};

int row,column;
int cur_row,cur_column,dest;
int num_sweep = 0, sweepflag;
int map[MAX][MAX];

void check_4direction(){
    sweepflag = 0;
    if(map[cur_column-1][cur_row] > 0){ // 북쪽 확인 
            sweepflag++;
        }
        if(map[cur_column+1][cur_row] > 0){ // 남쪽 확인 
            sweepflag++;
        }
        if(map[cur_column][cur_row-1] > 0){ // 서쪽 확인 
            sweepflag++;
        }
        if(map[cur_column][cur_row+1] > 0){ //동쪽 확인 
            sweepflag++;
        }
}

void sweep(){
    int next_row,next_column;
    while(1){
        //printf("cur_column cur_row %d %d\n",cur_column,cur_row);
        //sleep(1);
        if(map[cur_column][cur_row] == 0){ // 1번 : 현재 위치 청소
            map[cur_column][cur_row] = 2;
            num_sweep++;
        }
        /* 사방 확인 */
        check_4direction();

        //printf("sweepfloag %d\n",sweepflag);
        if(sweepflag == 4){ // 사방이 청소되어있거나 벽인 경우
            // 후진 방향 체크 
            switch(dest){ 
            case 0 : // 북쪽
                next_column = cur_column + 1; 
                next_row = cur_row;
                break;
            case 1 : // 동쪽
                next_column = cur_column; 
                next_row = cur_row - 1;
                break;
            case 2 : // 남쪽
                next_column = cur_column - 1; 
                next_row = cur_row;
                break;
            case 3 : // 서쪽
                next_column = cur_column; 
                next_row = cur_row + 1;
                break;
            }

            // 2-4번 : 뒤쪽 방향이 벽인 경우 
            if(map[next_column][next_row] == 1){
                break; // 작동 정지
            }

            // 2-3번 : 바라보는 방향 유지하며 후진
            cur_column = next_column;
            cur_row = next_row;
            continue;
        }

        dest--; // 왼쪽으로 방향 틀기
        if(dest<0){dest=3;}

        switch(dest){
            case 0 : // 북쪽
                next_column = cur_column - 1; 
                next_row = cur_row;
                break;
            case 1 : // 동쪽
                next_column = cur_column; 
                next_row = cur_row + 1;
                break;
            case 2 :  // 남쪽
                next_column = cur_column + 1; 
                next_row = cur_row;
                break;
            case 3 : // 서쪽
                next_column = cur_column; 
                next_row = cur_row - 1;
                break;
        }

        if(map[next_column][next_row] == 0){ // 2-1번
            cur_column = next_column;
            cur_row = next_row;
        }
    }
}

int main(){
    scanf("%d %d",&column,&row);
    scanf("%d %d %d",&cur_column,&cur_row,&dest);

    for(int i = 0 ; i < column ; i++){
        for(int j = 0 ; j < row ; j++){
            scanf("%d",&map[i][j]);
        }
    }

    sweep();

    printf("%d\n",num_sweep);
    

}