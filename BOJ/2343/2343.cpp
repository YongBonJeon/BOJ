#include <bits/stdc++.h>
using namespace std;

int N,M,sum = 0;
int lecture[100001];

bool check(int val){
    int cnt = 1;
    int temp = val;
    for(int i = 0 ; i < N ; i++){
        if(lecture[i] > val)
            return false;
        
        if(temp - lecture[i] < 0){
            cnt++;
            temp = val;
        }
        temp -= lecture[i];        
    }

    return cnt <= M;
}

int main()
{
    scanf("%d %d",&N, &M);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&lecture[i]);
        sum += lecture[i];
    }

    int l = 1, r = sum,mid,ans = INT_MAX;
    while(l <= r){
        mid = (l+r)/2;

        if(check(mid)){
            r = mid-1;
            ans = min(ans,mid);
        }
        else
            l = mid+1;
    }
    printf("%d\n",ans);
}