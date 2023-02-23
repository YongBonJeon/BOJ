#include <bits/stdc++.h>
using namespace std;

int main(){
    int T,N,M;
    int A[1000001];
    int B[1000001];

    scanf("%d",&T);
    while(T > 0){
        scanf("%d",&N);
        for(int i = 0 ; i < N ; i++)
            scanf("%d",&A[i]);
        scanf("%d",&M);
        for(int i = 0 ; i < M ; i++)
            scanf("%d",&B[i]);
        
        sort(A,A+N);

        for(int i = 0 ; i < M ; i++){
            if(binary_search(A,A+N,B[i]))
                printf("1\n");
            else
                printf("0\n");
        }
        T--;
    }
}