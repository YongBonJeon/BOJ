#include <stdio.h>
#include <unistd.h>

int map[50][50] = {0,};
int cleaner;
int row, column;

void do_clean(){

    /* 확산 */
    int temp[50][50] = {0,};

    /* 확산 2방향 */
    temp[1][0] += map[0][0] / 5;
    temp[0][1] += map[0][0] / 5;
    map[0][0] -= 2*(map[0][0] / 5);
    temp[row-2][column-1] += map[row-1][column-1] / 5;
    temp[row-1][column-2] += map[row-1][column-1] / 5;
    map[row-1][column-1] -= 2*(map[row-1][column-1] / 5);
    temp[row-2][0] += map[row-1][0] / 5;
    temp[row-1][1] += map[row-1][0] / 5;
    map[row-1][0] -= 2*(map[row-1][0] / 5);
    temp[0][column-2] += map[0][column-1] / 5;
    temp[1][column-1] += map[0][column-1] / 5;
    map[0][column-1] -= 2*(map[0][column-1] / 5);

    /* 확산 3방향 */

    for(int j = 1 ; j < column-1 ; j++){
        temp[0][j-1] += map[0][j] / 5;
        temp[0][j+1] += map[0][j] / 5;
        temp[1][j] += map[0][j] / 5;
        map[0][j] -= 3*(map[0][j] / 5);
    }
    for(int i = 1 ; i < row-1 ; i++){
        if(i == cleaner+1){
            temp[i+1][0] += map[i][0] / 5;
            temp[i][1] += map[i][0] / 5;
            map[i][0] -= 2*(map[i][0] / 5);
            continue;
        }
        else if(i == cleaner-2){
            temp[i-1][0] += map[i][0] / 5;
            temp[i][1] += map[i][0] / 5;
            map[i][0] -= 2*(map[i][0] / 5);
            continue;
        }
        temp[i+1][0] += map[i][0] / 5;
        temp[i-1][0] += map[i][0] / 5;
        temp[i][1] += map[i][0] / 5;
        map[i][0] -= 3*(map[i][0] / 5);
    }
    for(int j = 1 ; j < column-1 ; j++){
        temp[row-1][j-1] += map[row-1][j] / 5;
        temp[row-1][j+1] += map[row-1][j] / 5;
        temp[row-2][j] += map[row-1][j] / 5;
        map[row-1][j] -= 3*(map[row-1][j] / 5);
    }
    for(int i = 1 ; i < row-1 ; i++){
        temp[i+1][column-1] += map[i][column-1] / 5;
        temp[i-1][column-1] += map[i][column-1] / 5;
        temp[i][column-2] += map[i][column-1] / 5;
        map[i][column-1] -= 3*(map[i][column-1] / 5);
    }

    /* 4방향 확산 */
    for(int i = 1 ; i < row-1 ; i++){
        for(int j = 1 ; j < column-1 ; j++){
            if(i == cleaner && j == 1){
               //printf("\n%d %d\n",i,j);
                temp[i][j+1] += map[i][j] / 5;
                temp[i+1][j] += map[i][j] / 5;
                temp[i-1][j] += map[i][j] / 5;
                map[i][j] -= 3*(map[i][j] / 5);
                continue;
            }
            else if(i == cleaner-1 && j == 1){
                temp[i][j+1] += map[i][j] / 5;
                temp[i+1][j] += map[i][j] / 5;
                temp[i-1][j] += map[i][j] / 5;
                map[i][j] -= 3*(map[i][j] / 5);
                continue;
            }
            temp[i][j-1] += map[i][j] / 5;
            temp[i][j+1] += map[i][j] / 5;
            temp[i+1][j] += map[i][j] / 5;
            temp[i-1][j] += map[i][j] / 5;
            map[i][j] -= 4*(map[i][j] / 5);
        }
    }
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < column ; j++){
            map[i][j] += temp[i][j];
        }
    }

    /*printf("확산\n");
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < column ; j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }*/

    int cur_row = cleaner;
    int cur_column = 0;

    if(cur_row == row-1){
        map[cur_row][1] = 0;
        cur_column = 1;
    }
    else{
        map[cur_row+1][0] = 0;
        cur_row += 1;
    }

    while(cur_row != cleaner || cur_column != 0){
        int next_row, next_column;

        if(cur_column == 0){
            next_row = cur_row + 1;
            next_column = cur_column;
        }
        if(cur_row == row-1){
            next_row = cur_row;
            next_column = cur_column + 1;
        }
        if(cur_column == column -1){
            next_row = cur_row - 1;
            next_column = cur_column;
        }
        if(cur_row == cleaner){
            next_row = cur_row;
            next_column = cur_column -1;
        }

        map[cur_row][cur_column] = map[next_row][next_column];

        cur_row = next_row;
        cur_column = next_column;
    }

    cur_row = cleaner -1;
    cur_column = 0;

    if(cur_row == 0){
        map[cur_row][1] = 0;
        cur_column = 1;
    }
    else{
        map[cur_row-1][0] = 0;
        cur_row -= 1;
    }

    while(cur_row != cleaner-1 || cur_column != 0){
        int next_row, next_column;

        if(cur_column == 0){
            next_row = cur_row - 1;
            next_column = cur_column;
        }
        if(cur_row == 0){
            next_row = cur_row;
            next_column = cur_column + 1;
        }
        if(cur_column == column -1){
            next_row = cur_row + 1;
            next_column = cur_column;
        }
        if(cur_row == cleaner-1){
            next_row = cur_row;
            next_column = cur_column -1;
        }

        map[cur_row][cur_column] = map[next_row][next_column];

        cur_row = next_row;
        cur_column = next_column;
    }

    /*printf("\n");
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < column ; j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }*/

    
}

int main(){
    int time;

    scanf("%d %d %d", &row, &column, &time);

    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < column ; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == -1){
                cleaner = i;
                map[i][j] = 0;
            }
        }
    }

    for(int i = 0 ; i < time ; i++){
        map[cleaner][0] = 0;
        map[cleaner-1][0] = 0;
        do_clean();
    }
    map[cleaner][0] = 0;
    map[cleaner-1][0] = 0;

    int sum = 0;
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < column ; j++){
            sum += map[i][j];
        }
    }
    printf("%d\n",sum);
}