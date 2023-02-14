#include <bits/stdc++.h>
using namespace std;

int N;
int min_ = 100000;

bool bit[21][21];

int cal();
void reverse_row(int);

void solve(int st)
{
    min_ = min(min_, cal());

    for(int row = st ; row < N ; row++){
        reverse_row(row);
        solve(row+1);
        reverse_row(row);
    }
}

void reverse_row(int row)
{
    for(int i = 0 ; i < N ; i++){
        if(bit[row][i])
            bit[row][i] = false;
        else
            bit[row][i] = true;
    }
}

void reverse_col(int col)
{
    for(int i = 0 ; i < N ; i++){
        if(bit[i][col])
            bit[i][col] = false;
        else
            bit[i][col] = true;
    }
}

int cal_col(int col)
{
    int ans = 0;

    for(int i = 0 ; i < N ; i++)
        if(bit[i][col])
            ans++;

    return ans;
}

int cal()
{   int ans = 0;

    for(int col = 0 ; col < N ; col++)
        ans += min(cal_col(col), N-cal_col(col));

    return ans;
}

int main()
{
    char m[21][21];

    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
        scanf("%s",m[i]);

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            // 앞면
            if(m[i][j] == 'H')
                bit[i][j] = true;
            // 뒷면
            else
                bit[i][j] = false;
        }
        
    }

    solve(0);

    printf("%d\n",min_);

}