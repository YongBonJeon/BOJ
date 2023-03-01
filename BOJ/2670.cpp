#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    double arr[10001];

    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lf",&arr[i]);
    }

    double temp = 1,ans = 0;
    for(int i = 0 ; i < N ; i++){
        temp *= arr[i];
        ans = max(temp,ans);
        if(temp < 1)
            temp = 1.0;
    }
    printf("%.3lf\n",ans);
}