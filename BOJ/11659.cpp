#include <bits/stdc++.h>
using namespace std;

int N,M,temp_sum = 0;
int arr[100001];
int p_arr[1000001];

int main(){

    scanf("%d %d",&N, &M);

    for(int i = 0 ; i < N ; i++){
        scanf("%d",&arr[i]);
        temp_sum += arr[i];
        p_arr[i+1] = temp_sum;
    }

    int s,e;
    for(int i = 0 ; i < M ; i++){
        scanf("%d %d",&s, &e);
        printf("%d\n", p_arr[e] - p_arr[s-1]);
    }
}
