#include <bits/stdc++.h>
using namespace std;

int N;
pair<int,int> arr[1001];
int cnt[1001];

int main(){
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d %d",&arr[i].first,&arr[i].second);
    
    sort(arr,arr+N);

    int maxValue = 0,ret=0;
    for(int i = 0 ; i < N ; i++){
        maxValue = 0;
        for(int j = 0 ; j < i ; j++){
            if(arr[j].first < arr[i].first && arr[j].second < arr[i].second && maxValue < cnt[j])
                maxValue = cnt[j];
        }
        cnt[i] = maxValue + 1;
        ret = max(ret,cnt[i]);
    }
    /*for(int i = 0 ; i < N ; i++)
        printf("%d ",cnt[i]);
    printf("\n");*/
    printf("%d\n",N-ret);
}