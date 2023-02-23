#include <bits/stdc++.h>
using namespace std;

int N,M;
int cost[100001];

bool check(int val){
    int cnt = 1;
    int temp = val;
    for(int i = 0 ; i < N ; i++){
        if(cost[i] > val)
            return false;
        
        if(temp - cost[i] < 0){
            temp = val;
            cnt++;
        }
        temp -= cost[i];
    }

    return cnt <= M;
} 

int main()
{
    int sum = 0;
    scanf("%d %d",&N, &M);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&cost[i]);
        sum += cost[i];
    }

    int l = 1, r = sum, mid,ans = INT_MAX;
    while(l <= r){
        mid = (l+r)/2;

        if(check(mid)){
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%d\n",ans);
}