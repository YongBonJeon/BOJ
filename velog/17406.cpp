#include <bits/stdc++.h>
using namespace std;

int N,M,K;

typedef struct r_
{
    int y;
    int x;
    int range;
}r;

vector<r> rot;
vector<int> num;

void go(vector<int> num, int m[51][51])
{
    int real[51][51];
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            real[i][j] = m[i][j];
    
    for(auto q : num)
    {
        int y = rot[q].y;
        int x = rot[q].x;
        int range = rot[q].range;

        for(int i = y-range ; i < range+1 ; i++)
        {
            for(int j = x-range ; j < range+1 ; j++)
            {
                real[i][j] = m[range-1-j][i];
            }
        }


    }
}

void solve(int m[51][51])
{
    do
    {
        go(num, m);
    } while (next_permutation(num.begin(), num.end()));
    
}


int main()
{
    int m[51][51];
    scanf("%d %d %d",&N,&M,&K);
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
    int y,x,range;
    for(int i = 0 ; i < K ; i++)
    {
        scanf("%d %d %d",&y, &x, &range);
        r cmd = {y,x,range};
        rot.push_back(cmd);
        num.push_back(i);
    }
}