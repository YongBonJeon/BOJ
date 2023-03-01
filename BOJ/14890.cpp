#include <bits/stdc++.h>
using namespace std;

int N,L;
int m[101][101];
int install[101][101];

int road_row(int row)
{
    int ins[101] = {0,};    // 경사로 설치 
    int prev = 0, cur = 1;
    while(prev != N-1)
    {
        if(m[row][prev] == m[row][cur]){
            prev++; cur++;
        }
        // 높이의 차가 1 초과이면 경사로 설치 불가 
        else if(abs(m[row][prev] - m[row][cur]) > 1)
            return 0;
        // 경사로 설치 
        else if(m[row][prev] - m[row][cur] == 1)
        {
            for(int j = 0 ; j < L-1 ; j++)
            {
                // 이미 경사로가 설치되어 있으므로 불가
                if(ins[cur])
                    return 0;
                // 경사로가 설치되는 곳의 높이는 모두 같아야 함 
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
                if(ins[prev]){
                    return 0;}
                if(prev-1 >= 0 && m[row][prev] == m[row][prev-1])
                {   
                    ins[prev--] = 1;
                }
                else{ 
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
    return 1;
}

int road_col(int col)
{
    int ins[101] = {0,};
    int prev = 0, cur = 1;
    while(prev != N-1)
    {
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
                if(ins[prev]){ 
                    return 0;}
                if(prev-1 >= 0 && m[prev][col] == m[prev-1][col])
                {
                    ins[prev--] = 1;
                }
                else{ 
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