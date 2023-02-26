#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    int seq[100001];
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&seq[i]);
    }
    pair<int,int> ans;
    int ret = INT_MAX;

    int l = 0, r = N-1;
    while(l < r){
        int sum = (seq[l]+seq[r]);

        if(abs(sum) < abs(ret)){
            ans.first = seq[l];
            ans.second = seq[r];
            ret = sum;
        }
        if(sum > 0){
            r--;
        }
        else if(sum < 0){
            l++;
        }
        else
            break;
    }
    printf("%d %d\n",ans.first,ans.second);
}