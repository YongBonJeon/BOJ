#include <bits/stdc++.h>
using namespace std;

int N,L;
int m[101][101];
int install[101][101];

int road_row(int row)
{
    /* 항상 L개 만큼은 같은 높이 여야함 */
    /* 높이 차이는 항사 1이여야함 */
    /* */
    /* 탐색을 하다가 높이가 같으면 진행 
        높이가 1 다르면 L만큼 낮은 곳 탐색
        높이가 1 이상 다르면 끝 
    */
    int ins[101] = {0,};
    int prev = 0, cur = 1;
    while(prev != N-1)
    {
        //printf("%d %d\n",prev,cur);
        if(m[row][prev] == m[row][cur]){
            prev++; cur++;
        } 
        else if(abs(m[row][prev] - m[row][cur]) > 1)
            return 0;
        else if(m[row][prev] - m[row][cur] == 1)
        {
            for(int j = 0 ; j < L-1 ; j++)
            {
                if(ins[cur])
                    return 0;
                if(cur+1 < N && m[row][cur] == m[row][cur+1])
                {
                    ins[cur++] = 1;
                }
                else
                    return 0;
            }
            if(ins[cur])
                return 0;
            ins[cur]=1;
            prev = cur;
            cur++;
        }
        else if(m[row][cur] - m[row][prev] == 1)
        {
            for(int j = 0 ; j < L-1 ; j++)
            {
                if(ins[prev]){// printf("x\n");
                    return 0;}
                if(prev-1 >= 0 && m[row][prev] == m[row][prev-1])
                {   //printf("sibal");
                    ins[prev--] = 1;
                }
                else{ //printf("923\n");
                    return 0;
                }
            }
            if(ins[prev])
                return 0;
            ins[prev] = 1;
            prev = cur;
            cur++;
        }
    }
    //printf("row %d\n",row);
    return 1;
}

int road_col(int col)
{
    /* 항상 L개 만큼은 같은 높이 여야함 */
    /* 높이 차이는 항사 1이여야함 */
    /* */
    /* 탐색을 하다가 높이가 같으면 진행 
        높이가 1 다르면 L만큼 낮은 곳 탐색
        높이가 1 이상 다르면 끝 
    */
    int ins[101] = {0,};
    int prev = 0, cur = 1;
    while(prev != N-1)
    {
        //printf("%d %d\n",prev,cur);
        if(m[prev][col] == m[cur][col]){
            prev++; cur++;
        } 
        else if(abs(m[prev][col] - m[cur][col]) > 1)
            return 0;
        else if(m[prev][col] - m[cur][col] == 1)
        {
            for(int j = 0 ; j < L-1 ; j++)
            {
                if(ins[cur])
                    return 0;
                if(cur+1 < N && m[cur][col] == m[cur+1][col])
                {
                    ins[cur++] = 1;
                }
                else
                    return 0;
            }
            if(ins[cur])
                return 0;
            ins[cur] = 1;
            prev = cur;
            cur++;
        }
        else if(m[cur][col] - m[prev][col] == 1)
        {
            for(int j = 0 ; j < L-1 ; j++)
            {
                if(ins[prev]){ //printf("x\n");
                    return 0;}
                if(prev-1 >= 0 && m[prev][col] == m[prev-1][col])
                { //  printf("sibal");
                    ins[prev--] = 1;
                }
                else{ //printf("923\n");
                    return 0;
                }
            }
            if(ins[prev])
                return 0;
            ins[prev] = 1;
            prev = cur;
            cur++;
        }
    }
    //printf("col %d\n",col);
    return 1;
}

int main()
{
    scanf("%d %d",&N, &L);

    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            scanf("%d",&m[i][j]);

    int ans = 0;
    for(int i = 0 ; i < N ; i++)
        ans += road_row(i);
    for(int i = 0 ; i < N ; i++)
        ans += road_col(i);

    printf("%d\n",ans);
}