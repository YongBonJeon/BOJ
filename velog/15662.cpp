#include <bits/stdc++.h>
using namespace std;

int T,K;
int tooth[1001][8];
vector<pair<int,int>> cmd;

void rot(int num, int dir)
{
    int temp[8];
    for(int i = 0 ; i < 8 ; i++)
        temp[i] = tooth[num][i];
    /* 시계 방향 회전 */
    if(dir == 1)
    {
        for(int i = 0 ; i < 8 ; i++)
            tooth[num][i] = temp[(i+7)%8];
    }
    /* 반시계 방향 회전 */
    else
    {
        for(int i = 0 ; i < 8 ; i++)
            tooth[num][i] = temp[(i+1)%8];
    }
}

void game(int num, int dir)
{
    /* 우선 num 톱니바퀴를 dir 방향으로 회전 */
    int origin = dir;
    rot(num, origin);

    /* 우측 톱니바퀴 연쇄 회전 */
    int next_num = num+1;
    while(next_num != T+1 && tooth[next_num-1][2+dir] != tooth[next_num][6]){
        /* 상극일 경우 반대 방향으로 회전 */
        rot(next_num,-dir);
        next_num++;
        dir = -dir;
    }
    
    /* 좌측 톱니바퀴 연쇄 회전 */
    next_num = num-1;
    dir = origin;
    while(next_num != 0 && tooth[next_num+1][6+dir] != tooth[next_num][2]){
        rot(next_num,-dir);
        next_num--;
        dir = -dir;
    }
    
}

int order()
{
    for(auto go : cmd){
        int num = go.first;
        int dir = go.second;

        game(num,dir);
    }

    int cnt = 0;
    for(int i = 1 ; i <= T ; i++)
        if(tooth[i][0])
            cnt++;
    
    return cnt;
}

int main()
{
    scanf("%d",&T);
    for(int i = 1 ; i <= T ; i++)
        for(int j = 0 ; j < 8 ; j++)
            scanf("%1d",&tooth[i][j]);

    scanf("%d",&K);
    int num, dir;
    for(int i = 0 ; i < K ; i++){
        scanf("%d %d",&num, &dir);
        cmd.push_back({num, dir});
    }
    printf("%d\n",order());
}