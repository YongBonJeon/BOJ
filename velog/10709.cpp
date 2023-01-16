#include <bits/stdc++.h>
using namespace std;

int H,W;
char m[101][101];
int ans[101][101];

void solve(int h)
{
    int st;
    for(int i = W-1 ; i >= 0 ; i--)
    {
        if(m[h][i] == 'c')
        {
            st = 1;

            while(m[h][i+st] != 'c' && i+st < W)
            {
                ans[h][i+st] = st;
                st++;
            }
        }
    }

}

int main()
{
    cin >> H >> W;

    for(int i = 0 ; i < H ; i++)
        for(int j = 0 ; j < W ; j++){
            cin >> m[i][j];
            if(m[i][j] == 'c')
                ans[i][j] = 0;
            else
                ans[i][j] = -1;
        }
    for(int i = 0 ; i < H ; i++)
        solve(i);

    for(int i = 0 ; i < H ; i++)
    {
        for(int j = 0 ; j < W ; j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }

    
}