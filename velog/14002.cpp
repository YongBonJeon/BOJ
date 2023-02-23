#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1001];
int cnt[1001];

int main(){
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&arr[i]);

    int maxValue = 0,ret=0;
    for(int i = 0 ; i < N ; i++){
        maxValue = 0;
        for(int j = 0 ; j < i ; j++){
            if(arr[j] < arr[i] && maxValue < cnt[j])
                maxValue = cnt[j];
        }
        cnt[i] = maxValue +1;
        ret = max(ret,cnt[i]);
    }
    printf("%d\n",ret);
    int t = ret;
    vector<int> ans;
    for(int i = N-1 ; i >= 0 ; i--){
        if(cnt[i] == t){
            ans.push_back(i);
            t--;
        }
    }
    for(int i = ans.size()-1 ; i >= 0 ; i--){
        printf("%d ",arr[ans[i]]);
    }
    printf("\n");
}