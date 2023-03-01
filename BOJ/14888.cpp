#include <bits/stdc++.h>
using namespace std;

int N;
int arr[12];
int op[4];
int min_ = INT_MAX, max_ = INT_MIN;

void select(int num, int val)
{
   // printf("%d %d\n",num,val);
    if(num == N)
    {
        min_ = min(min_, val);
        max_ = max(max_, val);
        return ;
    }

    for(int i = 0 ; i < 4 ; i++)
    {
        if(op[i])
        {
            op[i]--;
            if(i == 0)
                select(num+1, val+arr[num]);
            else if(i == 1)
                select(num+1, val-arr[num]);
            else if(i == 2)
                select(num+1, val*arr[num]);
            else    
                select(num+1, val/arr[num]);
            op[i]++;
        }
    }
}

int main()
{
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&arr[i]);
    for(int i = 0 ; i < 4 ; i++)
        scanf("%d",&op[i]);

    select(1,arr[0]);

    printf("%d\n%d\n",max_,min_);
}