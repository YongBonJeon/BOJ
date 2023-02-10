#include <bits/stdc++.h>
using namespace std;

int N,M,K;

vector<tuple<int,int,int>> cmd;
vector<int> num;
int min_ = INT_MAX;

void rot(int num, int m[51][51])
{
    int temp[51][51];

    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            temp[i][j] = m[i][j];

    int cy = get<0>(cmd[num]);
    int cx = get<1>(cmd[num]);
    int range = get<2>(cmd[num]);

    for(int r = 1 ; r <= range ; r++)
    {
        int ly = cy - r;
        int lx = cx - r;
        int ry = cy + r;
        int rx = cx + r;

        /* 윗변 */
        for(int i = lx ; i < rx ; i++)
            m[ly][i+1] = temp[ly][i];
        /* 왼변 */
        for(int i = ry ; i > ly ; i--)
            m[i-1][lx] = temp[i][lx];
        /* 아랫변 */
        for(int i = rx ; i > lx ; i--)
            m[ry][i-1] = temp[ry][i];
        /* 오른변*/
        for(int i = ly ; i < ry ; i++)
            m[i+1][rx] = temp[i][rx];
    }

}


void solve(int m[51][51])
{
    int temp[51][51];
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            temp[i][j] = m[i][j];
    do
    {
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < M ; j++)
                m[i][j] = temp[i][j];

        for(auto x : num){
            rot(x, m);
            /*for(int i = 0 ; i < N ; i++)
            {
                for(int j = 0 ; j < M ; j++)
                    printf("%d ",m[i][j]);
                printf("\n");
            }*/
        }
        int sum;
        for(int i = 0 ; i < N ; i++)
        {
            sum = 0;
            for(int j = 0 ; j < M ; j++)
            {
                sum += m[i][j];
            }
            min_ = min(min_,sum);
        }

    } while (next_permutation(num.begin(), num.end()));
    
}


int main()
{
    int m[51][51];
    scanf("%d %d %d",&N,&M,&K);
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            scanf("%d",&m[i][j]);

    int y,x,range;
    for(int i = 0 ; i < K ; i++)
    {
        scanf("%d %d %d",&y, &x, &range);
        cmd.push_back({y-1,x-1,range});
        num.push_back(i);
    }
    solve(m);
    printf("%d\n",min_);
}