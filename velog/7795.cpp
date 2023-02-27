#include <bits/stdc++.h>
using namespace std;

int T,N,M,t;

int main(){
    scanf("%d",&T);

    while(T > 0){
        scanf("%d %d",&N, &M);
        vector<int> A(N);
        vector<int> B(M);
        for(int i = 0 ; i < N ; i++){
            scanf("%d",&t); A[i] = t;}
        for(int i = 0 ; i < M ; i++){
            scanf("%d",&t); B[i] = t;}
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());

        int total = 0;

        for(int i = 0 ; i < N ; i++){
            auto pos = lower_bound(B.begin(),B.end(),A[i]);
            total += (int)(pos-B.begin());
        }

        printf("%d\n",total);
        T--;
    }
}