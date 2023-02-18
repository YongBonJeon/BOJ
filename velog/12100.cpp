#include <bits/stdc++.h>
using namespace std;

int N,max_block = 0;

void move(int num, int m[21][21])
{
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++){
            max_block = max(max_block, m[i][j]);
        }

    if(num == 5)
        return ;

    int temp[21][21];

    /* <- */
    for(int dir = 0 ; dir < 4 ; dir++)
    {
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < N ; j++)
                temp[i][j] = m[i][j];

        /* <- */
        if(dir == 0)
        {
            for(int i = 0 ; i < N ; i++)
            { 
                bool crash[21] = {0,};
                for(int j = 1 ; j < N ; j++)
                {
                    int move_idx = j;
                    if(temp[i][move_idx] == 0)
                        continue;
                    /* 0 pass*/
                    while(move_idx > 0 && temp[i][move_idx-1] == 0)
                        move_idx--;
                    /* 끝으로 이동*/
                    if(move_idx == 0)
                    {
                        temp[i][0] = temp[i][j];
                        temp[i][j] = 0;
                    }
                    /* 합침*/
                    else if(!crash[move_idx-1] && temp[i][move_idx-1] == temp[i][j] )
                    {
                        temp[i][move_idx-1] *=2;
                        temp[i][j] = 0;
                        crash[move_idx-1] = true;
                    }
                    else if(crash[move_idx-1] && temp[i][move_idx-1] == temp[i][j] )
                    {
                        temp[i][move_idx] = temp[i][j];
                        temp[i][j] = 0;
                    }
                    /* 단순 이동 */
                    else if(temp[i][move_idx-1] != temp[i][j] && move_idx != j)
                    {
                        temp[i][move_idx] = temp[i][j];
                        temp[i][j] = 0;
                    }
                    
                }
            }
        }
        // -> 
        if(dir == 1)
        {
            for(int i = 0 ; i < N ; i++)
            {
                bool crash[21] = {0,};
                for(int j = N-2 ; j >= 0 ; j--)
                {
                    int move_idx = j;
                    if(temp[i][move_idx] == 0)
                        continue;
                    /* 0 pass*/
                    while(move_idx < N-1 && temp[i][move_idx+1] == 0)
                        move_idx++;
                    //printf("move %d %d %d\n",i,j,move_idx);
                    /* 끝으로 이동*/
                    if(move_idx == N-1)
                    {
                        temp[i][move_idx] = temp[i][j];
                        temp[i][j] = 0;
                    }
                    /* 합침*/
                    else if(!crash[move_idx+1] && temp[i][move_idx+1] == temp[i][j])
                    {
                        temp[i][move_idx+1] *=2;
                        temp[i][j] = 0;
                        crash[move_idx+1] = true;
                    }
                    else if(crash[move_idx+1] && temp[i][move_idx+1] == temp[i][j])
                    {
                        temp[i][move_idx] = temp[i][j];
                        temp[i][j] = 0;
                    }
                    /* 단순 이동 */
                    else if(temp[i][move_idx+1] != temp[i][j] && move_idx != j){
                        temp[i][move_idx] = temp[i][j];
                        temp[i][j] = 0;
                    }
                }
            }
        }
        /* ^ */
        else if(dir == 2)
        {
            for(int i = 0 ; i < N ; i++)
            { 
                bool crash[21] = {0,};
                for(int j = 1 ; j < N ; j++)
                {
                    int move_idx = j;
                    if(temp[move_idx][i] == 0)
                        continue;
                    /* 0 pass*/
                    while(move_idx > 0 && temp[move_idx-1][i] == 0)
                        move_idx--;
                    /* 끝으로 이동*/
                    if(move_idx == 0){
                        temp[0][i] = temp[j][i];
                        temp[j][i] = 0;
                    }
                    /* 합침*/
                    else if(!crash[move_idx-1] && temp[move_idx-1][i] == temp[j][i]){
                        temp[move_idx-1][i] *=2;
                        temp[j][i] = 0;
                        crash[move_idx-1] = true;
                    }
                    else if(crash[move_idx-1] && temp[move_idx-1][i] == temp[j][i]){
                        temp[move_idx][i] = temp[j][i];
                        temp[j][i] = 0;
                    }
                    /* 단순 이동 */
                    else if(temp[move_idx-1][i] != temp[j][i] && move_idx != j){
                        temp[move_idx][i] = temp[j][i];
                        temp[j][i] = 0;
                    }
                }
            }
        }
        /* v */
        else if(dir == 3)
        {
            for(int i = 0 ; i < N ; i++)
            { 
                bool crash[21] = {0,};
                for(int j = N-2 ; j >= 0 ; j--)
                {
                    int move_idx = j;
                    if(temp[move_idx][i] == 0)
                        continue;
                    /* 0 pass*/
                    while(move_idx < N-1 && temp[move_idx+1][i] == 0)
                        move_idx++;
                    /* 끝으로 이동*/
                    if(move_idx == N-1){
                        temp[N-1][i] = temp[j][i];
                        temp[j][i] = 0;
                    }
                    /* 합침*/
                    else if(!crash[move_idx+1] && temp[move_idx+1][i] == temp[j][i]){
                        temp[move_idx+1][i] *=2;
                        temp[j][i] = 0;
                        crash[move_idx+1] = true;
                    }
                    else if(crash[move_idx+1] && temp[move_idx+1][i] == temp[j][i]){
                        temp[move_idx][i] = temp[j][i];
                        temp[j][i] = 0;
                    }
                    /* 단순 이동 */
                    else if(temp[move_idx+1][i] != temp[j][i] && move_idx != j){
                        temp[move_idx][i] = temp[j][i];
                        temp[j][i] = 0;
                    }
                }
            }
        }

        move(num+1, temp);
    }

}

int main()
{
    int board[21][21];

    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            scanf("%d",&board[i][j]);
        }
    }
    move(0,board);
    printf("%d\n",max_block);

}