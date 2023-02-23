#include <bits/stdc++.h>
using namespace std;

int N, num;
int arr[1000001];
int cnt[1000001];

int main(){
    scanf("%d",&N);
    vector<int> lis;
    int ret_length = 0;
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&arr[i]);

        if(lis.empty()){
            lis.push_back(arr[i]);
            cnt[i]=1;
        }
        else{
            // 값이 크므로 증가 수열에 추가
            if(lis[lis.size()-1] < arr[i]){
                lis.push_back(arr[i]);
                cnt[i] = lis.size();
            }
            // 값이 작으므로 증가 수열 교체
            else{
                auto p = lower_bound(lis.begin(),lis.end(),arr[i]);
                *p = arr[i];
                cnt[i] = p-lis.begin()+1;
            }
        }
        ret_length = max(ret_length,cnt[i]);
    }
    /*for(int i = 0 ; i < N ; i++)
        printf("%d ",cnt[i]);*/
    
    stack<int> s;

    printf("%d\n",ret_length);
    for(int i = N-1 ; i >= 0 ; i--){
        if(ret_length == cnt[i]){
            s.push(arr[i]);
            ret_length--;
        }
    }
    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }
    printf("\n");
}
  