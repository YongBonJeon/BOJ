#include <bits/stdc++.h>
using namespace std;

int N, min_ = 10000;

int is_all_zero(int a, int b, int c)
{
    if(a <= 0 && b <= 0 && c <= 0)
        return true;
    return false;
}

void attack(int num, int a, int b, int c)
{
    printf("%d num %d %d %d\n",num, a,b,c);
    if(is_all_zero(a,b,c) || num > min_)
    {
        min_ = min(min_, num);
        return ;
    }

    attack(num+1, a-9, b-3, c-1);
    attack(num+1, a-9, b-1, c-3);
    attack(num+1, a-3, b-9, c-1);
    attack(num+1, a-3, b-1, c-9);
    attack(num+1, a-1, b-9, c-3);
    attack(num+1, a-1, b-3, c-9);
}

int main()
{
    scanf("%d",&N);
    
    vector<int> scv(N); 
    int temp;
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&temp);
        scv[i] = temp;
    }

    sort(scv.begin(), scv.end(), greater<int>());
    //printf("%d num %d %d %d\n",0, scv[0],scv[1],scv[2]);
    attack(0, scv[0], scv[1], scv[2]);

    printf("%d\n",min_);
}